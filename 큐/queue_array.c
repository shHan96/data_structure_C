#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct queue
{
	
	int* data;		//�����Ҵ�� �޸��� �ּҸ� �����ϴ� ������(8����Ʈ)
	int rear;		//������ �迭�� �ε���
	int front;		//������ �迭�� �ε���
	int size;		//�迭�� ����� ������ ����
	int capacity;	//�迭�� �ִ� �뷮(�迭�� ũ��)
}queue;

void createQueue(queue* pQue, int count); //ť �ʱ�ȭ
void push(queue* pQue, int value); // ť�� �� �ڿ� �� ����
int pop(queue* pQue); // ť�� �� �հ� ����
int print(queue* pQue);//ť�� �� �հ� ���
void clear(queue* pQue);//ť �ʱ�ȭ
int isEmpty(queue* pQue); //ť�� ��� �ִٸ� 1, �ƴ϶�� 0����
int size(queue* pQue); // ť�� ����ִ� ������ ����
void display(queue* pQue)
{
	if (pQue->size == 0)
		return;

	int temp = pQue->front;
	for (int i = 0; i < pQue->size; i++)
	{
		printf("%d ", pQue->data[temp]);
		temp = (temp + 1) % pQue->capacity;
	}
	printf("\n");
}
int main()
{
	queue que; //����ü ���� ����(24����Ʈ)
	int choice, count, value;

	printf("�Ҵ��ϰ� ���� ť�� ũ�⸦ �Է� �ϼ��� : ");
	scanf("%d", &count);
	while (getchar() != '\n');

	createQueue(&que, count);

	while (1)
	{
		system("cls");
		display(&que);
		printf("\n\n\t\t****  �迭�� �̿��� ���� ť ***\n\n");
		printf("1. push    2. pop    3. print    4. clear   5.size    6. empty   0. terminate\n");
		printf("choice : [ ]\b\b");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			printf("\n\ninteger push : ");
			scanf("%d", &value);
			while (getchar() != '\n');
			push(&que, value);
			break;
		case 2:
			pop(&que);
			break;
		case 3:
			print(&que);
			break;
		case 4:
			clear(&que);
			break;
		case 5:
			printf("queue size is %d \n", size(&que));
			break;
		case 6:
			if (isEmpty(&que))
				printf("queue is empty\n");
			else
				printf("queue is not empty\n");
			break;
		case 0:
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

void createQueue(queue* pQue, int count) // ť�ʱ�ȭ
{
	pQue->data = (int*)malloc(sizeof(int) * count);
	pQue->front = 0;
	pQue->rear = 0;
	pQue->size = 0;
	pQue->capacity = count;
}
void push(queue* pQue, int value)
{
	if (pQue->size == pQue->capacity) // ����������
	{
		printf("queue is full\n");
		return;
	}

	if (pQue->size == 0) // ť�� ���� ���ٸ�
	{
		pQue->data[pQue->rear] = value;
	}
	else
	{
		pQue->rear = (pQue->rear + 1) % pQue->capacity;//��ĭ �̵��ϰ�
		pQue->data[pQue->rear] = value; // ������
	}
	pQue->size += 1;
}
int pop(queue* pQue)
{
	if (pQue->size == 0)
	{
		printf("queue is empty\n"); //ť�� ��������� ����
		return -1;
	}
	if (pQue->size == 1) // ť�� �Ѱ��� �����Ͱ� �ִٸ�
	{
		printf("pop data is %d\n", pQue->data[pQue->front]); //���
		pQue->size -= 1; // ������ ����
		return pQue->data[pQue->front]; // ����
	}
	else
	{
		int popData = pQue->data[pQue->front]; //�� ����
		pQue->front = (pQue->front + 1) % pQue->capacity; // font�̵�
		printf("pop data is %d\n", popData); // ���
		pQue->size -= 1; //������ ����
		return popData; // ���
	}
}
int print(queue* pQue)
{
	if (pQue->size == 0)
	{
		printf("queue is empty\n");
		return -1;
	}
	printf("queue front is %d\n", pQue->data[pQue->front]); //front�� ���
	return pQue->data[pQue->front];
}

void clear(queue* pQue) //�ʱ�ȭ
{
	pQue->front = 0;
	pQue->rear = 0;
	pQue->size = 0;
}
int isEmpty(queue* pQue)
{
	if (pQue->size == 0)
		return 1;
	else
		return 0;
}
int size(queue* pQue)
{
	return pQue->size;
}