#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
	int i;
	int f[n+1];

	f[0] = 0;
	f[1] = 1;

	for(i=2;i<=n;i++)
		f[i] = f[i-1] + f[i-2];

	return f[n];
}

int main()
{
	int n = 20;
	printf("%d\n",fib(n));
}