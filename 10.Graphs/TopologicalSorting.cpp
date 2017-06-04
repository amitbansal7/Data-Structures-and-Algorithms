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

void tsort(vector<int >adj[],int s,bool visited[],stack<int>&S)
{
	visited[s] = 1;

	vector <int >::iterator it;
	for(it = adj[s].begin(); it != adj[s].end(); it++)
		if(!visited[*it])
			tsort(adj,*it,visited,S);

	S.push(s);
}
void TopologicalSort(vector<int >adj[],int n)
{
	bool visited[n];
	Mset(visited,0);

	stack <int >S;
	for(int i=0;i<n;i++)
		if(!visited[i])
			tsort(adj,i,visited,S);

	while(!S.empty())
	{
		printf("%d ",S.top());
		S.pop();
	}
}

int main()
{
	int v = 6;
	vector <int > adj[v];

	adj[5].push_back(2);
	adj[5].push_back(0);
	adj[4].push_back(0);
	adj[4].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(1);

	TopologicalSort(adj,v);

	return 0;
}