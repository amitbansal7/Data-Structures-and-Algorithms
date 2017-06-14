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

void updateQuery(int STree[],int low,int high,int pos,int val,int v)
{
	if(low == high)
	{
		STree[pos] = val;
		return;
	}
	int mid = (low+high) >> 1;

	if(v <= mid)
		updateQuery(STree,low,mid,pos*2+1,val,v);
	else
		updateQuery(STree,mid+1,high,pos*2+2,val,v);

	STree[pos] = STree[2*pos+1] + STree[2*pos+2];
}

int RangeSumQuery(int STree[],int qlow,int qhigh,int low,int high,int pos)
{
	if(low >= qlow && high <= qhigh)
		return STree[pos];

	if(low > qhigh || high < qlow)
		return 0;

	int mid = (low+high) >> 1;
	return RangeSumQuery(STree,qlow,qhigh,low,mid,pos*2+1) +
			   RangeSumQuery(STree,qlow,qhigh,mid+1,high,pos*2+2);

}
void BulidTree(int A[],int STree[],int low,int high,int pos)
{
	if(low == high)
	{
		STree[pos] = A[low];
		return;
	}

	int mid = (low+high) >> 1;
	BulidTree(A,STree,low,mid,pos*2+1);
	BulidTree(A,STree,mid+1,high,pos*2+2);
	STree[pos] = STree[pos*2+1] + STree[pos*2+2];

}

int main()
{
	int A[] = {1,4,3,5};

	int n = sizeof(A)/sizeof(A[0]);
	int h = (int)(ceil(log2(n)));
	int size = 2*(int)pow(2,h)-1;

	int *STree  = mlc(int,size);

	BulidTree(A,STree,0,n-1,0);

	printf("%d\n",RangeSumQuery(STree,1,2,0,n-1,0));

	updateQuery(STree,0,n-1,0,8,2);
	// new array 1,4,8,5

	printf("%d\n",RangeSumQuery(STree,1,2,0,n-1,0));

	return 0;
}
