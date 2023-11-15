#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

enum menuType //������
{
	//�������� 0���� ���ʴ�� 1�� �����Ǵ� ������� ���Ѵ�.
	//����, ������� ������ ��� �� ������ 1�� �����Ǵ� ���� ���Ѵ�.
	INSERT_FRONT = 1, INSERT_TAIL, INSERT_ASCEND_SORT, INSERT_FRONT_NTH,
	REMOVE_FRONT, REMOVE_ALL, REMOVE_FRONT_NTH, REMOVE_VALUE,
	TRAVERSAL, SEARCH, GET_NODE_COUNT, REVERSE, TERMINATE = 0
};

typedef struct node
{
	int value; //������
	struct node* next; //���� ����� �ּ� �����ϴ� ������ //8����Ʈ
}node;



typedef struct 
{
	node* head; // �Ǿ� ���
	node* tail; // �ǵ� ���
	int size; // ����Ʈ�� ��ü ������
}List;

void List_init(List* list); // ����Ʈ �ʱ�ȭ �Լ�
void insert_front(List* list); // �Ǿ� ����
void traversal(List* list); // ����Ʈ ��ȸ
void remove_front(List* list); // �Ǿ� ����
void remove_all(List* list); // ��� ����Ʈ ����
int get_node_count(List* list); // ����Ʈ ���� �Լ�
node* search_node(List* list, int target);  // ��� �˻�
void insert_tail(List* list); // �ǵ� ����
int remove_node(List* list, int target); // Ư���� ����
int remove_Nth_node(List* list, int N); // �տ��� ���� N��° ����
int insert_front_Nth(List* list, int N);  // �տ������� N��°�� ����
void insert_ascend_sort(); 
void reverse_node(List* list); //��� ���� ����

