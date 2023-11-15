#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

long long factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * factorial(n - 1);
}


int main()
{
	int N;
	scanf("%d", &N);
	printf("%lld", factorial(N));
}