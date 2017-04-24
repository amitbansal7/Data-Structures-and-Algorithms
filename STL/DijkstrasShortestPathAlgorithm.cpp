/* Amit Bansal - amitbansal7 */
#include <bits/stdc++.h>
#define lli long long int
#define llu unsigned long long int
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define Mset(p,i) memset(p,i,sizeof(p))
#define mlc(t,n) (t *)malloc(sizeof(t)*n)
#define NIL -1
#define INF 0x3f3f3f3f
template <typename T>
T Max(T x, T y){x>y?x:y;}
using namespace std;

void printpath(int parent[],int v)
{
	if(parent[v] == v)
		return;

	printpath(parent,parent[v]);
	printf("%d->",parent[v]);
}

void addEdge(vector<pair<int,int> >adj[], int src,int dest, int w)
{
	adj[src].push_back(make_pair(dest,w));
	adj[dest].push_back(make_pair(src,w));
}

void Dijkstra(vector <pair<int, int> >adj[],int src,int v)
{
	priority_queue< pair<int, int>, vector<pair<int,int> >,greater<pair<int, int> > > pq;

	vector<int >dist(v,INF);
	int parent[v];
	parent[src] = src;

	pq.push(make_pair(0,src));
	dist[src] = 0;

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		vector <pair<int,int> >::iterator it;

		for(it = adj[u].begin(); it != adj[u].end(); it++)
		{
			int v = (*it).first;
			int w = (*it).second;

			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u]+w;
				pq.push(make_pair(dist[v],v));
				parent[v] = u;
			}
		}
	}

	printf("Vertex   distance from  %d       Path\n",src);
	for(int i=0;i<v;i++)
	{
		printf("%d \t\t%d  \t\t",i,dist[i]);
		printpath(parent,i);
		printf("%d \n",i);
	}
}

int main(int argc, char const *argv[])
{
	int v = 9;
	vector <pair <int, int> >adj[v];

	addEdge(adj,0, 1, 4);
    addEdge(adj,0, 7, 8);
    addEdge(adj,1, 2, 8);
    addEdge(adj,1, 7, 11);
    addEdge(adj,2, 3, 7);
    addEdge(adj,2, 8, 2);
    addEdge(adj,2, 5, 4);
    addEdge(adj,3, 4, 9);
    addEdge(adj,3, 5, 14);
    addEdge(adj,4, 5, 10);
    addEdge(adj,5, 6, 2);
    addEdge(adj,6, 7, 1);
    addEdge(adj,6, 8, 6);
    addEdge(adj,7, 8, 7);
	
	Dijkstra(adj,1,v);
	return 0;
}