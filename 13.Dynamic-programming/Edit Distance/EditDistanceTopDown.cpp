/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
using namespace std;

/*
Edit Distance. Given two text strings A of length n and B of length m, you want to transform A into B
with a minimum number of operations of the following types: delete a character from A, insert a
character into A, or change some character in A into a new character. The minimal number of such
operations required to transform A into B is called the edit distance between A and B.
*/

int DP[20][20];

int solve(string a, string b, int i, int j)
{
	if (i < 1)
		return DP[i][j] = j;

	else if (j < 1)
		return DP[i][j] = i;

	else if (a[i-1] == b[j-1])
		return DP[i][j] = solve(a, b, i - 1, j - 1);

	return DP[i][j] = 1 + min(solve(a, b, i - 1, j - 1),
	                          min(solve(a, b, i - 1, j), solve(a, b, i, j - 1)));
}
int main()
{
	string a = "FOOD";
	string b = "MONEY";

	int al = a.length();
	int bl = b.length();

	printf("%d\n", solve(a, b, al, bl));

	return 0;
}
