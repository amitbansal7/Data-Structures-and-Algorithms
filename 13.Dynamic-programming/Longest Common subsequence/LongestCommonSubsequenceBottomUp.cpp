/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
#include <string>
#define lli long long int
#define llu unsigned long long int
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define Mset(p,i) memset(p,i,sizeof(p))
#define mlc(t,n) (t *)malloc(sizeof(t)*n)
#define NIL -1
#define INF 0x3f3f3f3f
#define TC int testcase; S(testcase); while(testcase--)
#define Pi 3.14159
using namespace std;

int main()
{
	string x = "BCBDAB";
	string y = "BDCABA";
	int xl = x.length();
	int yl = y.length();

	int DP[xl+1][yl+1];

	for(int i=0;i<=xl;i++)
		for(int j=0;j<=yl;j++)
		{
			if(i == 0 || j == 0)
				DP[i][j] = 0;
			else if(x[i-1] == y[j-1])
				DP[i][j] = 1 + DP[i-1][j-1];

			else
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
		}

	printf("Longest Common Subsequence is : %d\n",DP[xl][yl]);

}
