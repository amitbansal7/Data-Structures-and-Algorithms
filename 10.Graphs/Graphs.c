#include <stdio.h>
#include <stdlib.h>
//adjacency list representation of graph
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

void printGraph(struct Graph* graph)
{
	int v;
	for(v=0; v < graph->v;v++)
	{
		struct AdjListNode* crawl = graph->array[v].head;
		printf("Adjacency list of vertex %d\nhead",v);
		while(crawl)
		{
			printf("-> %d",crawl->dest);
			crawl = crawl->next;
		}
		printf("\n");
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

	printGraph(graph);
	return 0;
}