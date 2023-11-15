#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

#define MAX_SIZE 5

typedef struct node
{
	int value; //������
	struct node* prev; //���� ����� �ּ� �����ϴ� ������ //8����Ʈ
	struct node* next; //���� ����� �ּ� �����ϴ� ������ //8����Ʈ
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
DNode* create_dnode(int element); //���� �޸� �Ҵ� �� ���� �޸��� �ּ� ����
void List_init(List* list); //����Ʈ �ʱ�ȭ
void insert_tail_dnode(List* list,int element); // �� �� ����
int remove_tail_dnode(List* list); // �ǵ� ����
void remove_all_dnode(List* list); // ��� ��� ����
int get_dnode_count(List* list); // ����Ʈ�� ����
void createStack(stack* p); //���� �ʱ�ȭ
void push(stack* p, int element); // ���� push���� 
int pop(stack* p); // ���� pop����
int print(stack* p); // ���� top�� ���
void clearStack(stack* p); // ������ ����
int stackEmpty(stack* p); // ������ ����ִ���?
int stackSize(stack* p); // ���þȿ� ��� �ִ� ������ ����

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
			push(&stk,value);
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
DNode* create_dnode(int element) // ��� ������ �ʱ�ȭ
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
void insert_tail_dnode(List* list,int element) // �� �� ����
{
	DNode* newDNode = create_dnode(element); // ��� ����
	if (list->size == 0) // ����ִٸ�
	{
		list->head = newDNode;
		list->tail = newDNode;
		list->size += 1;
		return;
	}
	list->tail->next = newDNode; // �ǵڿ� �����ϰ� tail ����
	newDNode->prev = list->tail;
	list->tail = newDNode;
	list->size += 1;
}
int remove_tail_dnode(List* list) // �ǵ� ����
{
	int top;
	if (list->size == 0) // �����Ұ� ���ٸ� ����
		return -1;
	else if (list->size == 1) // 1����� �ǵڿ� �Ÿ� �����ְ� �ʱ�ȭ
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
		list->tail = list->tail->prev; // tail�� �����ϰ� 
		list->tail->next = NULL; //next�� NULL�� ����  
		free(deleteNode); //����
	}
	list->size -= 1;
	return top;
}
int get_dnode_count(List* list)
{
	return list->size; // size����
}
void remove_all_dnode(List* list) // ��� ��� ����
{
	if (list->size == 0) //���� �Ұ� ������
	{
		return;
	}
	DNode* deleteDNode, * curDNode;
	curDNode = list->head;
	while (curDNode) // ó������ �ϳ��� ��ȸ �ϸ鼭 �����Ѵ�
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
	List_init(&p->list); //���þ� ����Ʈ �ʱ�ȭ
}
void push(stack* p, int element)
{
	insert_tail_dnode(&p->list,element); //���ÿ����� �� �� ����
}
int pop(stack* p) 
{
	if (get_dnode_count(&p->list) == 0)
	{
		printf("stack underflow �߻�\n");
		return -1;
	}
	else
	{
		int top =remove_tail_dnode(&p->list); //�� �ڰ� ����
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
	remove_all_dnode(&p->list); // ����Ʈ�� ��簪 ����
	printf("stack is clear\n");
}
int stackEmpty(stack* p) // ����Ʈ�� �� �ִ��� Ȯ��
{
	if (get_dnode_count(&p->list) == 0)
		return 1;
	else
		return 0;
}
int stackSize(stack* p) //����Ʈ�� ������ Ȯ��
{
	return get_dnode_count(&p->list);
}