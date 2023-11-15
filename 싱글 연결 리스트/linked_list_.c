#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

enum menuType //열거형
{
	//열거형은 0에서 차례대로 1씩 증가되는 상수값을 취한다.
	//만약, 상수값을 지정한 경우 그 값부터 1씩 증가되는 값을 취한다.
	INSERT_FRONT = 1, INSERT_TAIL, INSERT_ASCEND_SORT, INSERT_FRONT_NTH,
	REMOVE_FRONT, REMOVE_ALL, REMOVE_FRONT_NTH, REMOVE_VALUE,
	TRAVERSAL, SEARCH, GET_NODE_COUNT, REVERSE, TERMINATE = 0
};

typedef struct node
{
	int value; //데이터
	struct node* next; //다음 노드의 주소 저장하는 포인터 //8바이트
}node;



typedef struct 
{
	node* head; // 맨앞 노드
	node* tail; // 맨뒤 노드
	int size; // 리스트의 전체 사이즈
}List;

void List_init(List* list); // 리스트 초기화 함수
void insert_front(List* list); // 맨앞 삽입
void traversal(List* list); // 리스트 순회
void remove_front(List* list); // 맨앞 제거
void remove_all(List* list); // 모든 리스트 제거
int get_node_count(List* list); // 리스트 갯수 함수
node* search_node(List* list, int target);  // 노드 검색
void insert_tail(List* list); // 맨뒤 삽입
int remove_node(List* list, int target); // 특정값 삭제
int remove_Nth_node(List* list, int N); // 앞에서 부터 N번째 제거
int insert_front_Nth(List* list, int N);  // 앞에서부터 N번째에 삽입
void insert_ascend_sort(); 
void reverse_node(List* list); //노드 역순 연결

