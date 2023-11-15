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




DNode* create_dnode(); //동적 메모리 할당 후 동적 메모리의 주소 리턴
void List_init(List* list); //리스트 초기화
void insert_front_dnode(List* list); // 맨 앞 삽입
void insert_tail_dnode(List* list); // 맨 뒤 삽입
void traversal_dnode(List* list); // 앞에서 부터 차례로 순회
void remove_front_dnode(List* list); // 맨앞 삭제
void remove_tail_dnode(List* list); // 맨뒤 삭제
int get_dnode_count(List* list); // 리스트의 갯수
int insert_front_Nth_dnode(List *list,int N); // N번째 삽입
int remove_front_Nth_dnode(List* list,int N); // N번째 노드 제거
void reverse_dnode(List *list); // 역순 연결
DNode* search(List* list, int N); // 노드 찾기
int remove_search(List* list, int N); // 특정값 삭제
void remove_all_dnode(List *list); // 모든 노드 삭제

int main()
{
	int choice, value;
	List myList;
	List_init(&myList);
	while (1)
	{
		printf("\n\n\t *** 이중 연결 리스트(Doubly Linked List) ***\n\n");
		printf(" 1. 노드 삽입(맨 앞)\n");
		printf(" 2. 노드 삽입(맨 뒤)\n");
		printf(" 3. 노드 삽입(오름차순 정렬)\n");
		printf(" 4. 노드 삽입(앞에서부터 N번째)\n");
		printf("------------------------------\n");
		printf(" 5. 노드 삭제(맨 앞)\n");
		printf(" 6. 노드 삭제(맨 뒤)\n");
		printf(" 7. 노드 삭제(전체 노드)\n");
		printf(" 8. 노드 삭제(앞에서부터 N번째)\n");
		printf(" 9. 노드 삭제(특정 값)\n");
		printf("------------------------------\n");
		printf("10. 노드 순회 | 이중 연결 리스트 출력\n");
		printf("11. 노드 검색\n");
		printf("12. 노드 개수 구하기\n");
		printf("13. 노드 역순 연결\n");
		printf(" 0. 프로그램 종료\n");
		printf("------------------------------\n");
		printf("\n메뉴 선택 : [  ]\b\b\b");
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
			printf("\n\n*** N번째 노드 삽입 ***\n");
			printf("\n\n몇 번째에 노드를 삽입하시겠습니까? ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (insert_front_Nth_dnode(&myList,value)) //삽입 성공 1 리턴, 삽입 실패 시 0리턴
				printf("\n\n\t\t%d번째에 삽입 성공 했습니다.\n", value);
			else
				printf("\n\n\t\t%d번째 삽입하지 못했습니다.\n", value);
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
			printf("\n\n*** N번째 노드 삭제 ***\n");
			printf("\n\n몇 번째 노드를 삭제하시겠습니까? ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (remove_front_Nth_dnode(&myList, value)) //삭제 성공 1 리턴, 삭제 실패 시 0리턴
				printf("\n\n\t\t%d번째 노드를 삭제했습니다.\n", value);
			else
				printf("\n\n\t\t%d번째 노드를 삭제하지 못했습니다.\n", value);
			break;
		case REMOVE_VALUE:
			system("cls");
			printf("\n\n삭제할 값을 입력해 주세요 : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (remove_search(&myList,value)) //삭제 성공 1 리턴, 삭제 실패 시 0리턴
				printf("\n\n\t\t%d값의 노드를 삭제했습니다.\n", value);
			else
				printf("\n\n\t\t%d값의 노드를 삭제하지 못했습니다.\n", value);
			break;
		case TRAVERSAL:
			traversal_dnode(&myList);
			break;
		case SEARCH:
			printf("\n\n 찾을 값을 입력해 주세요 : ");
			scanf("%d", &value);
			while (getchar() != '\n');

			if (search(&myList, value))
				printf("%d 값이 리스트에 존재합니다\n", value);
			else
				printf("%d 값이 리스트에 존재하지 않습니다.\n", value);
			break;
		case GET_NODE_COUNT:
			printf("\n\n\t\t생성된 노드의 개수는 %d개 입니다.\n", get_dnode_count(&myList));
			break;
		case REVERSE:
			reverse_dnode(&myList);
			break;
		case TERMINATE:
			remove_all_dnode(&myList);
			exit(0); //프로그램 강제 종료			
		}

		printf("\n\n\t\t");
		system("pause"); //일시대기
		system("cls"); //화면지우기
	}

	return 0;
}
DNode* create_dnode() // 노드 생성과 초기화
{
	DNode *newDNode = (DNode*)malloc(sizeof(DNode));
	newDNode->next = NULL;
	newDNode->prev = NULL;
	printf("리스트에 넣을 데이터를 입력해 주세요. : ");
	scanf("%d", &newDNode->value);
	while (getchar() != '\n');

	return newDNode;
}
void remove_all_dnode(List* list) // 모든 노드 삭제
{
	if (list->size == 0) //삭제 할게 없으면
	{
		return;
	}
	DNode* deleteDNode, *curDNode; 
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

void List_init(List* list)  // 리스트 초기화
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}
void insert_front_dnode(List* list) // 맨앞 삽입
{
	DNode* newDNode = create_dnode(); // 노드 생성
	if (list->size == 0) //비어있다면
	{
		list->head = newDNode;
		list->tail = newDNode;
		list->size += 1;
		return;
	}
	newDNode->next = list->head; // 맨앞에 삽입하고  head변경
	list->head->prev = newDNode;
	list->head = newDNode;
	list->size += 1;
}
void insert_tail_dnode(List* list) // 맨 뒤 삽입
{
	DNode* newDNode = create_dnode(); // 노드 생성
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
void traversal_dnode(List* list) //순회
{
	if (list->size == 0) //0개면 순회 안한다.
	{
		return;
	}
	DNode* curDNode = list->head; // 맨앞부터
	int i = 1;
	while (curDNode) // 하나씩 순회 한다.
	{
		printf("%d번째 노드는 %d입니다\n", i, curDNode->value);
		curDNode = curDNode->next;
		i++;
	}
}
void remove_front_dnode(List* list) // 맨앞 삭제
{
	if (list->size == 0) // 삭제할게 없다면 종료
		return;
	else if (list->size == 1) // 1개라면
	{
		free(list->head); //처음것 없애주고 초기화
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		DNode* deleteNode = list->head; // 맨앞에 삭제
		list->head = list->head->next; // head값 변경
		list->head->prev = NULL; // 뒤에 노드 null값 넣어준다.
		free(deleteNode);
	}
	list->size -= 1; 
}
int get_dnode_count(List* list)
{
	return list->size; // size리턴
}
void remove_tail_dnode(List* list) // 맨뒤 삭제
{
	if (list->size == 0) // 삭제할게 없다면 종료
		return;
	else if (list->size == 1) // 1개라면 맨뒤에 거를 없애주고 초기화
	{
		free(list->tail);
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		DNode* deleteNode = list->tail; 
		list->tail = list->tail->prev; // tail을 변경하고 
		list->tail->next = NULL; //next값 NULL로 변경  
		free(deleteNode); //삭제
	}
	list->size -= 1;
}
int insert_front_Nth_dnode(List* list, int N) // N번째 삽입
{
	if (N<1 || N>list->size + 1) // 삽입입력을 잘못하면 종료
		return 0;

	if (N == 1) //맨앞에 삽입한다면
	{
		insert_front_dnode(list);
	}
	else if (N==list->size+1) // 맨뒤에 삽입한다면
	{
		insert_tail_dnode(list);
	}
	else //중간에 삽입한다면
	{
		int i = 2;
		DNode* curNode = list->head->next; // 2번째 부터 순회
		while (i < N) //N번째에까지 찾아간다
		{
			curNode = curNode->next; 
			i++;
		}
		DNode* newNode = create_dnode(); // 노드생성
		newNode->next = curNode; // 중간에 삽입한다.
		newNode->prev = curNode->prev;
		newNode->prev->next = newNode;
		curNode->prev = newNode;
		list->size += 1;
	}
	return 1; //삽입성공
}
int remove_front_Nth_dnode(List* list, int N)
{
	if (N<1 || N>list->size) // 삽입 입력을 잘못하면 종료
		return 0;
	if (N == 1) //맨앞을 삭제한다면
	{
		remove_front_dnode(list);
	}
	else if (N == list->size) // 맨뒤를 삭제한다면
	{
		remove_tail_dnode(list);
	}
	else //중간에 있는걸 삭제한다면
	{
		int i = 2;
		DNode* curNode = list->head->next; //2번째 부터 순회
		while (i < N) //N번째까지 이동
		{
			curNode = curNode->next;
			i++;
		}
		curNode->next->prev = curNode->prev; // 이전 값들을 연결
		curNode->prev->next = curNode->next;
		free(curNode); //삭제
		list->size -= 1;
	}
	return 1;
}
void reverse_dnode(List* list)
{
	if (list->size < 2) // 거꾸로 연결
		return;
	DNode* curNode = list->head;
	while (curNode) //prev와 next를 swap하면서 이동
	{
		DNode* temp;
		temp = curNode->prev;
		curNode->prev = curNode->next;
		curNode->next = temp;
		curNode = curNode->prev;
	}
	DNode* temp = list->head; //head와 테일 swap
	list->head = list->tail;
	list->tail = temp;
}
DNode* search(List* list, int N) // 특정값 찾기
{
	if (list->size == 0) // 찾을 값 없으면 NULL
		return NULL;
	DNode* curNode = list->head; // 처음부터 순회하면서 찾아간다.
	while (curNode)
	{
		if (curNode->value == N) // 찾으면 포인터값 리턴
			return curNode;
		curNode = curNode->next;
	}
	return curNode;
}
int remove_search(List* list, int N) //특정값 삭제
{
	if (list->size == 0) //리스트가 비어 있으면 종료
	{
		return 0;
	}
	int i = 1;
	DNode* curNode = list->head;
	while (curNode) // 앞에서 부터 찾아간다.
	{
		if (curNode->value == N)
		{
			return remove_front_Nth_dnode(list, i); //i번째에 찾으면 i번째 위치 값을 삭제한다.
		}
		curNode = curNode->next;
		i++;
	}
	return 0; // 특정값을 찾지 못해 삭제 못함
}