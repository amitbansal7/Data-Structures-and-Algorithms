#include <bits/stdc++.h>

int min(int a,int b) {return a<b?a:b;};
const int n = 5;
int DP[n][n];
int S[n][n];

void PrintOptimalParens(int i,int j)
{
	if(i == j)
		printf("A%d",i);

	else
	{
		printf("(");
		PrintOptimalParens(i,S[i][j]);
		PrintOptimalParens(S[i][j]+1,j);
		printf(")");
	}

}

int MatrixChainMultiplication(int p[],int n)
{
	memset(DP,-1,sizeof(DP));
	for(int i=0;i<n;i++)
		DP[i][i] = 0;

	int q;
	for(int l = 2;l<n;l++)
	{
		for(int i=1;i<n-l+1;i++)
		{
			int j = l+i-1;
			DP[i][j] = INT_MAX;
			for(int k=i;k<j;k++)
			{
				q = DP[i][k] + DP[k+1][j] + p[i-1]*p[k]*p[j];
				if(q < DP[i][j])
				{
					DP[i][j] = q;
					S[i][j] = k;
				}
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%4d ",DP[i][j]);

		printf("\n");
	}

	PrintOptimalParens(1,n-1);
	printf("\n");

	return DP[1][n-1];
}

int main()
{
	int p[] = {2,3,6,4,5};
	printf("Minimum multiplications required : %d\n",MatrixChainMultiplication(p,n));


	return 0;
}
