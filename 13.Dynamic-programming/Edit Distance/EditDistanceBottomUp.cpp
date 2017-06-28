/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
using namespace std;

/*
Edit Distance. Given two text strings A of length n and B of length m, you want to transform A into B
with a minimum number of operations of the following types: delete a character from A, insert a
character into A, or change some character in A into a new character. The minimal number of such
operations required to transform A into B is called the edit distance between A and B.
*/

int main()
{
	string a = "FOOD";
	string b = "MONEY";

	int al = a.length();
	int bl = b.length();

	int DP[al + 1][bl + 1];

	for (int i = 0; i <= al; i++)
	{
		for (int j = 0; j <= bl; j++)
		{
			if (i == 0)
				DP[i][j] = j;

			else if (j == 0)
				DP[i][j] = i;

			else if (a[i - 1] == b[j - 1])
				DP[i][j] = DP[i - 1][j - 1];

			else
				DP[i][j] = 1 + min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1]));
		}
	}

	printf("%d\n",DP[al][bl]);


	return 0;
}
