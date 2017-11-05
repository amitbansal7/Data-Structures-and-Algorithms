#include <bits/stdc++.h>
using namespace std;
// Find Power Set of a set of characters

void PrintSet(char result[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%c ", result[i]);

	printf("\n");
}

void Pset(char chs[], int count[], int pos, char result[], int depth, int cs)
{
	PrintSet(result, depth);
	for (int i = pos; i < cs; i++)
	{
		if (count[i] != 0)
		{
			result[depth] = chs[i];
			count[i]--;
			Pset(chs, count, i, result, depth + 1, cs);
			count[i]++;
		}
	}
}

void powerSet(char exp[])
{
	map<char, int> cmap;
	int l = strlen(exp);

	for (int i = 0; i < l; i++)
	{
		cmap.insert(pair<char, int>(exp[i], 0));
		map<char, int>::iterator it;
		it = cmap.find(exp[i]);
		++it->second;
		cmap.insert(pair<char, int>(exp[i], it->second));
	}

	int cs = cmap.size();
	char chs[cs];
	int count[cs];

	map<char, int> ::iterator it;
	int i = 0;
	for (it = cmap.begin(); it != cmap.end(); it++)
	{
		chs[i] = it->first;
		count[i] = it->second;
		i++;
	}

	char result[cs];
	Pset(chs, count, 0, result, 0, cs);
}

int main(int argc, char const *argv[])
{
	char exp[1000];
	cout << "Enter an expression :";
	cin >> exp;

	powerSet(exp);
	return 0;
}
