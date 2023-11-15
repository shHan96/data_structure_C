#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100001

#pragma warning (disable : 4996)

typedef struct
{
	int arr[MAX_SIZE];
	int size;
}PriorityQueue;
void init_PriorityQueue(PriorityQueue* pq); // �ʱ�ȭ
int size(PriorityQueue* pq); // ���� ����ִ� ������ ����
void push(PriorityQueue* pq,int data); // ���� ������ ����
int pop(PriorityQueue* pq); // ���� ������ ����
int empty(PriorityQueue* pq); // ���� ����ִ��� ����


int main()
{
	PriorityQueue pq;
	init_PriorityQueue(&pq);
	int n;
	scanf("%d", &n);
	int value;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &value);
		if (value == 0)
		{
			if (empty(&pq))
				printf("%d\n", 0);
			else
				printf("%d\n", pop(&pq));
		}
		else
		{
			push(&pq, value);
		}
	}
	return 0;
}

void init_PriorityQueue(PriorityQueue* pq)
{
	pq->size = 0;
}
int size(PriorityQueue* pq) 
{
	return pq->size;
}
void push(PriorityQueue* pq,int data)
{
	pq->size += 1;
	int index = pq->size;
	while (index > 1&& data<pq->arr[index/2]) // ��ġ ã��
	{
		pq->arr[index] = pq->arr[index / 2];
		index /= 2;
	}
	pq->arr[index] = data;
}
int pop(PriorityQueue* pq)
{
	if (pq->size == 1)  // ����� 1�̸� ����
	{
		pq->size--;
		return pq->arr[1];
	}
	int pop_data = pq->arr[1]; 
	int temp = pq->arr[pq->size];
	pq->size--;
	int parent = 1;
	int child = 2;
	while (child <= pq->size)
	{
		if (child < pq->size && pq->arr[child + 1] < pq->arr[child]) // �����ʰ��� �� �۴ٸ�
			child++;
		if (temp <= pq->arr[child]) // �ڽĺ��� ���� �۰ų� ���ٸ�
			break;
		pq->arr[parent] = pq->arr[child];
		parent = child;
		child *= 2;
	}
	pq->arr[parent] = temp;
	return pop_data;
}
int empty(PriorityQueue* pq)
{
	return (pq->size == 0) ? 1 : 0;
}