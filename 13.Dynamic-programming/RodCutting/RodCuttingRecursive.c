#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Without dynamic programming , takes exponential time.
int max(int a, int b)
{
	return a>b?a:b;
}

int CutRod(int p[],int n)
{
	if(n==0)
		return 0;

	int q = INT_MIN;

	for(int i=0;i<n;i++)
		q = max(q, p[i] + CutRod(p,n-i-1));

	return q;
}

int main()
{
	int p[10] = {1,5,8,9,10,17,17,20,24,30};

	printf("%d\n",CutRod(p,9));

	return 0;
}
