#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){ return (a>b)?a:b; }

int knapsack(int v[],int w[], int c,int n)
{
	int K[n+1][c+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=c;j++)
		{
			if(i==0 || j==0)
				K[i][j] = 0;

			else if(w[i-1] > j)
				K[i][j] = K[i-1][j];

			else
				K[i][j] = max(v[i-1] + K[i-1][j-w[i-1]], K[i-1][j]);
		}
	}

	return K[n][c];
}

int main()
{
	int v[] = {60, 100, 120};
	int w[] = {10, 20, 30};
	int c = 50;
	printf("Max value %d \n",knapsack(v,w,c,sizeof(v)/sizeof(v[0])));
	
	return 0;
}