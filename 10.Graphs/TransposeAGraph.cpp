/* Amit Bansal - @amitbansal7 */
// Representing a Graph
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
// Transpose a graph in O(V+E)

void TraverseGraph(vector <int>adj[])
{
	vector <int>::iterator it;
	for(int v=1;v<=5;v++)
	{
		printf("\n %d ->",v);
		for(it = adj[v].begin();it != adj[v].end();it++)
			printf("%d ",*it);
	}
	printf("\n");
}

void Transpose(vector <int> adj[],vector <int>adjT[])
{
	vector <int>::iterator it;
	for(int i=1;i<=6;i++)
		for(it = adj[i].begin();it != adj[i].end();it++)
			adjT[*it].push_back(i);
}

int main()
{
	int ver = 6;
	vector <int> adj[ver+1];
	adj[1].push_back(2);
	adj[1].push_back(4);

	adj[2].push_back(5);

	adj[3].push_back(6);
	adj[3].push_back(5);

	adj[4].push_back(2);

	adj[5].push_back(4);

	adj[6].push_back(6);

	vector <int> :: iterator it;
	TraverseGraph(adj);
	vector <int> adjT[ver+1];//Transposed Graph
	printf("After Transpose\n");
	Transpose(adj,adjT);
	TraverseGraph(adjT);
}