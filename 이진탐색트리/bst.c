#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)


typedef struct treeNode
{
	int value;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

void displayTreeInorder(treeNode* t); //중위 순회
void displayTreePreorder(treeNode* t); // 전위 순회
void displayTreePostorder(treeNode* t); // 후위 순회
treeNode* memoryFree(treeNode* t); // 전체 삭제
int getTreeNodeCount(treeNode* t); // tree안의 노드 개수
int getTreeNodeSum(treeNode* t); // 트리안에 노드의 총합
int getTreeHeight(treeNode* t); // 트리의 높이
treeNode* addNode(treeNode* t, int data); // 새로운 노드 넣기
treeNode* getMaxNode(treeNode* t); // 최대값 리턴
treeNode* getMinNode(treeNode* t); // 최소값 리턴
treeNode* searchTreeNode(treeNode* t, int target);// 노드 찾기
treeNode* removeTreeNode(treeNode* t, int target); // 노드 삭제


int main()
{
	treeNode* root = NULL;
	treeNode* findNode;
	int choice, data;
	while (1)
	{
		system("cls");
		printf("\n\n\t\t*** Binary Search Tree(BST) ***\n\n");
		printf("1. 원소 삽입\n");
		printf("2. 원소 제거\n");
		printf("3. 원소 검색\n");
		printf("4. 최댓값 구하기\n");
		printf("5. 최솟값 구하기\n");
		printf("6. 이진 검색 트리 출력\n");
		printf("7. 트리 노드의 합\n");
		printf("8. 트리 노드의 개수\n");
		printf("9. 트리의 높이\n");
		printf("0. 프로그램 종료\n");
		printf("\n메뉴 선택 : ");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			printf("\n\n트리 노드의 값 입력 : ");
			scanf("%d", &data);
			while (getchar() != '\n');
			//addNode함수 : 노드 생성 후 루트의 주소를 리턴
			root = addNode(root, data);
			break;
		case 2:
			printf("\n\n제거할 노드의 값 입력 : ");
			scanf("%d", &data);
			while (getchar() != '\n');
			root = removeTreeNode(root, data);
			break;
		case 3:
			printf("\n\n트리 노드의 값 검색 : ");
			scanf("%d", &data);
			while (getchar() != '\n');

			//searchNode 함수 : 검색한 노드가 존재하면 검색 노드의 주소를 리턴, 존재하지 않으면 NULL을 리턴
			findNode = searchTreeNode(root, data);
			if (findNode == NULL)
				printf("\n\n\t\t검색 노드는 존재 하지 않습니다.\n");
			else
				printf("\n\n\t\t검색한 노드의 값은 %p메모리에 저장되어 있습니다.\n", findNode);
			break;
		case 4:
			//getMaxNode함수 : 최댓값 노드를 구해 최댓값 노드의 주소를 리턴
			findNode = getMaxNode(root);
			if (findNode == NULL)
				printf("\n\n\t\t트리가 비어있습니다.\n");
			else
				printf("\n\n\t\t최댓값 노드의 값은 %d입니다.\n", findNode->value);
			break;
		case 5:
			findNode = getMinNode(root);
			if (findNode == NULL)
				printf("\n\n\t\t트리가 비어있습니다.\n");
			else
				printf("\n\n\t\t최솟값 노드의 값은 %d입니다.\n", findNode->value);
			break;
		case 6:
			printf("\n\nBST Display(Inorder) : ");
			displayTreeInorder(root);
			printf("\n\nBST Display(Preorder) : ");
			displayTreePreorder(root);
			printf("\n\nBST Display(Postorder) : ");
			displayTreePostorder(root);
			break;
		case 7:
			printf("\n\n트리 구조에 생성 된 노드의 합은 %d개 입니다.\n", getTreeNodeSum(root));
			break;
		case 8:
			printf("\n\n트리 구조에 생성 된 노드의 개수는 %d개 입니다.\n", getTreeNodeCount(root));
			break;
		case 9:
			printf("\n\n트리의 높이는 %d 입니다.\n", getTreeHeight(root));
			break;
		case 0:
			root = memoryFree(root);
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}
void displayTreeInorder(treeNode* t)
{
	if (t == NULL) 
		return;
	displayTreeInorder(t->left); //왼쪽 탐색
	printf("%d ", t->value); // 출력
	displayTreeInorder(t->right); // 오른쪽 탐색
}

void displayTreePreorder(treeNode* t)
{
	if (t == NULL)
		return;
	printf("%d ", t->value); // 출력
	displayTreeInorder(t->left); // 왼쪽 탐색
	displayTreeInorder(t->right); // 오른쪽 탐색
}
void displayTreePostorder(treeNode* t)
{
	if (t == NULL)
		return;
	displayTreeInorder(t->left); // 왼쪽 탐색
	displayTreeInorder(t->right); // 오른쪽 탐색
	printf("%d ", t->value); // 출력
}
treeNode* memoryFree(treeNode* t)
{
	if (t == NULL)
		return NULL;
	memoryFree(t->left);
	memoryFree(t->right);
	free(t);
	return NULL;
}
int getTreeNodeCount(treeNode* t)
{
	if (t == NULL)
		return 0;
	return 1 + getTreeNodeCount(t->left) + getTreeNodeCount(t->right); //왼쪽 노드와 오른쪽 노드의 합 +1
}
int getTreeNodeSum(treeNode* t)
{
	if (t == NULL)
		return 0;
	return t->value + getTreeNodeSum(t->left) + getTreeNodeSum(t->right); // 왼쪽 트리 총합 + 오른쪽 트리 총합 + 루트값
}
int getTreeHeight(treeNode* t)
{
	if (t == NULL)
		return 0;
	int	a = getTreeHeight(t->left); // 왼쪽 트리의 높이
	int b = getTreeHeight(t->right); // 오른쪽 트리의 높이
	if (a > b)
		return 1 + a; // 왼쪽이 크면
	else
		return 1 + b; // 오른쪽이 크면
}
treeNode* addNode(treeNode* t, int data)
{
	if (t == NULL) // 없으면 넣어준다
	{
		t = (treeNode*)malloc(sizeof(treeNode));
		t->value = data;
		t->left = NULL;
		t->right = NULL;
	}
	else if (t->value > data)
	{
		t->left = addNode(t->left, data); // 값이 작으면 왼쪽 트리에 넣는다
	}
	else if (t->value < data) // 값이 크면 오른쪽 트리에 넣는다
	{
		t->right = addNode(t->right, data);
	}
	return t;
}
treeNode* getMaxNode(treeNode* t) 
{
	if (t != NULL) // 값이 있으면 
	{
		if (t->right != NULL) //오른쪽에 트리가 있다면
			return	getMaxNode(t->right); //오른쪽에 트리의 최대값 노드 리턴
	}
	return t;
}
treeNode* getMinNode(treeNode* t) 
{
	if (t != NULL)
	{
		if (t->left != NULL) // 왼쪽 트리에 값이 있다면 
			return getMinNode(t->left); //왼쪽 트리에서 최소값 노드 리턴
	}
	return t;
}
treeNode* searchTreeNode(treeNode* t, int target)
{
	if (t == NULL)
		return NULL;
	if (t->value == target) // 지금 노드가 타겟이면 리턴
		return t;
	else if (t->value < target)
		return searchTreeNode(t->right, target); // 작으면 왼쪽 트리에서 찾는다
	else if (t->value > target)
		return searchTreeNode(t->left, target); // 크면 오른쪽 트리에서 찾는다

		
}
treeNode* removeTreeNode(treeNode* t, int target)
{
	if (t == NULL) // 없으면 NULL리턴
		return NULL;

	if (t->value == target) // 찾으면
	{
		if (t->left == NULL && t->right == NULL) 
		{
			free(t); //삭제
			return NULL;
		}
		else if (t->left == NULL && t->right != NULL)//오른쪽에만 트리가 있다면
		{
			treeNode* temp = t->right; 
			free(t); //삭제
			return temp; // 오른쪽 트리 리턴
		}
		else if (t->left != NULL && t->right == NULL) // 왼쪽에만 트리가 있다면
		{
			treeNode* temp = t->left; 
			free(t); //삭제
			return temp; //왼쪽 트리 리턴
		}
		else
		{
			t->value = getMinNode(t->right)->value; // 오른쪽트리에서 최소값을 찾아 값을 넣어준다.
			t->right = removeTreeNode(t->right, t->value);//오른쪽에서 최소값을 찾아 삭제한다.
		}
	}
	else if (t->value > target) //작으면 왼쪽 트리에서 찾는다
		t->left = removeTreeNode(t->left, target);
	else if (t->value < target) //크면 오른쪽 트리에서 찾는다
		t->right = removeTreeNode(t->right, target);

	return t;

}