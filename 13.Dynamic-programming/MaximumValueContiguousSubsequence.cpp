/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A[] = { -2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(A) / sizeof(A[0]);

	int msf = A[0];
	int cmax = A[0];

	for (int i = 1; i < n; i++)
	{
		cmax  = max(cmax + A[i], A[i]);
		msf = max(cmax, msf);
	}

	printf("Maximum contiguous sequence sum is %d\n",msf);
}
