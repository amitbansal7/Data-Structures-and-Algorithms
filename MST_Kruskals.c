#include <stdio.h>
#include <stdlib.h>
//Reference GFG and NPTEL
//Kruskal’s Minimum Spanning Tree Algorithm

struct Edge
{
	int src, dest, weight;
};
struct Graph
{
	int v,e;
	struct Edge* edge;
};

struct subset
{
	int parent;
	int rank;
};

//Path compression
int find(struct subset subsets[],int i)
{
	if(subsets[i].parent!=i)
		subsets[i].parent = find(subsets,subsets[i].parent);

	return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets,x);
	int yroot = find(subsets,y);

	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;

	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}

}

int scompare(const void *a, const void *b)
{
	// Compare function for qsort()
	struct Edge* na = (struct Edge*)a;
	struct Edge* nb = (struct Edge*)b;

	return na->weight > nb->weight;
}

struct Graph* creategraph(int v,int e)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->v = v;
	graph->e = e;
	graph->edge = (struct Edge*)malloc(sizeof(struct Edge)*e);

	return graph;
}

void MST_kruskal(struct Graph* graph)
{
	int v = graph->v;
	struct Edge result[v];

	int e = 0;
	int i = 0;

	// Sort edges according to their weight/length using library function
	// qsort()- Quick Sort ~ O(mlogm).

	qsort(graph->edge,graph->e,sizeof(graph->edge[0]),scompare);

	struct subset *subsets = (struct subset*)malloc(sizeof(struct subset)*v);

	for(i=0; i<v;i++)
	{
		// initializing all subsets containing only one element.
		// and having rank 0 ie. only one node.
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
	i = 0;
	
	// As in a minimum spanning tree no of edged are n-1.
	while(e < v-1)
	{
		struct Edge crawl = graph->edge[i++];
		//checking every edge. 

		int x = find(subsets,crawl.src);
		int y = find(subsets,crawl.dest);

		if(x!=y)// Avoid cycles.
		{
			result[e++] = crawl;// adding edge to MST.
			Union(subsets, x, y);
		}
	}

	printf("Following edges are there in MST \n");
	printf("src--dest=weight\n");
	for(i=0; i<e; i++)
		printf("%d--%d=%d\n",result[i].src,result[i].dest,result[i].weight);
}

int main()
{
	int v = 4,e=5;
	struct Graph* graph = creategraph(v,e);

	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;

	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;

	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;

	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 15;

	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;

	MST_kruskal(graph);

	return 0;
}
