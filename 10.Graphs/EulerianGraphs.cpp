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
//Check if undirected Graph is eulerian.

void BFS(vector <int>adj[],int s,int v,int visited[])
{
	queue <int> Q;
	visited[s] = 1;
	Q.push(s);

	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		vector <int> ::iterator it;
		for(it = adj[u].begin();it != adj[u].end();it++)
			if(!visited[*it])
			{
				visited[*it] = 1;
				Q.push(*it);
			}
	}
}

int check(vector <int> adj[],int v)
{
	int visited[v];
	Mset(visited,0);
	int odd = 0;

	BFS(adj,0,v,visited);

	for(int i=1;i<v;i++)
		if(!visited[i])
			return 0;

	for(int i=0;i<v;i++)
		if(adj[i].size() &1)
			odd++;

	if(odd > 2)
		return 0;

	return 1;
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

	addEdge(adj, 1, 0);
	addEdge(adj, 0, 3);
	addEdge(adj, 2, 1);
	addEdge(adj, 0, 3);
	addEdge(adj, 3, 4);
	addEdge(adj, 4, 0);
	
	if(check(adj,v))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}