#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

long long fibo(int N)
{
	if (N == 0)
		return 0;
	if (N == 1)
		return 1;
	return fibo(N - 1) + fibo(N - 2);
}

int main()
{
	int N;
	scanf("%d", &N);
	printf("%lld", fibo(N));
}