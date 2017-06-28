/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v[] = {60, 100, 120, 150};
    int w[] = {10, 20, 30, 20};
    const int c = 60;
    int itm = sizeof(v) / sizeof(v[0]);
    int DP[c + 1] = {0};

    for (int i = 0; i <= c; i++)
        for (int j = 0; j < itm; j++)
            if (w[j] <= i)
                DP[i] = max(DP[i], DP[i - w[j]] + v[j]);

    printf("%d\n", DP[c]);

    return 0;
}
