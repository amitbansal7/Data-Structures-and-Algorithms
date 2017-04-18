#include <stdio.h>
#include <stdlib.h>
#define NIL -1

int max(int a, int b){ return (a>b)?a:b; }

// With dynamic programming Top Down.

int K[3+1][50+1];

int knapsackUtil(int v[],int w[], int c,int n)
{
	if(K[n][c] != NIL)
		return K[n][c];

	else
	{
		int a;

		if(n==0 || c ==0)
			a = 0;

		else if(w[n-1] > c)
			a = knapsackUtil(v,w,c,n-1);

		else
			a = max(v[n-1] + knapsackUtil(v,w,c-w[n-1],n-1), knapsackUtil(v,w,c,n-1));

		K[n][c] = a;

	}

	return K[n][c];
}

int knapsack(int v[], int w[], int c, int n)
{

	for(int i=0;i<=n;i++)
		for(int j=0;j<=c;j++)
			K[i][j] = NIL;

	return knapsackUtil(v,w,c,n);

}

int main()
{
	int v[] = {60, 100, 120};
	int w[] = {10, 20, 30};
	int c = 50;
	printf("Max value %d \n",knapsack(v,w,c,sizeof(v)/sizeof(v[0])));
	
	return 0;
}