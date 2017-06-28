/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
using namespace std;

/*
You have a set of n integers each in the range 0 ... K. Partition these integers into two subsets such
that you minimize |S1 - S2|, where S1 and S2 denote the sums of the elements in each of the two subsets.
*/

int main()
{
	int set[] = {3, 1, 4, 2, 2, 1};
	int TotalSum = 0;
	int n = sizeof(set) / sizeof(set[0]);

	for (int i = 0; i < n; i++)
		TotalSum += set[i];

	bool DP[n][TotalSum + 1];
	memset(DP,0,sizeof(DP));

	for (int i = 0; i < n; i++)
		DP[i][0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= TotalSum; j++)
		{
			if (j < set[i])
				DP[i][j] = i < 1 ? 0 : DP[i - 1][j];

			else if (j == set[i])
				DP[i][j] = 1;

			else
				DP[i][j] = i < 1 ? 0 :DP[i-1][j] || DP[i-1][j-set[i]];
		}
	}

	int dif;

	for(int j = TotalSum/2;j>=0;j--)
	{
		if(DP[n-1][j])
		{
			dif = TotalSum - 2*j;
			break;
		}
	}
	printf("Minimum difference is %d\n",dif);

	return 0;
}
