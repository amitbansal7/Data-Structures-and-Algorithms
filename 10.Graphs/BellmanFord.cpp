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

void printpath(int parent[],int v)
{
	if(parent[v] == v)
		return;
	printpath(parent,parent[v]);

	printf("%d ",v);
}
int BellmanFord(vector<pair<int,pair<int,int> > >adj,int v,int s)
{
	int dist[v];
	int parent[v];
	bool cycle = false;
	for(int i=0;i<v;i++)
	{
		parent[i] = NIL;
		dist[i] = INT_MAX;
	}
	dist[s] = 0;
	parent[s] = s;
	vector <pair<int,pair<int,int > > >::iterator it;
	for(int i=0;i<v-1;i++)
	{
		for(it = adj.begin();it != adj.end();it++)
		{
			int u = (*it).first;
			int v = (*it).second.first;
			int w = (*it).second.second;

			if(dist[u] != INT_MAX && dist[v] >  dist[u] + w)
			{
				dist[v] = dist[u] + w;
				parent[v] = u;
			}
		}
	}
	for(it = adj.begin();it != adj.end();it++)
	{
		int u = (*it).first;
		int v = (*it).second.first;
		int w = (*it).second.second;

		if(dist[u] != INT_MAX && dist[v] >  dist[u] + w)
		{
			cycle  = true;
			break;
		}
	}

	if(cycle == true)
	{
		for(int i=0;i<v;i++)
		{
			printf("For %d\n",i);
			printf("Parent is %d\n",parent[i]);
			printf("Distance from %d is %d\n",s,dist[i]);
			printf("\n");
		}

	}
	else
	for(int i=0;i<v;i++)
	{
		printf("Distance from %d to %d is %d route ",s,i,dist[i]);
		printpath(parent,i);
		printf("\n");
	}

	return cycle;
}
int main()
{
	int v=5;

	vector <pair<int,pair<int,int> > > adj;

	adj.push_back(make_pair(0,make_pair(3,8)));
	adj.push_back(make_pair(3,make_pair(4,2)));
	adj.push_back(make_pair(4,make_pair(3,1)));
	adj.push_back(make_pair(2,make_pair(4,4)));
	adj.push_back(make_pair(0,make_pair(2,5)));
	adj.push_back(make_pair(0,make_pair(1,4)));
	adj.push_back(make_pair(1,make_pair(2,-3)));

	printf("\t\tExample 1 \n");
  	if(BellmanFord(adj,v,0))
  		printf("Negative edge cycle found\n");

  	else
  		printf("Negative edge cycle not found\n");

  	printf("\n\t\tExample 2 \n");

  	vector <pair<int,pair<int,int> > > adj2;
  	v = 4;
  	adj2.push_back(make_pair(0,make_pair(1,1)));
  	adj2.push_back(make_pair(1,make_pair(2,3)));
  	adj2.push_back(make_pair(2,make_pair(3,2)));
  	adj2.push_back(make_pair(3,make_pair(1,-6)));

  	if(BellmanFord(adj2,v,0))
  		printf("Negative edge cycle found\n");

  	else
  		printf("Negative edge cycle not found\n");

    return 0;
}
