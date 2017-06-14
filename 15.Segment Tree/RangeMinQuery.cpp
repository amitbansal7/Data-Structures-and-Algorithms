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

void UpdateQuery(int STree[],int low,int high,int pos,int newv,int v)
{
	if(low == high)
	{
		STree[pos] = newv;
		return;
	}

	int mid = (low+high) >> 1;
	if(v <= mid)
		UpdateQuery(STree,low,mid,2*pos+1,newv,v);

	else
		UpdateQuery(STree,mid+1,high,2*pos+2,newv,v);

	STree[pos] = min(STree[pos*2+1],STree[pos*2+2]);
}

int RangeMinQuery(int STree[],int qlow,int qhigh,int low,int high,int pos)
{
	if(qlow <= low && qhigh >= high)
		return STree[pos];

	if(qlow > high || qhigh < low)
		return INT_MAX;

	int mid = (low+high)>>1;

	return min(RangeMinQuery(STree,qlow,qhigh,low,mid,2*pos+1),
			   RangeMinQuery(STree,qlow,qhigh,mid+1,high,2*pos+2));
}

void BulidTree(int A[],int STree[],int low,int high,int pos)
{
	if(low == high)
	{
		STree[pos] = A[low];
		return;
	}
	int mid = (low+high) >> 1;
	BulidTree(A,STree,low,mid,2*pos+1);
	BulidTree(A,STree,mid+1,high,2*pos+2);
	STree[pos] = min(STree[2*pos+1],STree[2*pos+2]);
}

int main()
{

	int A[] = {-1,2,4,0};

	int n = sizeof(A)/sizeof(A[0]);
	int h = (int)(ceil(log2(n)));
	int size = 2*(int)pow(2,h)-1;

	int *STree  = mlc(int,size);

	BulidTree(A,STree,0,n-1,0);

	printf("%d\n",RangeMinQuery(STree,1,3,0,n-1,0));

	UpdateQuery(STree,0,n-1,0,-3,1);
	// new array -1,-3,4,0

	printf("%d\n",RangeMinQuery(STree,1,3,0,n-1,0));




	return 0;
}
