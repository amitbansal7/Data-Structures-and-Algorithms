#include <stdio.h>
#include <stdlib.h>
#define NIL -1

int max(int a, int b){ return (a>b)?a:b; }

int knapsack(int v[],int w[], int c,int n)
{
		if(n==0 || c ==0)
			return 0;

		else if(w[n-1] > c)
			return knapsack(v,w,c,n-1);

		else
			return max(v[n-1] + knapsack(v,w,c-w[n-1],n-1), knapsack(v,w,c,n-1));
}

int main()
{
	int v[] = {60, 100, 120};
	int w[] = {10, 20, 30};
	int c = 50;
	printf("Max value %d \n",knapsack(v,w,c,sizeof(v)/sizeof(v[0])));
	
	return 0;
}