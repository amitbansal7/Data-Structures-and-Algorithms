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
#define INF INT_MAX
#define TC int testcase; S(testcase); while(testcase--)
#define Pi 3.14159
using namespace std;

const int v = 4;

void PrintAllPairShortestPath(int P[][v],int i,int j)
{
	if(i == j)
		printf("%d ",i);
	else if(P[i][j] == NIL)
		printf("No path exist\n");
	else
	{
		PrintAllPairShortestPath(P,i,P[i][j]);
		printf("%d ",j);
	}
}

void FloydWorshall(int W[][v],int P[][v])
{
	int D[v][v];
	memcpy(D,W,v*v*sizeof(int));

	for(int k=0;k<v;k++)
		for(int i=0;i<v;i++)
			for(int j=0;j<v;j++)
				if(D[i][k] != INF && D[k][j] != INF && D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[k][j];
				}

	printf("Shortest Distance Matrix\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			printf("%2d ",D[i][j]);
		printf("\n");
	}

	printf("\nPaths\nFrom \tTo \tpath\n");
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
		{
			printf("%d \t%d \t ",i,j);
			PrintAllPairShortestPath(P,i,j);
			printf("\n");
		}
}

int main(int argc, char const *argv[])
{
	/* W(weight) denotes edges by vertices
		0 denotes distance from i to i is 0
		inf denotes no edge
	*/
	int W[v][v] = {{0,3,6,15},
				{INF,0,-2,INF},
				{INF,INF,0,2},
				{1,INF,INF,0}};
	//P denotes Path.. Pij denotes parent of j ie i
	// -1 represent no path
	int P[v][v] = {{-1,0,0,0},
				{-1,-1,1,-1},
				{-1,-1,-1,2},
				{3,-1,-1,-1}};

	FloydWorshall(W,P);

	return 0;
}
