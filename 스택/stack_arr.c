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
	stack stk; //����ü ���� ����(���� ����)

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
			printf("\n\n\t\t���� �Է� : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			push(&stk, value);
			break;
		case 2:
			value = pop(&stk); //������ ���� ����
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
				printf("stack�� ����ֽ��ϴ�.\n");
			}
			else
			{
				printf("stack�� ������� �ʽ��ϴ�..\n");
			}
			break;
		case 6:
			printf("stack �ȿ� ����ִ� ������ ������ :%d �Դϴ�.", stackSize(&stk));
			break;
		case 0:
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

void createStack(stack* p) // ���� �ʱ�ȭ
{
	p->top = -1;
	p->size = 0;
}
void push(stack* p, int element) // ���� push����
{
	if (p->size == MAX_SIZE)
	{
		printf("stack overflow �߻�\n"); //������ �� ���� overflow�߻�
		return;
	}
	
	p->top++;
	p->arr[p->top] = element;
	p->size += 1;
}
int pop(stack* p) // ���� pop ����
{
	if (p->size == 0)
	{
		printf("stack underflow �߻�\n"); //������ ������� 
		return -1;
	}
	int top = p->arr[p->top];
	p->top--;
	p->size -= 1;
	printf("stack pop value is %d\n", top);
	return top; //pop���ְ� pop�� �� ����
}
int print(stack* p)
{
	if (p->size == 0)
	{
		printf("stack is empty\n"); // ������� ����
		return -1;
	}
	printf("stack top is %d", p->arr[p->top]); // ž�� ���
	return p->arr[p->top]; // ���ÿ� ž �� ����
}
void clearStack(stack* p) // ���� �ʱ�ȭ�ϴ� �Ͱ� ����.
{
	p->top = -1;
	p->size = 0;
	printf("stack is clear\n");
}
int stackEmpty(stack* p) // ������ size�� 0���� Ȯ��
{
	if (p->size == 0)
		return 1;
	else
		return 0;
}
int stackSize(stack* p) //���� ������ ����
{
	return p->size;
}