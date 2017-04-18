#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NIL -1

//Top-down approach with memoization.

int max(int a,int b){ return a>b?a:b;}

int utilMemoizedCutRod(int p[], int n, int memo[])
{
	if(memo[n] != NIL)
		return memo[n];
	int q;
	
	if(n==0)
		q = 0;

	else
	{
		q = NIL;

		for(int i=0;i<n;i++)
			q = max(q, p[i] + utilMemoizedCutRod(p,n-i-1,memo));
	}

	memo[n] = q;
	
	return q;
}

int MemoizedCutRod(int p[], int n)
{
	int memo[n+1];

	for(int i=0;i<=n;i++)
		memo[i] = NIL;

	return utilMemoizedCutRod(p, n, memo);
}

int main()
{
	int p[10] = {1,5,8,9,10,17,17,20,24,30};

	printf("%d\n",MemoizedCutRod(p,7));

	return 0;
}
