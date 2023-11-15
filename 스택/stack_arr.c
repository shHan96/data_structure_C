#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

#define MAX_SIZE 5

typedef struct stack
{
	int arr[MAX_SIZE];
	int top;
	int size;
}stack;

void createStack(stack* p);
void push(stack* p, int element);
int pop(stack* p);
int print(stack* p);
void clearStack(stack* p);
int stackEmpty(stack* p);
int stackSize(stack* p);

int main()
{
	int choice, value;
	stack stk; //구조체 변수 선언(스택 생성)

	createStack(&stk);

	while (1)
	{
		system("cls");
		printf("\n\n\t\t*** Stack with Array ***\n\n");
		printf("\t\t1. push    2. pop    3. print    4. clear  5.empty  6.size  0. exit\n");
		printf("\t\tchoice : [ ]\b\b");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			printf("\n\n\t\t정수 입력 : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			push(&stk, value);
			break;
		case 2:
			value = pop(&stk); //삭제된 값을 리턴
			break;
		case 3:
			print(&stk);
			break;
		case 4:
			clearStack(&stk);
			break;
		case 5:
			if (stackEmpty(&stk))
			{
				printf("stack이 비어있습니다.\n");
			}
			else
			{
				printf("stack이 비어있지 않습니다..\n");
			}
			break;
		case 6:
			printf("stack 안에 들어있는 값드의 개수는 :%d 입니다.", stackSize(&stk));
			break;
		case 0:
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

void createStack(stack* p) // 스택 초기화
{
	p->top = -1;
	p->size = 0;
}
void push(stack* p, int element) // 스택 push연산
{
	if (p->size == MAX_SIZE)
	{
		printf("stack overflow 발생\n"); //스택이 다 차면 overflow발생
		return;
	}
	
	p->top++;
	p->arr[p->top] = element;
	p->size += 1;
}
int pop(stack* p) // 스택 pop 연산
{
	if (p->size == 0)
	{
		printf("stack underflow 발생\n"); //스택이 비었으면 
		return -1;
	}
	int top = p->arr[p->top];
	p->top--;
	p->size -= 1;
	printf("stack pop value is %d\n", top);
	return top; //pop해주고 pop한 값 리턴
}
int print(stack* p)
{
	if (p->size == 0)
	{
		printf("stack is empty\n"); // 비었으면 종료
		return -1;
	}
	printf("stack top is %d", p->arr[p->top]); // 탑값 출력
	return p->arr[p->top]; // 스택에 탑 값 리턴
}
void clearStack(stack* p) // 스택 초기화하는 것과 같다.
{
	p->top = -1;
	p->size = 0;
	printf("stack is clear\n");
}
int stackEmpty(stack* p) // 스택의 size가 0인지 확인
{
	if (p->size == 0)
		return 1;
	else
		return 0;
}
int stackSize(stack* p) //스택 사이즈 리턴
{
	return p->size;
}