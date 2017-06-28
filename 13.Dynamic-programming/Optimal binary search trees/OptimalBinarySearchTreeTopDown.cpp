#include <bits/stdc++.h>
using namespace std;

int Cost[4][4];

int Fsum(int freq[],int i,int j)
{
	int sm = 0;

	for(int k = i;k<=j;k++)
		sm += freq[k];

	return sm;
}

int OBST(int freq[], int i,int j)
{
	if(Cost[i][j] != -1)
		return Cost[i][j];

	if(j < i)
		return Cost[i][j] = 0;

	if(i==j)
		return Cost[i][j] = freq[i];

	int fsum = Fsum(freq,i,j);

	Cost[i][j] = INT_MAX;

	for(int r = i;r<=j;r++)
		Cost[i][j] = min(Cost[i][j], OBST(freq,i,r-1) + OBST(freq,r+1,j));

	Cost[i][j] += fsum;

	return Cost[i][j];

}

int main()
{
	int freq[] = {4,2,6,3};
	int n = sizeof(freq)/sizeof(freq[0]);

	memset(Cost,-1,sizeof(Cost));

	printf("%d\n",OBST(freq,0,n-1));

	return 0;
}
