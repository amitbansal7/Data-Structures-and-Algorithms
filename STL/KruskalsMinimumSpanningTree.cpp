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

struct DJSet
{
	int n;
	int *parent;
	int *rank;	
};

struct DJSet* createDJSets(int n)
{
	struct DJSet *sets = mlc(struct DJSet,1);

	sets->n = n;
	sets->parent = mlc(int, n+1);
	sets->rank = mlc(int, n+1);

	for(int i=0;i<=n;i++)
	{
		sets->parent[i] = i;
		sets->rank[i] = 0;
	}

	return sets;
}

int find(struct DJSet* sets, int u)
{
	if(u!= sets->parent[u])
		sets->parent[u] = find(sets,sets->parent[u]);

	return sets->parent[u];
}

void merge(struct DJSet* sets,int u,int v)
{
	int x = find(sets,u);
	int y = find(sets,v);

	if(sets->rank[x] > sets->rank[y])
		sets->parent[y] = x;

	else
		sets->parent[x] = y;

	if(sets->rank[x] == sets->rank[y])
		sets->rank[y]++;
}

int KruskalsMST(vector <pair<int ,pair<int, int> > >edges,int n)
{
	int Mwt = 0;

	sort(edges.begin(),edges.end());
	struct DJSet* ds = createDJSets(n);

	vector <pair<int ,pair<int ,int > > >::iterator it;

	for(it=edges.begin();it != edges.end();it++)
	{
		int u = (*it).second.first;
		int v = (*it).second.second;

		int su = find(ds,u);
		int sv = find(ds,v);

		if(su!=sv)
		{
			printf("%d - %d\n",u,v);
			Mwt += (*it).first;

			merge(ds,su,sv);
		}
	}
	return Mwt;
}

int main(int argc, char const *argv[])
{
	int v = 9;

	vector <pair<int ,pair<int ,int> > > edges;

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

	printf("\nMinimum weight - %d",KruskalsMST(edges,v));

	return 0;
}