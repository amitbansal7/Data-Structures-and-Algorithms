/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
#include <string>
#define lli long long int
#define llu unsigned long long int
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define Mset(p,i) memset(p,i,sizeof(p))
#define mlc(t,n) (t *)malloc(sizeof(t)*n)
#define NIL -1
#define INF 0x3f3f3f3f
#define TC int testcase; S(testcase); while(testcase--)
#define Pi 3.14159
using namespace std;
// Check if graph is Bipartite using BFS

enum colors {BLUE,RED};

bool BFSBipartite(vector <int>adj[],int s,int v)
{
	bool visited[v];
	Mset(visited,0);
	queue <int> Q;
	visited[s] = 1;
	Q.push(s);
	int color[v];
	Mset(color,-1);
	color[s] = 1;

	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		vector <int> ::iterator it;
		for(it = adj[u].begin();it != adj[u].end();it++)
			if(!visited[*it] && color[*it] == NIL)
			{
				visited[*it] = 1;
				Q.push(*it);

				if(color[u])
					color[*it] = 0;
				else
					color[*it] = 1;
			}

			else if(color[u] == color[*it])
				return false;
	}

	return true;
}

void addEdge(vector <int > adj[],int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

int main(int argc, char const *argv[])
{
	int v = 6;

	vector<int > adj[v];

	addEdge(adj, 0, 3);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 5);
	addEdge(adj, 2, 4);
	addEdge(adj, 2, 5);

	
	BFSBipartite(adj,0,v) ?cout<<"yes\n" :cout<<"No\n";

	return 0;
}