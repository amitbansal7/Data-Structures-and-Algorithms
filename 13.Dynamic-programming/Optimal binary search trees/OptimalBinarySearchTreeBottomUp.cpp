#include <bits/stdc++.h>
using namespace std;

int Fsum(int freq[],int i,int j)
{
	int sm = 0;

	for(int k = i;k<=j;k++)
		sm += freq[k];

	return sm;
}

int OBST(int freq[], int n)
{
	int Cost[n+1][n+1];

	for(int i=0;i<n;i++)
		Cost[i][i] = freq[i];

	for(int L=2;L<=n;L++)
	{
		for(int i=0;i<=n-L+1;i++)
		{
			int j = i+L-1;
			Cost[i][j] = INT_MAX;

			for(int r = i;r<=j;r++)
				Cost[i][j] = min(Cost[i][j],
					Fsum(freq,i,j)+
					((r>i)?Cost[i][r-1]:0)+
					((r<j)?Cost[r+1][j]:0));
		}
	}

	return Cost[0][n-1];
}

int main()
{
	int freq[] = {4,2,6,3};

	int n = sizeof(freq)/sizeof(freq[0]);

	printf("%d \n",OBST(freq,n));

	return 0;
}
