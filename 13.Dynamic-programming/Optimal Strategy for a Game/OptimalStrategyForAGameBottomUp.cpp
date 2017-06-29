/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
using namespace std;

/*
Optimal Strategy for a Game. Consider a row of n coins of values v(1) ... v(n), where n is even. We play
a game against an opponent by alternating turns. In each turn, a player selects either the first or last
coin from the row, removes it from the row permanently, and receives the value of the coin. Determine
the maximum possible amount of money we can definitely win if we move first.
*/
int main()
{
	int C[] = {20, 30, 2, 2, 2, 10};
	int c = sizeof(C) / sizeof(C[0]);

	pair<int, int>DP[c][c];

	for (int i = 0; i < c; i++)
		DP[i][i] = make_pair(C[i], 0);

	for (int l = 2; l <= c; l++)
	{
		for (int i = 0; i < c - l + 1; i++)
		{
			int j = i + l - 1;

			int a = C[i] + DP[i + 1][j].second;
			int b = C[j] + DP[i][j - 1].second;

			if (a > b)
				DP[i][j] = make_pair(a, DP[i + 1][j].first);

			else
				DP[i][j] = make_pair(b, DP[i][j - 1].first);
		}
	}
	printf("Player 1 gets : %d\nPlayer 2 gets : %d\n", DP[0][c - 1].first, DP[0][c - 1].second);


	return 0;
}
