#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

void move(int n, int a,int b) // ������ �����̴� �Լ�
{
	printf("%d %d\n", a, b);
}

void hanoi(int n, int one, int three, int two) // 1��°���� 3��°�� �̵��Ѵ� 2��°��ġ�� �̿��ؼ�
{
	if (n == 1) 
	{
		move(n, one, three); // ù��° ���� 1���� 3���� �̵��Ѵ�.
		return;
	}
	hanoi(n - 1,one,two,three); //n-1���� 2����ġ�� �̵��Ѵ�.
	move(n, one, three);//n��° ���� 3��ġ�� �̵��Ѵ�.
	hanoi(n - 1, two, three, one);//n-1���� 2����ġ���� 3����ġ�� �̵��Ѵ�.
}
int expo(int n) // 2�� ������ ���ִ� ����Լ�
{
	if (n == 0)
		return 1;
	return 2 * expo(n - 1);
}
int main()
{
	int N;
	scanf("%d", &N);
	printf("%d\n", expo(N) - 1);
	hanoi(N,1,3,2);
}