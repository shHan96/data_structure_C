#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

void move(int n, int a,int b) // 원판을 움직이는 함수
{
	printf("%d %d\n", a, b);
}

void hanoi(int n, int one, int three, int two) // 1번째에서 3번째로 이동한다 2번째위치를 이용해서
{
	if (n == 1) 
	{
		move(n, one, three); // 첫번째 것은 1에서 3으로 이동한다.
		return;
	}
	hanoi(n - 1,one,two,three); //n-1개를 2번위치로 이동한다.
	move(n, one, three);//n번째 것을 3위치로 이동한다.
	hanoi(n - 1, two, three, one);//n-1개를 2번위치에서 3번위치로 이동한다.
}
int expo(int n) // 2의 제곱을 해주는 재귀함수
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