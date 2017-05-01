#include <bits/stdc++.h>

// find occurrences of a character in a string

using namespace std;
int main(int argc, char const *argv[])
{
	char exp[] = {"qawaaertqawsedrfqw"};

	map<char,int> cmap;

	for(int i=0;i<strlen(exp);i++)
	{
		cmap.insert(pair<char,int>(exp[i],0));
		map<char,int> :: iterator it;
		it = cmap.find(exp[i]);
		++it->second;

		cmap.insert(pair<char,int>(exp[i],it->second));
	}

	map<char,int> ::iterator it;
	for(it = cmap.begin();it != cmap.end();it++)
		printf("%c %d\n",it->first,it->second);

	return 0;
}
