/* Amit Bansal - amitbansal7 */
#include <bits/stdc++.h>
#define lli long long int
#define llu unsigned long long int
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define Mset(p,i) memset(p,i,sizeof(p))
#define mlc(t,n) (t *)malloc(sizeof(t)*n)
#define NIL -1
template <typename T>
T Max(T x, T y){x>y?x:y;}
using namespace std;

void BFS(vector <int >adj[],int s,int n)
{
	bool visited[n];
	Mset(visited,0);
	visited[s] = 1;
	queue <int >Q;
	Q.push(s);

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		printf("%d ",v);

		vector <int >::iterator it;
		for(it = adj[v].begin(); it !=  adj[v].end(); it++)
			if(!visited[*it])
			{
				visited[*it] = 1;
				Q.push(*it);
			}
	}
}

void addEdge(vector <int > adj[],int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

int main(int argc, char const *argv[])
{
	int v = 5;

	vector<int > adj[v];

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);

	BFS(adj,0,v);

	return 0;
}