int main()
{
	int choice, value;
	List mylist;
	List_init(&mylist);
	while (1)
	{
		printf("\n\n\t *** ���� ���� ����Ʈ(Singly Linked List) ***\n\n");
		printf(" 1. ��� ����(�� ��)\n");
		printf(" 2. ��� ����(�� ��)\n");
		printf(" 3. ��� ����(�������� ����)\n");
		printf(" 4. ��� ����(�տ������� N��°)\n");
		printf("------------------------------\n");
		printf(" 5. ��� ����(�� ��)\n");
		printf(" 6. ��� ����(��ü ���)\n");
		printf(" 7. ��� ����(�տ������� N��°)\n");
		printf(" 8. ��� ����(Ư�� ��)\n");
		printf("------------------------------\n");
		printf(" 9. ��� ��ȸ | ���� ���� ����Ʈ ���\n");
		printf("10. ��� �˻�\n");
		printf("11. ��� ���� ���ϱ�\n");
		printf("12. ��� ���� ����\n");
		printf(" 0. ���α׷� ����\n");
		printf("------------------------------\n");
		printf("\n�޴� ���� : [  ]\b\b\b");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case INSERT_FRONT:
			insert_front(&mylist);
			break;
		case INSERT_TAIL:
			insert_tail(&mylist);
			break;
			//case INSERT_ASCEND_SORT:
			//	insert_ascend_sort();
			//	break;
		case INSERT_FRONT_NTH:
			system("cls");
			printf("\n\n*** N��° ��� ���� ***\n");
			printf("\n\n�� ��°�� ��带 �����Ͻðڽ��ϱ�? ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (insert_front_Nth(&mylist, value)) //���� ���� 1 ����, ���� ���� �� 0����
				printf("\n\n\t\t%d��(��) ���� ���� �߽��ϴ�.\n", value);
			else
				printf("\n\n\t\t%d��(��) �������� ���߽��ϴ�.\n", value);
			break;
		case REMOVE_FRONT:
			remove_front(&mylist);
			break;
		case REMOVE_ALL:
			remove_all(&mylist);
			break;
		case REMOVE_FRONT_NTH:
			system("cls");
			printf("\n\n*** N��° ��� ���� ***\n");
			printf("\n\n�� ��° ��带 �����Ͻðڽ��ϱ�? ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (remove_Nth_node(&mylist, value)) //���� ���� 1 ����, ���� ���� �� 0����
				printf("\n\n\t\t%d��° ��带 �����߽��ϴ�.\n", value);
			else
				printf("\n\n\t\t%d��° ��带 �������� ���߽��ϴ�.\n", value);
			break;
		case REMOVE_VALUE:
			system("cls");
			printf("\n\n*** Ư�� �� ��� ���� ***\n");
			printf("\n\n������ ���� �Է� : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (remove_node(&mylist,value)) //���� ���� 1 ����, ���� ���� �� 0����
				printf("\n\n\t\t%d��(��) �����߽��ϴ�.\n", value);
			else
				printf("\n\n\t\t%d��(��) �������� ���߽��ϴ�.\n", value);
			break;
		case TRAVERSAL:
			traversal(&mylist);
			break;
		case SEARCH:
			system("cls");
			printf("\n\n*** ��� �˻� ***\n");
			printf("\n\n�˻��� ���� �Է� : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			//�˻��� ���� �����ϸ� �˻� ����� �ּҸ� ����, ������ NULL�� ����
			if (search_node(&mylist, value) != NULL)
				printf("\n\n\t\t�˻��� ���� %d��(��) ���� �մϴ�.\n", value);
			else
				printf("\n\n\t\t�˻��� ���� %d��(��) �������� �ʽ��ϴ�.\n", value);

			break;
		case GET_NODE_COUNT:
			printf("\n\n\t\t������ ����� ������ %d�� �Դϴ�.\n", get_node_count(&mylist));
			break;
		case REVERSE:
			reverse_node(&mylist);
			break;
		case TERMINATE:
			remove_all(&mylist);
			exit(0); //���α׷� ���� ����			
		}

		printf("\n\n\t\t");
		system("pause"); //�Ͻô��
		system("cls"); //ȭ�������
	}

	return 0;
}
void List_init(List* list) // ��� �ʱ�ȭ
{
	list->head = NULL; 
	list->tail = NULL;
	list->size = 0;
}
void insert_front(List* list)
{
	node* newNode = (node*)malloc(sizeof(node)); //���ο� ��� ����
	newNode->next = NULL; // ��� �ʱ�ȭ
	printf("�� �տ� ������ ���� �Է����ּ��� : ");
	scanf("%d", &newNode->value); // ��忡 �� �� �Է�
	while (getchar() != '\n');
	if ((list->size) == 0) // ����Ʈ�� ����ִٸ�
	{
		list->head = newNode;
		list->tail = newNode;

	}
	else //��� ���� �ʴٸ�
	{
		newNode->next = list->head;
		list->head = newNode;
	}
	list->size += 1; // ����Ʈ�� ���� ����
	printf("�Ǿտ� �� %d�� ���ԵǾ����ϴ�. \n", newNode->value);
}
void insert_tail(List* list)
{
	node* newNode = (node*)malloc(sizeof(node)); // ���ο� ��� ����
	newNode->next = NULL; // ��� �ʱ�ȭ
	printf("�� �ڿ� ������ ���� �Է����ּ��� : ");
	scanf("%d", &newNode->value); // ��忡 �� �� �Է�
	while (getchar() != '\n');
	if (list->size == 0) // ����Ʈ�� ��� �ִٸ�
	{
		list->head = list->tail = newNode;

	}
	else
	{
		list->tail->next = newNode;
		list->tail = newNode;
	}
	list->size += 1; // ����� ���� ����
	printf("�ǵڿ� �� %d�� ���ԵǾ����ϴ�. \n", newNode->value);
}
node* search_node(List* list, int target)
{
	if (list->size == 0) //����Ʈ�� ��� �ִٸ�
		return NULL;

	node* curNode = list->head;
	while (curNode) 
	{
		if (curNode->value == target) //���� ã���� 
		{
			return curNode;
		}
		else
		{
			curNode = curNode->next; //���� ���� �̵�
		}
	}
	return NULL; //��ü ��ã����
}
int insert_front_Nth(List* list, int N) 
{

	int i = 1;
	if (N<1 || N>list->size + 1) // N�� ����� �Է� �Ǿ�����?
	{
		printf("N�� �ڸ��� �����Ҽ� �����ϴ�.\n");
		printf("1���� %d������ �ڿ����� �Է����ּ���.", list->size + 1);
		return 0;
	}
	node* newNode = (node*)malloc(sizeof(node)); // ���ο� ��� ����
	printf("%d ��ġ�� ���� ���� �Է��� �ּ��� : ",N);

	scanf("%d", &newNode->value); // ������ ��忡 ���� �� �Է�
	while (getchar() != '\n');

	if (N == 1) // �Ǿտ� �����Ѵٸ�
	{
		if (list->size == 0)
		{
			list->tail = newNode;
		}
		newNode->next = list->head;
		list->head = newNode;
	}
	else if (N == list->size + 1) //�� �ڿ� �����Ѵٸ�
	{
		list->tail->next = newNode;
		newNode->next = NULL;
		list->tail = newNode;
	}
	else // �߰��� �����Ѵٸ�
	{
		node* preNode;
		node* curNode;
		preNode = list->head;
		curNode = list->head->next;
		i = 2;
		while (i < N)
		{
			preNode = curNode;
			curNode = curNode->next;
			i++;
		}
		preNode->next = newNode;
		newNode->next = curNode;
	}
	list->size += 1; // ����Ʈ�� ���� ����
	return 1;
}
void traversal(List* list) // ��ȸ
{
	if (list->size == 0) //����Ʈ�� ��� �ִٸ�
	{
		printf("��ȸ�� ��尡 �����ϴ�\n");
		return 0;
	}
	node* curNode = list->head;
	int i = 1;
	while (curNode) // �Ǿպ��� �ϳ��� �̵��ϸ� ���
	{
		printf("%d��° ��� ���� %d�Դϴ�.\n", i, curNode->value);
		curNode = curNode->next;
		i++;
	}
	printf("����Ʈ ��ȸ�� ���½��ϴ�.\n");
}
void remove_front(List* list)
{
	if (list->size == 0) // ����Ʈ�� ��� �ִٸ�
	{
		printf("������ ��尡 �����ϴ�\n");
		return;
	}
	if (list->size == 1) // ����Ʈ�� 1�����
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else // ����Ʈ�� ���������
	{
		node* delNode = list->head;
		list->head = list->head->next;
		free(delNode);
	}
	list->size -= 1; //����Ʈ ���� ����
	printf("�� �� ��带 ���������� �����߽��ϴ�.");

}
int get_node_count(List* list) 
{
	return list->size; //����Ʈ�� ����� ��ȯ
}
void remove_all(List* list) // ��� ��� ����
{
	if (list->size == 0) // ����Ʈ�� ����ִٸ�
	{
		return;
	}
	node* curNode = list->head; 
	node* delNode = curNode;
	while (curNode) // �տ��� ���� �ϳ��� ����
	{
		curNode = curNode->next;
		free(delNode);
		delNode = curNode;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}
int remove_Nth_node(List* list, int N) 
{
	if (list->size == 0) // ����Ʈ�� ����ִٸ�
	{
		return 0;
	}
	if (N<1 || N>list->size) // �߸��� N���� �Է¹޴´ٸ�
	{
		printf("1���� %d���� �Է����ּ���\n", list->size);
		return 0;
	}
	if (N == 1) // �Ǿտ� ���� �����϶��
	{
		if (list->size == 1)
		{
			list->tail = NULL;
		}
		node* delNode = list->head;
		list->head = list->head->next;
		free(delNode);
	}
	else
	{
		node* preNode = list->head;
		node* delNode = list->head->next;
		int i = 2;
		while (i < N) // ������ ��� ã��
		{
			preNode = delNode;
			delNode = delNode->next;
			i++;
		}
		if (N == list->size) // �ǵڿ� ���� �����϶��
		{
			list->tail = preNode;
		}
		preNode->next = delNode->next;
		free(delNode);
	}
	list->size -= 1;
	return 1;

}
int remove_node(List* list, int target) // Ư���� ����
{
	if (list->size == 0) //����Ʈ�� ��������� �Լ� ����
	{
		return 0;
	}

	node* curNode = list->head;
	if (curNode->value == target) // �Ǿտ� ������ ���� �ִٸ�
	{
		if (list->size == 1)
		{
			list->tail = NULL;
		}
		list->head = curNode->next;
		free(curNode);
		list->size -= 1;
		return 1;
	}
	else {
		node* preNode = list->head;
		curNode = curNode->next;
		while (curNode) //������ �� ã��
		{
			if (curNode->value == target) 
			{
				if (curNode == list->tail) // �ǵڿ� ������ ���� �ִٸ�
				{
					list->tail = preNode;
				}
				preNode->next = curNode->next;
				free(curNode);
				list->size -= 1;
				return 1;
			}
			preNode = curNode;
			curNode = curNode->next;
		}
		return 0;
	}

}
void reverse_node(List *list)
{
	if (list->size < 2) //����� ������ 2�̸��̸� ����
	{
		return;
	}
	node* preNode = NULL;
	node* curNode = list->head;
	node* nextNode = curNode->next;
	curNode->next = preNode;
	preNode = curNode;
	curNode = nextNode;
	nextNode = nextNode->next;

	while (curNode) // ��带 �ϳ��� �̵��ϸ� reverse
	{
		curNode->next = preNode;
		preNode = curNode;
		curNode = nextNode;
		if(nextNode)
			nextNode = nextNode->next;
	}
	node* temp = list->head; // head�� tail swap
	list->head = list->tail;
	list->tail = temp;
}