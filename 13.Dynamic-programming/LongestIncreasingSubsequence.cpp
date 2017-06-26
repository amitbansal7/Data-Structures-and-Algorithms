/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
//Longest increasing subsequence

int main()
{
	int seq[] = {3, 4, -1, 0, 6, 2, 3};
	int n = sizeof(seq) / sizeof(seq[0]);

	int DP[n];
	for (int i = 0; i < n; i++)
		DP[i] = 1;

	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (seq[j] < seq[i])
				DP[i] = max(DP[i], DP[j] + 1);

	int maxn = INT_MIN;

	for (int i = 0; i < n; i++)
		if (maxn < DP[i])
			maxn = DP[i];

	printf("%d\n", maxn);

}
