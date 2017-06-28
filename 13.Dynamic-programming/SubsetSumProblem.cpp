/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
using namespace std;
//Subset Sum Problem

int main()
{
	int set[] = {2, 3, 7, 8, 10};
	int sz = sizeof(set) / sizeof(set[0]);
	int s = 11;
	bool DP[s + 1][sz];

	//If sum is 0 answer is always true.
	for (int i = 0; i < sz; i++)
		DP[0][i] = 1;

	for (int i = 0; i < sz; i++)
	{
		for (int n = 1; n <= s; n++)
		{
			if (n < set[i])
				DP[n][i] = i < 1 ? 0 : DP[n][i - 1];

			else if (n == set[i])
				DP[n][i] = 1;

			else
				DP[n][i] = i < 1 ? 0 : DP[n][i - 1] || DP[n - set[i]][i - 1];
		}
	}

	DP[11][sz - 1] ? cout << "For 11 : Yes" << endl : cout << "For 11 : No" << endl;
	DP[6][sz - 1] ? cout << "For 6 : Yes" << endl : cout << "For 6 : No" << endl;

	return 0;
}
