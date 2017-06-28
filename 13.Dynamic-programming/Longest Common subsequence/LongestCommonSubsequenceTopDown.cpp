#include <bits/stdc++.h>
using namespace std;

int DP[10][10];

int lcs(int i,int j,string x, string y)
{
	if(i == 0 || j==0)
		return DP[i][j] = 0;

	if(DP[i][j])
		return DP[i][j];

	else if(x[i-1] == y[j-1])
		return DP[i][j] = 1 + lcs(i-1,j-1,x,y);

	else
		return DP[i][j] = max(lcs(i-1,j,x,y),lcs(i,j-1,x,y));
}

int main()
{
	string x = "BCBDAB";
	string y = "BDCABA";
	int xl = x.length();
	int yl = y.length();


	printf("Longest Common Subsequence is : %d\n",lcs(xl,yl,x,y));
	return 0;
}
