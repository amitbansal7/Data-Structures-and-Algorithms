/* Amit Bansal - @amitbansal7 */
#include <bits/stdc++.h>
using namespace std;

void printCombination(int chosenCoin[],int coins[],int s)
{
	if(chosenCoin[s] == -1)
	{
		printf("Coins cannot be chosen\n");
		return;
	}

	printf("Coins used are : ");
	while(s!=0)
	{
		int j = chosenCoin[s];
		printf("%d ",coins[j]);
		s -= coins[j];
	}
	printf("\n");
}

int main()
{
	int s = 11;
	int coins[] = {1,3,5};

	int chosenCoin[s+1];
	Mset(chosenCoin,-1);

	int NoOfCoins[s+1];
	Mset(NoOfCoins,INF);

	NoOfCoins[0] = 0;
	printf("No of coins are : %d\n",NoOfCoins[s]);
	printCombination(chosenCoin,coins,s);


	for(int j=0;j<3;j++)
		for(int i=1;i<=s;i++)
			if(i >= coins[j] && NoOfCoins[i] > NoOfCoins[i - coins[j]]+1)
			{
				chosenCoin[i] = j;
				NoOfCoins[i] = NoOfCoins[i - coins[j]] + 1;
			}

	printf("No of Coins Used : %d\n",NoOfCoins[s]);
	printCombination(chosenCoin,coins,s);


	return 0;
}