int main()
{
	int choice, value;
	List mylist;
	List_init(&mylist);
	while (1)
	{
		printf("\n\n\t *** 단일 연결 리스트(Singly Linked List) ***\n\n");
		printf(" 1. 노드 삽입(맨 앞)\n");
		printf(" 2. 노드 삽입(맨 뒤)\n");
		printf(" 3. 노드 삽입(오름차순 정렬)\n");
		printf(" 4. 노드 삽입(앞에서부터 N번째)\n");
		printf("------------------------------\n");
		printf(" 5. 노드 삭제(맨 앞)\n");
		printf(" 6. 노드 삭제(전체 노드)\n");
		printf(" 7. 노드 삭제(앞에서부터 N번째)\n");
		printf(" 8. 노드 삭제(특정 값)\n");
		printf("------------------------------\n");
		printf(" 9. 노드 순회 | 단일 연결 리스트 출력\n");
		printf("10. 노드 검색\n");
		printf("11. 노드 개수 구하기\n");
		printf("12. 노드 역순 연결\n");
		printf(" 0. 프로그램 종료\n");
		printf("------------------------------\n");
		printf("\n메뉴 선택 : [  ]\b\b\b");
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
			printf("\n\n*** N번째 노드 삽입 ***\n");
			printf("\n\n몇 번째에 노드를 삽입하시겠습니까? ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (insert_front_Nth(&mylist, value)) //삽입 성공 1 리턴, 삽입 실패 시 0리턴
				printf("\n\n\t\t%d를(을) 삽입 성공 했습니다.\n", value);
			else
				printf("\n\n\t\t%d를(을) 삽입하지 못했습니다.\n", value);
			break;
		case REMOVE_FRONT:
			remove_front(&mylist);
			break;
		case REMOVE_ALL:
			remove_all(&mylist);
			break;
		case REMOVE_FRONT_NTH:
			system("cls");
			printf("\n\n*** N번째 노드 삭제 ***\n");
			printf("\n\n몇 번째 노드를 삭제하시겠습니까? ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (remove_Nth_node(&mylist, value)) //삭제 성공 1 리턴, 삭제 실패 시 0리턴
				printf("\n\n\t\t%d번째 노드를 삭제했습니다.\n", value);
			else
				printf("\n\n\t\t%d번째 노드를 삭제하지 못했습니다.\n", value);
			break;
		case REMOVE_VALUE:
			system("cls");
			printf("\n\n*** 특정 값 노드 삭제 ***\n");
			printf("\n\n삭제할 정수 입력 : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (remove_node(&mylist,value)) //삭제 성공 1 리턴, 삭제 실패 시 0리턴
				printf("\n\n\t\t%d를(을) 삭제했습니다.\n", value);
			else
				printf("\n\n\t\t%d를(을) 삭제하지 못했습니다.\n", value);
			break;
		case TRAVERSAL:
			traversal(&mylist);
			break;
		case SEARCH:
			system("cls");
			printf("\n\n*** 노드 검색 ***\n");
			printf("\n\n검색할 정수 입력 : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			//검색한 값이 존재하면 검색 노드의 주소를 리턴, 없으면 NULL을 리턴
			if (search_node(&mylist, value) != NULL)
				printf("\n\n\t\t검색한 정수 %d는(은) 존재 합니다.\n", value);
			else
				printf("\n\n\t\t검색한 정수 %d는(은) 존재하지 않습니다.\n", value);

			break;
		case GET_NODE_COUNT:
			printf("\n\n\t\t생성된 노드의 개수는 %d개 입니다.\n", get_node_count(&mylist));
			break;
		case REVERSE:
			reverse_node(&mylist);
			break;
		case TERMINATE:
			remove_all(&mylist);
			exit(0); //프로그램 강제 종료			
		}

		printf("\n\n\t\t");
		system("pause"); //일시대기
		system("cls"); //화면지우기
	}

	return 0;
}
void List_init(List* list) // 노드 초기화
{
	list->head = NULL; 
	list->tail = NULL;
	list->size = 0;
}
void insert_front(List* list)
{
	node* newNode = (node*)malloc(sizeof(node)); //새로운 노드 생성
	newNode->next = NULL; // 노드 초기화
	printf("맨 앞에 삽입할 값을 입력해주세요 : ");
	scanf("%d", &newNode->value); // 노드에 들어갈 값 입력
	while (getchar() != '\n');
	if ((list->size) == 0) // 리스트가 비어있다면
	{
		list->head = newNode;
		list->tail = newNode;

	}
	else //비어 있지 않다면
	{
		newNode->next = list->head;
		list->head = newNode;
	}
	list->size += 1; // 리스트의 개수 증가
	printf("맨앞에 값 %d이 삽입되었습니다. \n", newNode->value);
}
void insert_tail(List* list)
{
	node* newNode = (node*)malloc(sizeof(node)); // 새로운 노드 생성
	newNode->next = NULL; // 노드 초기화
	printf("맨 뒤에 삽입할 값을 입력해주세요 : ");
	scanf("%d", &newNode->value); // 노드에 들어갈 값 입력
	while (getchar() != '\n');
	if (list->size == 0) // 리스트가 비어 있다면
	{
		list->head = list->tail = newNode;

	}
	else
	{
		list->tail->next = newNode;
		list->tail = newNode;
	}
	list->size += 1; // 노드의 개수 증가
	printf("맨뒤에 값 %d이 삽입되었습니다. \n", newNode->value);
}
node* search_node(List* list, int target)
{
	if (list->size == 0) //리스트가 비어 있다면
		return NULL;

	node* curNode = list->head;
	while (curNode) 
	{
		if (curNode->value == target) //값으 찾으면 
		{
			return curNode;
		}
		else
		{
			curNode = curNode->next; //다음 노드로 이동
		}
	}
	return NULL; //전체 못찾으면
}
int insert_front_Nth(List* list, int N) 
{

	int i = 1;
	if (N<1 || N>list->size + 1) // N이 제대로 입력 되었는지?
	{
		printf("N의 자리에 삽입할수 없습니다.\n");
		printf("1부터 %d까지의 자연수를 입력해주세요.", list->size + 1);
		return 0;
	}
	node* newNode = (node*)malloc(sizeof(node)); // 새로운 노드 생성
	printf("%d 위치에 넣을 값을 입력해 주세요 : ",N);

	scanf("%d", &newNode->value); // 생성된 노드에 넣을 값 입력
	while (getchar() != '\n');

	if (N == 1) // 맨앞에 삽입한다면
	{
		if (list->size == 0)
		{
			list->tail = newNode;
		}
		newNode->next = list->head;
		list->head = newNode;
	}
	else if (N == list->size + 1) //맨 뒤에 삽입한다면
	{
		list->tail->next = newNode;
		newNode->next = NULL;
		list->tail = newNode;
	}
	else // 중간에 삽입한다면
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
	list->size += 1; // 리스트의 개수 증가
	return 1;
}
void traversal(List* list) // 순회
{
	if (list->size == 0) //리스트가 비어 있다면
	{
		printf("순회할 노드가 없습니다\n");
		return 0;
	}
	node* curNode = list->head;
	int i = 1;
	while (curNode) // 맨앞부터 하나씩 이동하며 출력
	{
		printf("%d번째 노드 값은 %d입니다.\n", i, curNode->value);
		curNode = curNode->next;
		i++;
	}
	printf("리스트 순회를 끝냈습니다.\n");
}
void remove_front(List* list)
{
	if (list->size == 0) // 리스트가 비어 있다면
	{
		printf("삭제할 노드가 없습니다\n");
		return;
	}
	if (list->size == 1) // 리스트가 1개라면
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else // 리스트가 여러개라면
	{
		node* delNode = list->head;
		list->head = list->head->next;
		free(delNode);
	}
	list->size -= 1; //리스트 개수 감소
	printf("맨 앞 노드를 성공적으로 삭제했습니다.");

}
int get_node_count(List* list) 
{
	return list->size; //리스트의 사이즈값 반환
}
void remove_all(List* list) // 모든 노드 삭제
{
	if (list->size == 0) // 리스트가 비어있다면
	{
		return;
	}
	node* curNode = list->head; 
	node* delNode = curNode;
	while (curNode) // 앞에서 부터 하나씩 삭제
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
	if (list->size == 0) // 리스트가 비어있다면
	{
		return 0;
	}
	if (N<1 || N>list->size) // 잘못된 N값을 입력받는다면
	{
		printf("1부터 %d까지 입력해주세요\n", list->size);
		return 0;
	}
	if (N == 1) // 맨앞에 것을 삭제하라면
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
		while (i < N) // 삭제할 노드 찾기
		{
			preNode = delNode;
			delNode = delNode->next;
			i++;
		}
		if (N == list->size) // 맨뒤에 것을 삭제하라면
		{
			list->tail = preNode;
		}
		preNode->next = delNode->next;
		free(delNode);
	}
	list->size -= 1;
	return 1;

}
int remove_node(List* list, int target) // 특정값 삭제
{
	if (list->size == 0) //리스트가 비어있으면 함수 종료
	{
		return 0;
	}

	node* curNode = list->head;
	if (curNode->value == target) // 맨앞에 삭제할 값이 있다면
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
		while (curNode) //삭제할 값 찾기
		{
			if (curNode->value == target) 
			{
				if (curNode == list->tail) // 맨뒤에 삭제할 값이 있다면
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
	if (list->size < 2) //노드의 개수가 2미만이면 종료
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

	while (curNode) // 노드를 하나씩 이동하며 reverse
	{
		curNode->next = preNode;
		preNode = curNode;
		curNode = nextNode;
		if(nextNode)
			nextNode = nextNode->next;
	}
	node* temp = list->head; // head와 tail swap
	list->head = list->tail;
	list->tail = temp;
}