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




DNode* create_dnode(); //���� �޸� �Ҵ� �� ���� �޸��� �ּ� ����
void List_init(List* list); //����Ʈ �ʱ�ȭ
void insert_front_dnode(List* list); // �� �� ����
void insert_tail_dnode(List* list); // �� �� ����
void traversal_dnode(List* list); // �տ��� ���� ���ʷ� ��ȸ
void remove_front_dnode(List* list); // �Ǿ� ����
void remove_tail_dnode(List* list); // �ǵ� ����
int get_dnode_count(List* list); // ����Ʈ�� ����
int insert_front_Nth_dnode(List *list,int N); // N��° ����
int remove_front_Nth_dnode(List* list,int N); // N��° ��� ����
void reverse_dnode(List *list); // ���� ����
DNode* search(List* list, int N); // ��� ã��
int remove_search(List* list, int N); // Ư���� ����
void remove_all_dnode(List *list); // ��� ��� ����

int main()
{
	int choice, value;
	List myList;
	List_init(&myList);
	while (1)
	{
		printf("\n\n\t *** ���� ���� ����Ʈ(Doubly Linked List) ***\n\n");
		printf(" 1. ��� ����(�� ��)\n");
		printf(" 2. ��� ����(�� ��)\n");
		printf(" 3. ��� ����(�������� ����)\n");
		printf(" 4. ��� ����(�տ������� N��°)\n");
		printf("------------------------------\n");
		printf(" 5. ��� ����(�� ��)\n");
		printf(" 6. ��� ����(�� ��)\n");
		printf(" 7. ��� ����(��ü ���)\n");
		printf(" 8. ��� ����(�տ������� N��°)\n");
		printf(" 9. ��� ����(Ư�� ��)\n");
		printf("------------------------------\n");
		printf("10. ��� ��ȸ | ���� ���� ����Ʈ ���\n");
		printf("11. ��� �˻�\n");
		printf("12. ��� ���� ���ϱ�\n");
		printf("13. ��� ���� ����\n");
		printf(" 0. ���α׷� ����\n");
		printf("------------------------------\n");
		printf("\n�޴� ���� : [  ]\b\b\b");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case INSERT_FRONT:
			insert_front_dnode(&myList);
			break;
		case INSERT_TAIL:
			insert_tail_dnode(&myList);
			break;
		//case INSERT_ASCEND_SORT:
			//insert_ascend_sort_dnode();
			//break;
		case INSERT_FRONT_NTH:
			system("cls");
			printf("\n\n*** N��° ��� ���� ***\n");
			printf("\n\n�� ��°�� ��带 �����Ͻðڽ��ϱ�? ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (insert_front_Nth_dnode(&myList,value)) //���� ���� 1 ����, ���� ���� �� 0����
				printf("\n\n\t\t%d��°�� ���� ���� �߽��ϴ�.\n", value);
			else
				printf("\n\n\t\t%d��° �������� ���߽��ϴ�.\n", value);
			break;
		case REMOVE_FRONT:
			remove_front_dnode(&myList);
			break;
		case REMOVE_TAIL:
			remove_tail_dnode(&myList);
			break;
		case REMOVE_ALL:
			remove_all_dnode(&myList);
			break;
		case REMOVE_FRONT_NTH:
			system("cls");
			printf("\n\n*** N��° ��� ���� ***\n");
			printf("\n\n�� ��° ��带 �����Ͻðڽ��ϱ�? ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (remove_front_Nth_dnode(&myList, value)) //���� ���� 1 ����, ���� ���� �� 0����
				printf("\n\n\t\t%d��° ��带 �����߽��ϴ�.\n", value);
			else
				printf("\n\n\t\t%d��° ��带 �������� ���߽��ϴ�.\n", value);
			break;
		case REMOVE_VALUE:
			system("cls");
			printf("\n\n������ ���� �Է��� �ּ��� : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (remove_search(&myList,value)) //���� ���� 1 ����, ���� ���� �� 0����
				printf("\n\n\t\t%d���� ��带 �����߽��ϴ�.\n", value);
			else
				printf("\n\n\t\t%d���� ��带 �������� ���߽��ϴ�.\n", value);
			break;
		case TRAVERSAL:
			traversal_dnode(&myList);
			break;
		case SEARCH:
			printf("\n\n ã�� ���� �Է��� �ּ��� : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (search(&myList, value))
				printf("%d ���� ����Ʈ�� �����մϴ�\n", value);
			else
				printf("%d ���� ����Ʈ�� �������� �ʽ��ϴ�.\n", value);
			break;
		case GET_NODE_COUNT:
			printf("\n\n\t\t������ ����� ������ %d�� �Դϴ�.\n", get_dnode_count(&myList));
			break;
		case REVERSE:
			reverse_dnode(&myList);
			break;
		case TERMINATE:
			remove_all_dnode(&myList);
			exit(0); //���α׷� ���� ����			
		}

		printf("\n\n\t\t");
		system("pause"); //�Ͻô��
		system("cls"); //ȭ�������
	}

	return 0;
}
DNode* create_dnode() // ��� ������ �ʱ�ȭ
{
	DNode *newDNode = (DNode*)malloc(sizeof(DNode));
	newDNode->next = NULL;
	newDNode->prev = NULL;
	printf("����Ʈ�� ���� �����͸� �Է��� �ּ���. : ");
	scanf("%d", &newDNode->value);
	while (getchar() != '\n');

	return newDNode;
}
void remove_all_dnode(List* list) // ��� ��� ����
{
	if (list->size == 0) //���� �Ұ� ������
	{
		return;
	}
	DNode* deleteDNode, *curDNode; 
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

void List_init(List* list)  // ����Ʈ �ʱ�ȭ
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}
void insert_front_dnode(List* list) // �Ǿ� ����
{
	DNode* newDNode = create_dnode(); // ��� ����
	if (list->size == 0) //����ִٸ�
	{
		list->head = newDNode;
		list->tail = newDNode;
		list->size += 1;
		return;
	}
	newDNode->next = list->head; // �Ǿտ� �����ϰ�  head����
	list->head->prev = newDNode;
	list->head = newDNode;
	list->size += 1;
}
void insert_tail_dnode(List* list) // �� �� ����
{
	DNode* newDNode = create_dnode(); // ��� ����
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
void traversal_dnode(List* list) //��ȸ
{
	if (list->size == 0) //0���� ��ȸ ���Ѵ�.
	{
		return;
	}
	DNode* curDNode = list->head; // �Ǿպ���
	int i = 1;
	while (curDNode) // �ϳ��� ��ȸ �Ѵ�.
	{
		printf("%d��° ���� %d�Դϴ�\n", i, curDNode->value);
		curDNode = curDNode->next;
		i++;
	}
}
void remove_front_dnode(List* list) // �Ǿ� ����
{
	if (list->size == 0) // �����Ұ� ���ٸ� ����
		return;
	else if (list->size == 1) // 1�����
	{
		free(list->head); //ó���� �����ְ� �ʱ�ȭ
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		DNode* deleteNode = list->head; // �Ǿտ� ����
		list->head = list->head->next; // head�� ����
		list->head->prev = NULL; // �ڿ� ��� null�� �־��ش�.
		free(deleteNode);
	}
	list->size -= 1; 
}
int get_dnode_count(List* list)
{
	return list->size; // size����
}
void remove_tail_dnode(List* list) // �ǵ� ����
{
	if (list->size == 0) // �����Ұ� ���ٸ� ����
		return;
	else if (list->size == 1) // 1����� �ǵڿ� �Ÿ� �����ְ� �ʱ�ȭ
	{
		free(list->tail);
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		DNode* deleteNode = list->tail; 
		list->tail = list->tail->prev; // tail�� �����ϰ� 
		list->tail->next = NULL; //next�� NULL�� ����  
		free(deleteNode); //����
	}
	list->size -= 1;
}
int insert_front_Nth_dnode(List* list, int N) // N��° ����
{
	if (N<1 || N>list->size + 1) // �����Է��� �߸��ϸ� ����
		return 0;

	if (N == 1) //�Ǿտ� �����Ѵٸ�
	{
		insert_front_dnode(list);
	}
	else if (N==list->size+1) // �ǵڿ� �����Ѵٸ�
	{
		insert_tail_dnode(list);
	}
	else //�߰��� �����Ѵٸ�
	{
		int i = 2;
		DNode* curNode = list->head->next; // 2��° ���� ��ȸ
		while (i < N) //N��°������ ã�ư���
		{
			curNode = curNode->next; 
			i++;
		}
		DNode* newNode = create_dnode(); // ������
		newNode->next = curNode; // �߰��� �����Ѵ�.
		newNode->prev = curNode->prev;
		newNode->prev->next = newNode;
		curNode->prev = newNode;
		list->size += 1;
	}
	return 1; //���Լ���
}
int remove_front_Nth_dnode(List* list, int N)
{
	if (N<1 || N>list->size) // ���� �Է��� �߸��ϸ� ����
		return 0;
	if (N == 1) //�Ǿ��� �����Ѵٸ�
	{
		remove_front_dnode(list);
	}
	else if (N == list->size) // �ǵڸ� �����Ѵٸ�
	{
		remove_tail_dnode(list);
	}
	else //�߰��� �ִ°� �����Ѵٸ�
	{
		int i = 2;
		DNode* curNode = list->head->next; //2��° ���� ��ȸ
		while (i < N) //N��°���� �̵�
		{
			curNode = curNode->next;
			i++;
		}
		curNode->next->prev = curNode->prev; // ���� ������ ����
		curNode->prev->next = curNode->next;
		free(curNode); //����
		list->size -= 1;
	}
	return 1;
}
void reverse_dnode(List* list)
{
	if (list->size < 2) // �Ųٷ� ����
		return;
	DNode* curNode = list->head;
	while (curNode) //prev�� next�� swap�ϸ鼭 �̵�
	{
		DNode* temp;
		temp = curNode->prev;
		curNode->prev = curNode->next;
		curNode->next = temp;
		curNode = curNode->prev;
	}
	DNode* temp = list->head; //head�� ���� swap
	list->head = list->tail;
	list->tail = temp;
}
DNode* search(List* list, int N) // Ư���� ã��
{
	if (list->size == 0) // ã�� �� ������ NULL
		return NULL;
	DNode* curNode = list->head; // ó������ ��ȸ�ϸ鼭 ã�ư���.
	while (curNode)
	{
		if (curNode->value == N) // ã���� �����Ͱ� ����
			return curNode;
		curNode = curNode->next;
	}
	return curNode;
}
int remove_search(List* list, int N) //Ư���� ����
{
	if (list->size == 0) //����Ʈ�� ��� ������ ����
	{
		return 0;
	}
	int i = 1;
	DNode* curNode = list->head;
	while (curNode) // �տ��� ���� ã�ư���.
	{
		if (curNode->value == N)
		{
			return remove_front_Nth_dnode(list, i); //i��°�� ã���� i��° ��ġ ���� �����Ѵ�.
		}
		curNode = curNode->next;
		i++;
	}
	return 0; // Ư������ ã�� ���� ���� ����
}