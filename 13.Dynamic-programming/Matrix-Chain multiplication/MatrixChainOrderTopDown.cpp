#include <bits/stdc++.h>
using namespace std;
const int n = 5;
int DP[n][n];
int s[n][n];

void PrintOptimalParens(int i,int j)
{
	if(i == j)
		printf("A%d",i);
	else
	{
		printf("(");
		PrintOptimalParens(i,s[i][j]);
		PrintOptimalParens(s[i][j]+1,j);
		printf(")");
	}
}

int MCM(int p[],int i,int j)
{
	if(i == j)
		return DP[i][j] = 0;

	int q;
	DP[i][j] = INT_MAX;

	for(int k = i;k<j;k++)
	{
		q = MCM(p,i,k) + MCM(p,k+1,j) + p[i-1]*p[k]*p[j];
		if(q < DP[i][j])
		{
			DP[i][j] = q;
			s[i][j] = k;
		}
	}

	return DP[i][j] = q;

}

int main()
{
	int p[] = {2,3,6,4,5};
	memset(DP,-1,sizeof(DP));

	printf("Minimum multiplications required : %d\n",MCM(p,1,n-1));

	printf("\n");

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",DP[i][j]);

		printf("\n");
	}

	printf("Optimal Parenthesization  is :");
	PrintOptimalParens(1,n-1);
	printf("\n");

}
