#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Bottom-up approach with memoization.

int max(int a,int b){ return a>b?a:b;}

int BottomUpCutRod(int p[],int n)
{
	int memo[n+1];
	memo[0] = 0;

	for(int j=1;j<=n;j++)
	{
		int q = INT_MIN;
		for(int i=0;i<j;i++)
			q = max(q, p[i]+memo[j-i-1]);

		memo[j] = q;
	}

	return memo[n];
}

int main()
{
	int p[10] = {1,5,8,9,10,17,17,20,24,30};

	printf("%d\n",BottomUpCutRod(p,10));

	return 0;
}
