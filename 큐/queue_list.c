#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

enum menuType //열거형
{
	//열거형은 0에서 차례대로 1씩 증가되는 상수값을 취한다.
	//만약, 상수값을 지정한 경우 그 값부터 1씩 증가되는 값을 취한다.
	INSERT_FRONT = 1, INSERT_TAIL, INSERT_ASCEND_SORT, INSERT_FRONT_NTH,
	REMOVE_FRONT, REMOVE_TAIL, REMOVE_ALL, REMOVE_FRONT_NTH, REMOVE_VALUE,
	TRAVERSAL, SEARCH, GET_NODE_COUNT, REVERSE, TERMINATE = 0
};

typedef struct node
{
	int value; //데이터
	struct node* prev; //이전 노드의 주소 저장하는 포인터 //8바이트
	struct node* next; //다음 노드의 주소 저장하는 포인터 //8바이트
}DNode;

typedef struct _List
{
	int size;
	DNode* head;
	DNode* tail;
}List;




DNode* create_dnode(int value); //동적 메모리 할당 후 동적 메모리의 주소 리턴
void List_init(List* list); //리스트 초기화
void insert_tail_dnode(List* list,int value); // 맨 뒤 삽입
void traversal_dnode(List* list); // 앞에서 부터 차례로 순회
int remove_front_dnode(List* list); // 맨앞 삭제
void remove_all_dnode(List* list); // 모든 노드 삭제
typedef struct _queue
{
	List list;
}queue;


void createQueue(queue* pQue);
void push(queue* pQue, int value);
int pop(queue* pQue);
int print(queue* pQue);
void clear(queue* pQue);//큐가 가득 찼다면 있다면 1, 아니라면 0리턴
int isEmpty(queue* pQue); //큐가 비어 있다면 1, 아니라면 0리턴
int size(queue* pQue);
void display(queue* pQue);
int main()
{
	queue que; //구조체 변수 선언(24바이트)
	int choice, count, value;
	createQueue(&que);

	while (1)
	{
		system("cls");
		display(&que);
		printf("\n\n\t\t****  리스트를 이용한 큐 ***\n\n");
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
void List_init(List* list)  // 리스트 초기화
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}
DNode* create_dnode(int value) // 노드 생성과 초기화
{
	DNode* newDNode = (DNode*)malloc(sizeof(DNode));
	newDNode->next = NULL;
	newDNode->prev = NULL;
	newDNode->value = value;

	return newDNode;
}
void insert_tail_dnode(List* list,int value) // 맨 뒤 삽입
{
	DNode* newDNode = create_dnode(value); // 노드 생성
	if (list->size == 0) // 비어있다면
	{
		list->head = newDNode;
		list->tail = newDNode;
		list->size += 1;
		return;
	}
	list->tail->next = newDNode; // 맨뒤에 삽입하고 tail 생성
	newDNode->prev = list->tail;
	list->tail = newDNode;
	list->size += 1;
}
int remove_front_dnode(List* list) // 맨앞 삭제
{
	int popData;
	if (list->size == 0)
	{
		printf("queue is empty\n");
		return -1;
	}
	else if (list->size == 1) // 1개라면
	{
		popData = list->head->value;
		free(list->head); //처음것 없애주고 초기화
		list->head = NULL;
		list->tail = NULL;
		list->size -= 1;
		printf("pop data is %d\n", popData);
		return popData;
	}
	else
	{
		popData = list->head->value;
		DNode* deleteNode = list->head; // 맨앞에 삭제
		list->head = list->head->next; // head값 변경
		list->head->prev = NULL; // 뒤에 노드 null값 넣어준다.
		free(deleteNode);
		list->size -= 1;
		printf("pop data is %d\n", popData);
		return popData;
	}
	
}
void remove_all_dnode(List* list) // 모든 노드 삭제
{
	if (list->size == 0) //삭제 할게 없으면
	{
		return;
	}
	DNode* deleteDNode, * curDNode;
	curDNode = list->head;
	while (curDNode) // 처음부터 하나씩 순회 하면서 삭제한다
	{
		deleteDNode = curDNode;
		curDNode = curDNode->next;
		free(deleteDNode);
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}
void traversal_dnode(List* list) //순회
{
	if (list->size == 0) //0개면 순회 안한다.
	{
		return;
	}
	DNode* curDNode = list->head; // 맨앞부터
	
	while (curDNode) // 하나씩 순회 한다.
	{
		printf("%d ", curDNode->value);
		curDNode = curDNode->next;
	}
	printf("\n");
}
void createQueue(queue* pQue)
{
	List_init(&pQue->list); //리스트 초기화
}
void push(queue* pQue, int value)
{
	insert_tail_dnode(&pQue->list, value); // 이중 리스트 맨뒤에 삽입
}

int pop(queue* pQue)
{
	if (pQue->list.size == 0)
	{
		printf("queue is empty\n");
		return -1;
	}
	return remove_front_dnode(&pQue->list); // 맨 앞값 삭제
}

int print(queue* pQue)
{
	if (pQue->list.size == 0)
	{
		printf("queue is empty\n");
		return -1;
	}
	printf("queue front is %d", pQue->list.head->value);
	return pQue->list.head->value; // 맨 앞값 출력
}
void clear(queue* pQue)
{
	remove_all_dnode(&pQue->list); // 모든 리스트 값 삭제
}
int isEmpty(queue* pQue)
{
	if (pQue->list.size == 0)
		return 1;
	else
		return 0;
}
int size(queue* pQue)
{
	return pQue->list.size;
}
void display(queue* pQue)
{
	traversal_dnode(&pQue->list);
}