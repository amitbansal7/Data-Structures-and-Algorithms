/* Amit Bansal - @amitbansal7 */
//References GeeksForGeeks
#include <bits/stdc++.h>
#include <string>
#define lli long long int
#define llu unsigned long long int
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define Mset(p,i) memset(p,i,sizeof(p))
#define mlc(t,n) (t *)malloc(sizeof(t)*n)
#define NIL -1
#define INF INT_MAX
#define TC int testcase; S(testcase); while(testcase--)
#define Pi 3.14159
using namespace std;

const int V = 6;

bool BFS(int graph[V][V],int s,int t,int parent[])
{
	queue <int>Q;
	int visited[V];
	Mset(visited,0);
	visited[s] = 1;
	Q.push(s);
	parent[s] = NIL;

	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		for(int v=0;v<V;v++)
		{
			if(!visited[v] && graph[u][v] > 0)
			{
				Q.push(v);
				parent[v] = u;
				visited[v] = 1;
			}
		}
	}
	return(visited[t]);
}

int FordFulkerson(int graph[V][V],int s,int t)
{
	//residual graph
	int rGraph[V][V];
	memcpy(rGraph,graph,sizeof(int)*V*V);

	int maxflow = 0;
	int parent[V];

	while(BFS(rGraph,s,t,parent))
	{
		int u,v;
		int path_flow = INT_MAX;
		//finding minimum residual capacity along the augmented path.
		for(int v = t;v!=s;v = parent[v])
		{
			u = parent[v];
			path_flow = min(path_flow,rGraph[u][v]);
		}

		for(v = t;v!=s;v=parent[v])
		{
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		maxflow += path_flow;
	}

	return maxflow;
}

int main()
{
	//CLRS fig 26.1(a)
	int graph[V][V] = {{0,16,12,0,0,0},
					{0,0,0,12,0,0},
					{0,4,0,0,14,0},
					{0,0,9,0,0,20},
					{0,0,0,7,0,4},
					{0,0,0,0,0,0}};

	printf("Max flow is %d\n",FordFulkerson(graph,0,5));

	return 0;
}
