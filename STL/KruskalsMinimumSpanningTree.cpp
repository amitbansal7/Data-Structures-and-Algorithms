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

struct DisjointSet
{
	int v;
	int *parent;
	int *rank;
};

struct DisjointSet* CreateSet(int v)
{
	struct DisjointSet* Set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
	Set->v = v;
	Set->parent = (int *)malloc(sizeof(int)*v);
	Set->rank = (int *)malloc(sizeof(int)*v);

	for(int i=0;i<v;i++)
	{
		Set->parent[i] = i;
		Set->rank[i] = 0;
	}
	return Set;
}

int find(int u,struct DisjointSet* Set)
{
	if(u != Set->parent[u])
		Set->parent[u] =  find(Set->parent[u],Set);

	return Set->parent[u];
}

void merge(int x,int y,struct DisjointSet* Set)
{
	if(Set->rank[x] > Set->rank[y])
		Set->parent[y] = x;
	else
		Set->parent[x] = y;

	if(Set->rank[x] == Set->rank[y])
		Set->rank[y]++;
}

int KruskalMST(vector <pair<int ,pair<int, int> > >  edges, int v)
{
	int Minwt = 0;
	sort(edges.begin(),edges.end());
	struct DisjointSet* Set = CreateSet(v);

	vector<pair<int,pair<int,int> > > ::iterator it;

	for(it = edges.begin();it != edges.end();it++)
	{
		int u = (*it).second.first;
		int v = (*it).second.second;

		int su = find(u,Set);
		int sv = find(v,Set);

		if(su!=sv)
		{
			Minwt += (*it).first;
			printf("%d - %d\n",u,v);
			merge(su,sv,Set);
		}
	}
	return Minwt;
}

int main()
{
	int v = 9;
	vector <pair<int,pair<int,int> > > edges;

	edges.push_back(make_pair(4,make_pair(0,1)));
	edges.push_back(make_pair(8,make_pair(0,7)));
	edges.push_back(make_pair(8,make_pair(1,2)));
	edges.push_back(make_pair(11,make_pair(1,7)));
	edges.push_back(make_pair(7,make_pair(2,3)));
	edges.push_back(make_pair(2,make_pair(2,8)));
	edges.push_back(make_pair(4,make_pair(2,5)));
	edges.push_back(make_pair(9,make_pair(3,4)));
	edges.push_back(make_pair(14,make_pair(3,5)));
	edges.push_back(make_pair(10,make_pair(4,5)));
	edges.push_back(make_pair(2,make_pair(5,6)));
	edges.push_back(make_pair(1,make_pair(6,7)));
	edges.push_back(make_pair(6,make_pair(6,8)));
	edges.push_back(make_pair(7,make_pair(7,8)));

	printf("Minimum wieght of MST is %d\n",KruskalMST(edges,v));
}
