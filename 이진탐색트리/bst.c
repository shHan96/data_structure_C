#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)


typedef struct treeNode
{
	int value;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

void displayTreeInorder(treeNode* t); //���� ��ȸ
void displayTreePreorder(treeNode* t); // ���� ��ȸ
void displayTreePostorder(treeNode* t); // ���� ��ȸ
treeNode* memoryFree(treeNode* t); // ��ü ����
int getTreeNodeCount(treeNode* t); // tree���� ��� ����
int getTreeNodeSum(treeNode* t); // Ʈ���ȿ� ����� ����
int getTreeHeight(treeNode* t); // Ʈ���� ����
treeNode* addNode(treeNode* t, int data); // ���ο� ��� �ֱ�
treeNode* getMaxNode(treeNode* t); // �ִ밪 ����
treeNode* getMinNode(treeNode* t); // �ּҰ� ����
treeNode* searchTreeNode(treeNode* t, int target);// ��� ã��
treeNode* removeTreeNode(treeNode* t, int target); // ��� ����


int main()
{
	treeNode* root = NULL;
	treeNode* findNode;
	int choice, data;
	while (1)
	{
		system("cls");
		printf("\n\n\t\t*** Binary Search Tree(BST) ***\n\n");
		printf("1. ���� ����\n");
		printf("2. ���� ����\n");
		printf("3. ���� �˻�\n");
		printf("4. �ִ� ���ϱ�\n");
		printf("5. �ּڰ� ���ϱ�\n");
		printf("6. ���� �˻� Ʈ�� ���\n");
		printf("7. Ʈ�� ����� ��\n");
		printf("8. Ʈ�� ����� ����\n");
		printf("9. Ʈ���� ����\n");
		printf("0. ���α׷� ����\n");
		printf("\n�޴� ���� : ");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			printf("\n\nƮ�� ����� �� �Է� : ");
			scanf("%d", &data);
			while (getchar() != '\n');
			//addNode�Լ� : ��� ���� �� ��Ʈ�� �ּҸ� ����
			root = addNode(root, data);
			break;
		case 2:
			printf("\n\n������ ����� �� �Է� : ");
			scanf("%d", &data);
			while (getchar() != '\n');
			root = removeTreeNode(root, data);
			break;
		case 3:
			printf("\n\nƮ�� ����� �� �˻� : ");
			scanf("%d", &data);
			while (getchar() != '\n');

			//searchNode �Լ� : �˻��� ��尡 �����ϸ� �˻� ����� �ּҸ� ����, �������� ������ NULL�� ����
			findNode = searchTreeNode(root, data);
			if (findNode == NULL)
				printf("\n\n\t\t�˻� ���� ���� ���� �ʽ��ϴ�.\n");
			else
				printf("\n\n\t\t�˻��� ����� ���� %p�޸𸮿� ����Ǿ� �ֽ��ϴ�.\n", findNode);
			break;
		case 4:
			//getMaxNode�Լ� : �ִ� ��带 ���� �ִ� ����� �ּҸ� ����
			findNode = getMaxNode(root);
			if (findNode == NULL)
				printf("\n\n\t\tƮ���� ����ֽ��ϴ�.\n");
			else
				printf("\n\n\t\t�ִ� ����� ���� %d�Դϴ�.\n", findNode->value);
			break;
		case 5:
			findNode = getMinNode(root);
			if (findNode == NULL)
				printf("\n\n\t\tƮ���� ����ֽ��ϴ�.\n");
			else
				printf("\n\n\t\t�ּڰ� ����� ���� %d�Դϴ�.\n", findNode->value);
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
			printf("\n\nƮ�� ������ ���� �� ����� ���� %d�� �Դϴ�.\n", getTreeNodeSum(root));
			break;
		case 8:
			printf("\n\nƮ�� ������ ���� �� ����� ������ %d�� �Դϴ�.\n", getTreeNodeCount(root));
			break;
		case 9:
			printf("\n\nƮ���� ���̴� %d �Դϴ�.\n", getTreeHeight(root));
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
	displayTreeInorder(t->left); //���� Ž��
	printf("%d ", t->value); // ���
	displayTreeInorder(t->right); // ������ Ž��
}

void displayTreePreorder(treeNode* t)
{
	if (t == NULL)
		return;
	printf("%d ", t->value); // ���
	displayTreeInorder(t->left); // ���� Ž��
	displayTreeInorder(t->right); // ������ Ž��
}
void displayTreePostorder(treeNode* t)
{
	if (t == NULL)
		return;
	displayTreeInorder(t->left); // ���� Ž��
	displayTreeInorder(t->right); // ������ Ž��
	printf("%d ", t->value); // ���
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
	return 1 + getTreeNodeCount(t->left) + getTreeNodeCount(t->right); //���� ���� ������ ����� �� +1
}
int getTreeNodeSum(treeNode* t)
{
	if (t == NULL)
		return 0;
	return t->value + getTreeNodeSum(t->left) + getTreeNodeSum(t->right); // ���� Ʈ�� ���� + ������ Ʈ�� ���� + ��Ʈ��
}
int getTreeHeight(treeNode* t)
{
	if (t == NULL)
		return 0;
	int	a = getTreeHeight(t->left); // ���� Ʈ���� ����
	int b = getTreeHeight(t->right); // ������ Ʈ���� ����
	if (a > b)
		return 1 + a; // ������ ũ��
	else
		return 1 + b; // �������� ũ��
}
treeNode* addNode(treeNode* t, int data)
{
	if (t == NULL) // ������ �־��ش�
	{
		t = (treeNode*)malloc(sizeof(treeNode));
		t->value = data;
		t->left = NULL;
		t->right = NULL;
	}
	else if (t->value > data)
	{
		t->left = addNode(t->left, data); // ���� ������ ���� Ʈ���� �ִ´�
	}
	else if (t->value < data) // ���� ũ�� ������ Ʈ���� �ִ´�
	{
		t->right = addNode(t->right, data);
	}
	return t;
}
treeNode* getMaxNode(treeNode* t) 
{
	if (t != NULL) // ���� ������ 
	{
		if (t->right != NULL) //�����ʿ� Ʈ���� �ִٸ�
			return	getMaxNode(t->right); //�����ʿ� Ʈ���� �ִ밪 ��� ����
	}
	return t;
}
treeNode* getMinNode(treeNode* t) 
{
	if (t != NULL)
	{
		if (t->left != NULL) // ���� Ʈ���� ���� �ִٸ� 
			return getMinNode(t->left); //���� Ʈ������ �ּҰ� ��� ����
	}
	return t;
}
treeNode* searchTreeNode(treeNode* t, int target)
{
	if (t == NULL)
		return NULL;
	if (t->value == target) // ���� ��尡 Ÿ���̸� ����
		return t;
	else if (t->value < target)
		return searchTreeNode(t->right, target); // ������ ���� Ʈ������ ã�´�
	else if (t->value > target)
		return searchTreeNode(t->left, target); // ũ�� ������ Ʈ������ ã�´�

		
}
treeNode* removeTreeNode(treeNode* t, int target)
{
	if (t == NULL) // ������ NULL����
		return NULL;

	if (t->value == target) // ã����
	{
		if (t->left == NULL && t->right == NULL) 
		{
			free(t); //����
			return NULL;
		}
		else if (t->left == NULL && t->right != NULL)//�����ʿ��� Ʈ���� �ִٸ�
		{
			treeNode* temp = t->right; 
			free(t); //����
			return temp; // ������ Ʈ�� ����
		}
		else if (t->left != NULL && t->right == NULL) // ���ʿ��� Ʈ���� �ִٸ�
		{
			treeNode* temp = t->left; 
			free(t); //����
			return temp; //���� Ʈ�� ����
		}
		else
		{
			t->value = getMinNode(t->right)->value; // ������Ʈ������ �ּҰ��� ã�� ���� �־��ش�.
			t->right = removeTreeNode(t->right, t->value);//�����ʿ��� �ּҰ��� ã�� �����Ѵ�.
		}
	}
	else if (t->value > target) //������ ���� Ʈ������ ã�´�
		t->left = removeTreeNode(t->left, target);
	else if (t->value < target) //ũ�� ������ Ʈ������ ã�´�
		t->right = removeTreeNode(t->right, target);

	return t;

}