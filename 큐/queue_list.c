#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

enum menuType //������
{
	//�������� 0���� ���ʴ�� 1�� �����Ǵ� ������� ���Ѵ�.
	//����, ������� ������ ��� �� ������ 1�� �����Ǵ� ���� ���Ѵ�.
	INSERT_FRONT = 1, INSERT_TAIL, INSERT_ASCEND_SORT, INSERT_FRONT_NTH,
	REMOVE_FRONT, REMOVE_TAIL, REMOVE_ALL, REMOVE_FRONT_NTH, REMOVE_VALUE,
	TRAVERSAL, SEARCH, GET_NODE_COUNT, REVERSE, TERMINATE = 0
};

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




DNode* create_dnode(int value); //���� �޸� �Ҵ� �� ���� �޸��� �ּ� ����
void List_init(List* list); //����Ʈ �ʱ�ȭ
void insert_tail_dnode(List* list,int value); // �� �� ����
void traversal_dnode(List* list); // �տ��� ���� ���ʷ� ��ȸ
int remove_front_dnode(List* list); // �Ǿ� ����
void remove_all_dnode(List* list); // ��� ��� ����
typedef struct _queue
{
	List list;
}queue;


void createQueue(queue* pQue);
void push(queue* pQue, int value);
int pop(queue* pQue);
int print(queue* pQue);
void clear(queue* pQue);//ť�� ���� á�ٸ� �ִٸ� 1, �ƴ϶�� 0����
int isEmpty(queue* pQue); //ť�� ��� �ִٸ� 1, �ƴ϶�� 0����
int size(queue* pQue);
void display(queue* pQue);
int main()
{
	queue que; //����ü ���� ����(24����Ʈ)
	int choice, count, value;
	createQueue(&que);

	while (1)
	{
		system("cls");
		display(&que);
		printf("\n\n\t\t****  ����Ʈ�� �̿��� ť ***\n\n");
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
void List_init(List* list)  // ����Ʈ �ʱ�ȭ
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}
DNode* create_dnode(int value) // ��� ������ �ʱ�ȭ
{
	DNode* newDNode = (DNode*)malloc(sizeof(DNode));
	newDNode->next = NULL;
	newDNode->prev = NULL;
	newDNode->value = value;

	return newDNode;
}
void insert_tail_dnode(List* list,int value) // �� �� ����
{
	DNode* newDNode = create_dnode(value); // ��� ����
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
int remove_front_dnode(List* list) // �Ǿ� ����
{
	int popData;
	if (list->size == 0)
	{
		printf("queue is empty\n");
		return -1;
	}
	else if (list->size == 1) // 1�����
	{
		popData = list->head->value;
		free(list->head); //ó���� �����ְ� �ʱ�ȭ
		list->head = NULL;
		list->tail = NULL;
		list->size -= 1;
		printf("pop data is %d\n", popData);
		return popData;
	}
	else
	{
		popData = list->head->value;
		DNode* deleteNode = list->head; // �Ǿտ� ����
		list->head = list->head->next; // head�� ����
		list->head->prev = NULL; // �ڿ� ��� null�� �־��ش�.
		free(deleteNode);
		list->size -= 1;
		printf("pop data is %d\n", popData);
		return popData;
	}
	
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
void traversal_dnode(List* list) //��ȸ
{
	if (list->size == 0) //0���� ��ȸ ���Ѵ�.
	{
		return;
	}
	DNode* curDNode = list->head; // �Ǿպ���
	
	while (curDNode) // �ϳ��� ��ȸ �Ѵ�.
	{
		printf("%d ", curDNode->value);
		curDNode = curDNode->next;
	}
	printf("\n");
}
void createQueue(queue* pQue)
{
	List_init(&pQue->list); //����Ʈ �ʱ�ȭ
}
void push(queue* pQue, int value)
{
	insert_tail_dnode(&pQue->list, value); // ���� ����Ʈ �ǵڿ� ����
}

int pop(queue* pQue)
{
	if (pQue->list.size == 0)
	{
		printf("queue is empty\n");
		return -1;
	}
	return remove_front_dnode(&pQue->list); // �� �հ� ����
}

int print(queue* pQue)
{
	if (pQue->list.size == 0)
	{
		printf("queue is empty\n");
		return -1;
	}
	printf("queue front is %d", pQue->list.head->value);
	return pQue->list.head->value; // �� �հ� ���
}
void clear(queue* pQue)
{
	remove_all_dnode(&pQue->list); // ��� ����Ʈ �� ����
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