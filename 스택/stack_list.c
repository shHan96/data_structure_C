#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

#define MAX_SIZE 5

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

typedef struct stack
{
	List list;
}stack;
DNode* create_dnode(int element); //동적 메모리 할당 후 동적 메모리의 주소 리턴
void List_init(List* list); //리스트 초기화
void insert_tail_dnode(List* list,int element); // 맨 뒤 삽입
int remove_tail_dnode(List* list); // 맨뒤 삭제
void remove_all_dnode(List* list); // 모든 노드 삭제
int get_dnode_count(List* list); // 리스트의 갯수
void createStack(stack* p); //스택 초기화
void push(stack* p, int element); // 스택 push연산 
int pop(stack* p); // 스택 pop연산
int print(stack* p); // 스택 top값 출력
void clearStack(stack* p); // 스택을 비운다
int stackEmpty(stack* p); // 스택이 비어있는지?
int stackSize(stack* p); // 스택안에 들어 있는 값들의 개수

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
			push(&stk,value);
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
DNode* create_dnode(int element) // 노드 생성과 초기화
{
	DNode* newDNode = (DNode*)malloc(sizeof(DNode));
	newDNode->next = NULL;
	newDNode->prev = NULL;
	newDNode->value = element;
	return newDNode;
}
void List_init(List* list)
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}
void insert_tail_dnode(List* list,int element) // 맨 뒤 삽입
{
	DNode* newDNode = create_dnode(element); // 노드 생성
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
int remove_tail_dnode(List* list) // 맨뒤 삭제
{
	int top;
	if (list->size == 0) // 삭제할게 없다면 종료
		return -1;
	else if (list->size == 1) // 1개라면 맨뒤에 거를 없애주고 초기화
	{
		top = list->tail->value;
		free(list->tail);
		list->head = NULL;
		list->tail = NULL;

	}
	else
	{
		top = list->tail->value;
		DNode* deleteNode = list->tail;
		list->tail = list->tail->prev; // tail을 변경하고 
		list->tail->next = NULL; //next값 NULL로 변경  
		free(deleteNode); //삭제
	}
	list->size -= 1;
	return top;
}
int get_dnode_count(List* list)
{
	return list->size; // size리턴
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
void createStack(stack* p)
{
	List_init(&p->list); //스택안 리스트 초기화
}
void push(stack* p, int element)
{
	insert_tail_dnode(&p->list,element); //스택에서의 맨 뒤 삽입
}
int pop(stack* p) 
{
	if (get_dnode_count(&p->list) == 0)
	{
		printf("stack underflow 발생\n");
		return -1;
	}
	else
	{
		int top =remove_tail_dnode(&p->list); //맨 뒤값 제거
		printf("stack pop value is %d\n", top);
		return top;
	}
}
int print(stack* p)
{
	if (get_dnode_count(&p->list) == 0)
	{
		printf("stack is empty\n");
		return -1;
	}
	printf("stack top is %d", p->list.tail->value);
	return p->list.tail->value;
}
void clearStack(stack* p)
{
	remove_all_dnode(&p->list); // 리스트의 모든값 제거
	printf("stack is clear\n");
}
int stackEmpty(stack* p) // 리스트에 값 있는지 확인
{
	if (get_dnode_count(&p->list) == 0)
		return 1;
	else
		return 0;
}
int stackSize(stack* p) //리스트의 사이즈 확인
{
	return get_dnode_count(&p->list);
}