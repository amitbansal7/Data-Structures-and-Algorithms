#include <stdio.h>
#include <stdlib.h>
//Breadth First Search
struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};

struct Queue
{
	int data;
	struct Queue* next;
};
struct Queue *front,*rear = NULL;

struct AdjList
{
	struct AdjListNode *head;
};

struct Graph
{
	int v;
	struct AdjList* array;
	
};

int pfront()
{
	if(front==NULL)
		return NULL;

	return front->data;
}

int isempty()
{
	if(front==NULL)
		return 1;

	else
		return 0;
}

void dequeue()
{
	if(isempty())
		return;

	struct Queue* temp = front;
	front = front->next;

	free(temp);
}

void enqueue(int data)
{
	struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
	temp->data = data;
	temp->next =NULL;

	if(isempty())
	{
		front = rear = temp;
	}

	else
	{
		rear->next = temp;
		rear = temp;
	}
}

struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode* new = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	new->dest = dest;
	new->next = NULL;

	return new;
}

struct Graph* createGrpah(int v)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->v = v;
	graph->array = (struct AdjList*)malloc(sizeof(struct AdjList)*v);

	int i;
	for(i=0;i<v;i++)
		graph->array[i].head = NULL;

	return graph;

}

void addEdge(struct Graph* graph, int src, int dest)
{
	struct AdjListNode* newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

void BFS(struct Graph* graph,int s)//Breadth First Traversal
{
	int i;
	struct AdjListNode* crawl;
	int *visited = (int *)malloc(sizeof(int)*graph->v);

	for(i=0;i<graph->v;i++)
		visited[i] = 0;

	visited[s] = 1;
	enqueue(s);

	while(!isempty())
	{

		s = pfront();
		printf("%d ",s);
		dequeue();

		for(crawl=graph->array[s].head;crawl;crawl = crawl->next)
		{
			if(!visited[crawl->dest])
			{
				visited[crawl->dest] = 1;
				enqueue(crawl->dest);
			}
		}
	}
}

int main()
{
	int v=5;

	struct Graph* graph = createGrpah(v);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	printf("\nBreadth First Traversal starting from 0 \n");
	BFS(graph,0);
	
	return 0;
}