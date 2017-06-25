/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
using namespace std;
// RNA Secondary structure problem (RNA folding)
// OPT(i,j) = max(OPT(i,j-1), (for all t)max(1 + OPT(i,t-1) + OPT(t+1,j-1)));
// All characters in the string are from set {A, U, C, G}
// One blank character at s[0] because we use 1 based indexing.
// Running time of this algorithm is O(n^3)

string s = " ACCGGUAGU";

int DP[100][100];

int OPT(int i, int j)
{
	if (DP[i][j] != -1)
		return DP[i][j];

	if (i <= j - 4)
	{
		int a = OPT(i, j - 1);
		int b = INT_MIN;
		for (int t = i; t < j; t++)
			if ((s[t] == 'A' && s[j] == 'U') || ((s[t] == 'C') && s[j] == 'G'))
				b = max(b, 1 + OPT(i, t - 1) + OPT(t + 1, j - 1));

		return  DP[i][j] = max(a, b);
	}
	else
		return DP[i][j] = 0;
}

int main()
{
	memset(DP, -1, sizeof(DP));
	printf("%d\n", OPT(1, s.length() - 1));
}
