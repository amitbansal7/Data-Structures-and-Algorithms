#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Top-down approach with memoization.
// Not working.

int max(int a,int b){ return a>b?a:b;}

int utilMemoizedCutRod(int p[], int n, int memo[])
{
	if(memo[n] >= 0)
		return memo[n];
	int q;
	
	if(n==0)
		q = 0;

	else
	{
		q = INT_MIN;

		for(int i=0;i<n;i++)
			q = max(q, p[i]+utilMemoizedCutRod(p,n-i-1,memo));
	}
	memo[n] = q;

	return q;
}

int MemoizedCutRod(int p[], int n)
{
	int memo[n];

	for(int i=0;i<n;i++)
		memo[i] = INT_MIN;

	return utilMemoizedCutRod(p, n, memo);
}

int main()
{
	int p[10] = {1,5,8,9,10,17,17,20,24,30};

	printf("%d\n",MemoizedCutRod(p,5));

	return 0;
}
