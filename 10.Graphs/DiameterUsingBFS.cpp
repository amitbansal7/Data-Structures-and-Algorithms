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
//Find diameter using BFS

void BFS(vector <int>adj[],int s,int v,int dis[])
{
	bool visited[v];
	Mset(visited,0);
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

				dis[*it] = dis[u] +1;
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
	int v = 8;

	vector<int > adj[v];

	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 2, 4);
	addEdge(adj, 2, 5);
	addEdge(adj, 4, 6);
	addEdge(adj, 5, 7);
	
	int maxdis = INT_MIN;
	int lc;
	int dis[v];
	Mset(dis,0);
	BFS(adj,1,v,dis);
	for(int i=1;i<v;i++)
		if(maxdis < dis[i])
		{
			lc = i;
			maxdis = dis[i];
		}
	Mset(dis,0);
	BFS(adj,lc,v,dis);
	for(int i=1;i<v;i++)
		if(maxdis < dis[i])
		{
			lc = i;
			maxdis = dis[i];
		}
	printf("%d\n",maxdis);

	return 0;
}