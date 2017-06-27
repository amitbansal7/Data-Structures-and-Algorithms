/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
using namespace std;

struct Pair
{
	int x, y;
};

bool compare(struct Pair a, struct Pair b)
{
	if (a.y == b.y)
		return a.x < b.x;

	return a.y < b.y;
}

int main()
{
	struct Pair CityPairs[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};
	int n = sizeof(CityPairs)/sizeof(CityPairs[0]);

	sort(CityPairs, CityPairs + n, compare);

	int maxbridges[n];
	for (int i = 0; i < n; i++)
		maxbridges[i] = 1;

	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (CityPairs[j].x <= CityPairs[i].x)
				maxbridges[i] = max(maxbridges[i], maxbridges[j] + 1);

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, maxbridges[i]);

	printf("Maximum number of bridges are : %d\n", ans);
}
