#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int a, b;
	scanf("%d %d",&a,&b);
	int GCD = gcd(a, b);
	int LCM = a * b / GCD;
	printf("%d\n%d\n", GCD, LCM);
}