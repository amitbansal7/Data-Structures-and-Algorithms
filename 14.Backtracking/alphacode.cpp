#include <bits/stdc++.h>
using namespace std;

/*
	All possible codes that an integer string can generate.
	1 = a, 2 = b , 3 = c, ...... 26 = z;

	input:
		1123

	output:
		aabc
		aaw
		alc
		kbc
		kw

*/

void solve(string &input, string &t, int i)
{
	if (i >= input.size())
	{
		cout << t << endl;
		return;
	}
	
	if(input[i] == '0')
		return;
	
	int a = input[i] - '0';
	if (input[i] <= '9')
	{
		t.push_back((char)(96 + a));
		solve(input, t, i + 1);
		t.pop_back();
	}

	if (i + 1 < input.size() && (input[i] == '1' || (input[i] == '2' && input[i + 1] <= '6')))
	{
		int b = input[i + 1] - '0';
		int c = a * 10 + b;
		t.push_back((char)(96 + c));
		solve(input, t, i + 2);
		t.pop_back();
	}
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	string t;
	solve(s, t, 0);
	return 0;
}
