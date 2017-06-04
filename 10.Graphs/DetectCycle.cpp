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
//Detect a cycle using DFS

int DFS(vector <int>adj[],int s,int visited[],int reStack[])
{
	visited[s] = 1;
	reStack[s] = 1;
	vector<int> ::iterator it;
	for(it = adj[s].begin();it != adj[s].end();it++)
		if(!visited[*it])
		{
			if(DFS(adj,*it,visited,reStack))
				return true;
		}
		else if(reStack[*it] == 1)
			return true;

	reStack[s] = false;
	return false;
}

int DetectCycle(vector <int>adj[],int v)
{
	int visited[v];
	Mset(visited,0);
	int reStack[v];
	Mset(reStack,0);

	for(int i=1;i<v;i++)
		if(!visited[i] && DFS(adj,i,visited,reStack))
			return 1;

	return 0;
}

int main(int argc, char const *argv[])
{
	int v = 4;

	vector<int > adj[v];
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(3);
	// Cycle detected

	/*
	adj[1].push_back(4);
	adj[2].push_back(4);
	adj[2].push_back(3);
	adj[3].push_back(4);
	adj[3].push_back(7);
	adj[6].push_back(8);
	adj[6].push_back(7);
	adj[7].push_back(9);
	adj[8].push_back(9);
	// No cycle found (for above case)
	*/

	if(DetectCycle(adj,v))
		printf("Cycle Detected \n");
	else
		printf("No Cycle found\n");

	return 0;
}