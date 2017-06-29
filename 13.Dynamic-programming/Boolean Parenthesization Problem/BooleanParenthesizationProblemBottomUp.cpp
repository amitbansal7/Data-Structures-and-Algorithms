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
	char exp[] = "TTFT";
	char op[] = "|&^";
	int n = strlen(exp);

	int T[n + 1][n + 1];
	int F[n + 1][n + 1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			T[i][j] = F[i][j] = 0;

	for (int i = 0; i < n; i++)
	{
		T[i][i] = (exp[i] == 'T') ? 1 : 0;
		F[i][i] = (exp[i] == 'F') ? 1 : 0;
	}

	for (int l = 2; l <= n; l++)
	{
		for (int i = 0; i < n - l + 1; i++)
		{
			int j = l + i - 1;

			for (int k = i; k < j; k++)
			{
				int Tik = T[i][k] + F[i][k];
				int Tkj = T[k + 1][j] + F[k + 1][j];

				if (op[k] == '&')
				{
					T[i][j] += T[i][k] * T[k + 1][j];
					F[i][j] += Tik * Tkj - T[i][k] * T[k + 1][j];
				}

				else if (op[k] == '|')
				{
					T[i][j] += Tik * Tkj - F[i][k] * F[k + 1][j];
					F[i][j] += F[i][k] * F[k + 1][j];
				}

				else if (op[k] == '^')
				{
					T[i][j] += T[i][k] * F[k + 1][j] + F[i][k] * T[k + 1][j];
					F[i][j] += T[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j];
				}
			}
		}
	}

	printf("%d\n", T[0][n - 1]);
	return 0;
}
