#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct queue
{
	
	int* data;		//동적할당된 메모리의 주소를 저장하는 포인터(8바이트)
	int rear;		//삽입할 배열의 인덱스
	int front;		//삭제할 배열의 인덱스
	int size;		//배열에 저장된 원소의 개수
	int capacity;	//배열의 최대 용량(배열의 크기)
}queue;

void createQueue(queue* pQue, int count); //큐 초기화
void push(queue* pQue, int value); // 큐의 맨 뒤에 값 삽입
int pop(queue* pQue); // 큐의 맨 앞값 삭제
int print(queue* pQue);//큐의 맨 앞값 출력
void clear(queue* pQue);//큐 초기화
int isEmpty(queue* pQue); //큐가 비어 있다면 1, 아니라면 0리턴
int size(queue* pQue); // 큐에 들어있는 값들의 개수
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
	queue que; //구조체 변수 선언(24바이트)
	int choice, count, value;

	printf("할당하고 싶은 큐의 크기를 입력 하세요 : ");
	scanf("%d", &count);
	while (getchar() != '\n');

	createQueue(&que, count);

	while (1)
	{
		system("cls");
		display(&que);
		printf("\n\n\t\t****  배열을 이용한 원형 큐 ***\n\n");
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

void createQueue(queue* pQue, int count) // 큐초기화
{
	pQue->data = (int*)malloc(sizeof(int) * count);
	pQue->front = 0;
	pQue->rear = 0;
	pQue->size = 0;
	pQue->capacity = count;
}
void push(queue* pQue, int value)
{
	if (pQue->size == pQue->capacity) // 꽈차있을때
	{
		printf("queue is full\n");
		return;
	}

	if (pQue->size == 0) // 큐에 값이 없다면
	{
		pQue->data[pQue->rear] = value;
	}
	else
	{
		pQue->rear = (pQue->rear + 1) % pQue->capacity;//한칸 이동하고
		pQue->data[pQue->rear] = value; // 값삽입
	}
	pQue->size += 1;
}
int pop(queue* pQue)
{
	if (pQue->size == 0)
	{
		printf("queue is empty\n"); //큐가 비어있으면 오류
		return -1;
	}
	if (pQue->size == 1) // 큐에 한개의 데이터가 있다면
	{
		printf("pop data is %d\n", pQue->data[pQue->front]); //출력
		pQue->size -= 1; // 사이즈 감소
		return pQue->data[pQue->front]; // 리턴
	}
	else
	{
		int popData = pQue->data[pQue->front]; //값 저장
		pQue->front = (pQue->front + 1) % pQue->capacity; // font이동
		printf("pop data is %d\n", popData); // 출력
		pQue->size -= 1; //사이즈 감소
		return popData; // 출력
	}
}
int print(queue* pQue)
{
	if (pQue->size == 0)
	{
		printf("queue is empty\n");
		return -1;
	}
	printf("queue front is %d\n", pQue->data[pQue->front]); //front값 출력
	return pQue->data[pQue->front];
}

void clear(queue* pQue) //초기화
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