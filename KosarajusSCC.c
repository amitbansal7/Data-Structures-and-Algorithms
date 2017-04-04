#include <stdio.h>
#include <stdlib.h>

//Kosaraju's algorithm for strongly connected components.
struct Graph
{
	int v;
	struct AdjList *array;
};

struct AdjList
{
	struct edge* head;
};

struct edge
{
	int dest;
	struct edge* next;
};

struct Stack
{
	int data;
	struct Stack* next;
};

struct Stack* stack = NULL;

int top()
{
	if(stack == NULL)
		return -1;

	return stack->data;
}

void pop()
{
	if(stack==NULL)
		return;

	struct Stack* node = stack;
	stack = stack->next;

	free(node);
}

int isEmpty()
{
	if(stack==NULL)
		return 1;

	else
		return 0;
}

void push(int data)
{
	struct Stack* node = (struct Stack*)malloc(sizeof(struct Stack));
	node->data = data;
	node->next = stack;

	stack = node;
}

struct Graph* createGraph(int v)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)*v);

	graph->v = v;
	graph->array = (struct AdjList*)malloc(sizeof(struct AdjList)*v);

	for(int i=0; i<graph->v;i++)
		graph->array[i].head = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
	struct edge* newedge = (struct edge*)malloc(sizeof(struct edge));
	newedge->dest = dest;

	newedge->next = graph->array[src].head;
	graph->array[src].head = newedge;
}

struct Graph* Transpose(struct Graph* graph)
{
	struct Graph* tgraph = createGraph(graph->v);

	for(int i=0; i< graph->v ;i++)
	{
		struct edge* crawl = NULL;

		for(crawl = graph->array[i].head; crawl; crawl = crawl->next)
		{
			struct edge* newedge = (struct edge*)malloc(sizeof(struct edge));
			newedge->dest = i;
			newedge->next = tgraph->array[crawl->dest].head;
			tgraph->array[crawl->dest].head = newedge;
		}
	}
	return tgraph;
}

void DFSutil(struct Graph* graph,int v,int visited[])
{
	visited[v] = 1;
	printf("%d ",v);

	struct edge* crawl = NULL;

	for(crawl = graph->array[v].head; crawl; crawl = crawl->next)
		if(!visited[crawl->dest])
			DFSutil(graph,crawl->dest,visited);
}

void fillOrder(struct Graph* graph, int v, int visisted[])
{
	visisted[v] = 1;

	struct edge* crawl = NULL;

	for(crawl = graph->array[v].head; crawl; crawl = crawl->next)
		if(!visisted[crawl->dest])
			fillOrder(graph,crawl->dest,visisted);

	push(v);
}

void printSCC(struct Graph* graph)
{
	stack = NULL;
	int i;

	int *visisted = (int *)malloc(sizeof(int)*graph->v);

	for(i=0; i<graph->v; i++)
		visisted[i] = 0;

	for(i=0 ;i<graph->v; i++)
		if(!visisted[i])
			fillOrder(graph, i, visisted);

	struct Graph* revgraph = Transpose(graph);

	for(i=0; i<graph->v; i++)
		visisted[i] = 0;

	while(!isEmpty())
	{
		int v = top();
		pop();

		if(!visisted[v])
		{
			DFSutil(revgraph,v,visisted);
			printf("\n");
		}
		
	}
}

int main(int argc, char const *argv[])
{
	int v = 5;
	struct Graph* graph = createGraph(v);

	addEdge(graph,1, 0);
    addEdge(graph,0, 2);
    addEdge(graph,2, 1);
    addEdge(graph,0, 3);
    addEdge(graph,3, 4);

    printf("Following are the strongly connected components \n");
    printSCC(graph);
	
	return 0;
}