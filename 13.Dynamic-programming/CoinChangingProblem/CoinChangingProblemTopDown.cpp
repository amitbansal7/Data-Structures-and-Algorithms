/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int Coins[] = {1, 3, 5};
int c = sizeof(Coins) / sizeof(Coins[0]);
int DP[12];

int solve(int s)
{
	if(DP[s] != INF)
		return DP[s];

	if (s <= 0)
		return DP[s] = 0;

	for (int i = 0; i < c; i++)
		if (s >= Coins[i])
			DP[s] = min(DP[s], solve(s - Coins[i]) + 1);

	return DP[s];
}

int main()
{
	int s = 11;

	memset(DP, INF, sizeof(DP));

	printf("%d\n", solve(s));

}
