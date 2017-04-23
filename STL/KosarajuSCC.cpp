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

void fillOrder(vector<int > adj[],int s,bool visited[],stack <int >&S)
{
	visited[s] = true;

	vector<int >::iterator it;

	for(it = adj[s].begin();it != adj[s].end();it++)
		if(!visited[*it])
			fillOrder(adj,*it,visited,S);

	S.push(s);
}
void DFS(vector<int > adj[],int s,bool visited[])
{
	visited[s] = true;
	printf("%d ",s);

	vector<int >::iterator it;
	for(it = adj[s].begin(); it!=adj[s].end(); it++)
		if(!visited[*it])
			DFS(adj,*it,visited);
}

void kosarajuSCC(vector<int > adj[],int n)
{
	bool visited[n];
	Mset(visited,0);

	stack <int > S;

	for(int i=0;i<n;i++)
		if(!visited[i])
			fillOrder(adj,i,visited,S);


	Mset(visited,0);

	// Tranposing a graph
	vector<int > Radj[n];
	vector<int >::iterator it;
	for(int i=0;i<n;i++)
		for(it = adj[i].begin(); it!= adj[i].end();it++)
			Radj[*it].push_back(i);

	while(!S.empty())
	{
		int v = S.top();
		S.pop();

		if(!visited[v])
		{
			DFS(Radj,v,visited);
			printf("\n");
		}
	}
}

int main(int argc, char const *argv[])
{
	int v = 5;

	vector<int > adj[v];

	adj[1].push_back(0);
	adj[0].push_back(2);
	adj[2].push_back(1);
	adj[0].push_back(3);
	adj[3].push_back(4);

	printf("Strongly Connected components are : \n");
	kosarajuSCC(adj,v);

	return 0;
}