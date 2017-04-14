#include <stdio.h>
#include <stdlib.h>

// Topological sorting
// reference GFG and nptel

struct Stack
{
	int data;
	struct Stack* next;
};

struct Stack* stop = NULL;// top of stack

struct Graph
{
	int v;
	struct AdjList* array;
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

int isempty()
{
	if(stop==NULL)
		return 1;
	else
		return 0;
}

void push(int data)
{
	struct Stack* newnode = (struct Stack*)malloc(sizeof(struct Stack));
	newnode->data = data;
	newnode->next = stop;
	stop = newnode;
}

void pop()
{
	if(stop==NULL)
		return;

	struct Stack* node = stop;
	stop = stop->next;
	free(node);
}

int top()
{
	return stop->data;
}

struct Graph* createGraph(int v)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->v = v;
	graph->array = (struct AdjList*)malloc(sizeof(struct AdjList)*v);

	for(int i=0; i<v; i++)
		graph->array[i].head = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
	struct edge* newnode = (struct edge*)malloc(sizeof(struct edge));
	newnode->dest = dest;

	newnode->next = graph->array[src].head;
	graph->array[src].head = newnode;
}

void tSortutil(struct Graph* graph, int v, int visited[])
{
	visited[v] = 1;

	struct edge* crawl =NULL;
	for(crawl = graph->array[v].head; crawl; crawl = crawl->next)
	{
		if(!visited[crawl->dest])
			tSortutil(graph, crawl->dest, visited);
	}

	push(v);
}

void TopologicalSort(struct Graph* graph)
{
	stop = NULL; // creating a stack
	int *visited = (int *)malloc(sizeof(int)*graph->v);

	for(int i=0; i<graph->v; i++)
		visited[i] = 0;

	for(int i=0; i<graph->v; i++)
	{
		if(visited[i] == 0)
			tSortutil(graph,i,visited);
	}

	while(!isempty())
	{
		printf("%d ",top());
		pop();
	}
}

int main()
{
	struct Graph* graph = createGraph(6);

	addEdge(graph,5, 2);
    addEdge(graph,5, 0);
    addEdge(graph,4, 0);
    addEdge(graph,4, 1);
    addEdge(graph,2, 3);
    addEdge(graph,3, 1);

    printf("Topological Sort for given graph is: ");

    TopologicalSort(graph);
	return 0;
}