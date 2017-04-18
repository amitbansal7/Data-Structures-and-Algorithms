#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

struct AdjListNode
{
	int dest;
	int weight;
	struct AdjListNode* next;
};

struct AdjList
{
	struct AdjListNode* head;
};

struct Graph
{
	int v;
	struct AdjList *array;
};

struct AdjListNode* newAdjListNode(int dest, int weight)
{
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int v)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->v = v;

	graph->array = (struct AdjList*)malloc(sizeof(struct AdjList)*v);

	for(int i=0;i<v;i++)
		graph->array[i].head = NULL;

	return graph;
}

void AddEdge(struct Graph* graph,int src, int dest, int weight)
{
	struct AdjListNode* newNode = newAdjListNode(dest,weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = newAdjListNode(src,weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

struct MinHeapNode
{
	int v;
	int dist;
};

struct MinHeap
{
	int size;
	int capacity;
	int *pos;
	struct MinHeapNode **array;
};

struct MinHeapNode* newMinHeapNode(int v, int dist)
{
	struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;	
}

struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->pos = (int *)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode**)malloc(sizeof(struct MinHeapNode*)*capacity);

	return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* temp = *a;
	*a = *b;
	*b = temp;
}

void MinHeapify(struct MinHeap* minHeap, int i)
{
	int l = 2*i + 1;
	int r = 2*i + 2;

	int smallest = i;

	if(l < minHeap->size && minHeap->array[l]->dist <  minHeap->array[smallest]->dist)
		smallest = l;

	if(r < minHeap->size && minHeap->array[r]->dist < minHeap->array[smallest]->dist)
		smallest = r;

	if(smallest!=i)
	{
		struct MinHeapNode* smallestnode = minHeap->array[smallest];
		struct MinHeapNode* iNode = minHeap->array[i];

		minHeap->pos[smallestnode->v] = i;
		minHeap->pos[iNode->v] = smallest;

		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[i]);
		MinHeapify(minHeap, smallest);
	}
}

int isEmpty(struct MinHeap* heap)
{
	return heap->size == 0;
}

void decreaseKey(struct MinHeap* minHeap, int v, int dist)
{
	int i = minHeap->pos[v];

	minHeap->array[i]->dist = dist;

	while(i && minHeap->array[i]->dist < minHeap->array[(i-1)/2]->dist)
	{
		minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
		minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i-1)/2]);

		i = (i-1)/2;
	}
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
	if(isEmpty(minHeap))
		return NULL;

	struct MinHeapNode* root = minHeap->array[0];

	struct MinHeapNode* lastNode = minHeap->array[minHeap->size-1];
	minHeap->array[0] = lastNode;

	minHeap->pos[root->v] = minHeap->size-1;
	minHeap->pos[lastNode->v] = 0;

	--minHeap->size;
	MinHeapify(minHeap,0);

	return root;
}

int isInMinHeap(struct MinHeap* minHeap, int v)
{
	if(minHeap->pos[v] < minHeap->size)
		return 1;

	else
		return 0;
}

void printpath(int parent[], int v)
{
	if(parent[v]==v)
		return;
	printpath(parent,parent[v]);
	printf("%d->",parent[v]);
}

void printarr(int dist[], int n,int parent[])
{
	printf("Vertex   distance from Source   Path\n");
	for(int i=0; i<n ;i++)
	{
		printf("%d \t\t%d   \t\t",i,dist[i]);
		printpath(parent,i);
		printf("%d\n",i);
	}
}

void dijkstra(struct Graph* graph, int src)
{
	int V = graph->v;
	struct MinHeap* minHeap = createMinHeap(V);
	int dist[V];
	minHeap->size = V;
	int parent[V];
	parent[src] = src;

	for(int v=0;v<V;v++)
	{
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v,INT_MAX);
		minHeap->pos[v] = v;
	}

	dist[src] = 0;
	decreaseKey(minHeap,src,dist[src]);

	while(!isEmpty(minHeap))
	{
		struct MinHeapNode* minNode = extractMin(minHeap);
		int u = minNode->v;

		for(struct AdjListNode* crawl = graph->array[u].head; crawl; crawl = crawl->next)
		{
			int v = crawl->dest;

			if(isInMinHeap(minHeap,v) && dist[u]!=INT_MAX && dist[u]+crawl->weight < dist[v])
			{
				dist[v] = crawl->weight + dist[u];
				parent[v] = u;
				decreaseKey(minHeap,v,dist[v]);
			}
		}
	}
	printarr(dist,V,parent);
}
int main()
{
	int V = 9;

	struct Graph* graph = createGraph(V);

	AddEdge(graph, 0, 1, 4);
	AddEdge(graph, 0, 7, 8);
	AddEdge(graph, 1, 2, 8);
	AddEdge(graph, 1, 7, 11);
	AddEdge(graph, 2, 3, 7);
	AddEdge(graph, 2, 8, 2);
	AddEdge(graph, 2, 5, 4);
	AddEdge(graph, 3, 4, 9);
	AddEdge(graph, 3, 5, 14);
	AddEdge(graph, 4, 5, 10);
	AddEdge(graph, 5, 6, 2);
	AddEdge(graph, 6, 7, 1);
	AddEdge(graph, 6, 8, 6);
	AddEdge(graph, 7, 8, 7);
	
	dijkstra(graph,1);

	/*
	Output

	Vertex   distance from Source   Path
	0 		4   		1->0
	1 		0   		1
	2 		8   		1->2
	3 		15   		1->2->3
	4 		22   		1->2->5->4
	5 		12   		1->2->5
	6 		12   		1->7->6
	7 		11   		1->7
	8 		10   		1->2->8

	*/
	return 0;
}
