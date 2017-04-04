#include <stdio.h>
#include "stdlib.h"
//Depth First Search
struct Graph
{
	int v;
	struct AdjList* array;
};

struct AdjList
{
	struct  AdjListNode* head;
};

struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};

void DFSutil(struct Graph* graph,int v,int visited[])
{
	visited[v] = 1;
	printf("%d ",v);

	struct AdjListNode* crawl;

	for(crawl=graph->array[v].head; crawl!=NULL; crawl = crawl->next)
	{
		if(!visited[crawl->dest])
			DFSutil(graph,crawl->dest,visited);
	}
}

void DFS(struct Graph* graph,int v)
{
	int *visited = (int *)malloc(sizeof(int)*graph->v);
	int i;
	for(i=0;i<graph->v;i++)
		visited[i] = 0;

	DFSutil(graph,v,visited);
}

struct Graph* Creategraph(int v)
{
	int i;
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->v = v;
	graph->array = (struct AdjList*)malloc(sizeof(struct AdjList)*v);

	for(i=0;i<v;i++)
		graph->array[i].head = NULL;

	return graph;
}

struct AdjListNode* createAdjListNode(int dest)
{
	struct AdjListNode* new = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	new->dest = dest;
	new->next = NULL;

	return new;
}

void addEdge(struct Graph* graph,int src,int dest)
{
	struct AdjListNode* newnode = createAdjListNode(dest);
	newnode->next = graph->array[src].head;
	graph->array[src].head = newnode;

	newnode = createAdjListNode(src);
	newnode->next = graph->array[dest].head;
	graph->array[dest].head = newnode;
}

int main()
{
	struct Graph* graph = Creategraph(5);

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	printf("Depth First Traversal staring from 0\n");
	DFS(graph,0);

	return 0;
}