#include <stdio.h>
#pragma warning (disable : 4996)

int arr[1000];
void swap(int* a, int* b) //  swap �Լ�
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubble_sort(int* arr, int n)
{
	for (int i = 0; i < n; i++) // 0���� n-1���� �ݺ�
	{
		for (int j = 0; j < n - i-1; j++) // 0���� n-i-2���� �ݺ�
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}
void selection_sort(int* arr, int n)
{
	int min_value; // ���� ������
	int min_index; // ���� ���� ���� �ε���
	for (int i = 0; i < n-1; i++)
	{
		min_value = arr[i];
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (min_value > arr[j])
			{
				min_value = arr[j];
				min_index = j;
			}
		}
		if (min_index != i)
		{
			swap(&arr[i], &arr[min_index]); // ��ġ�� swap�Ѵ�.
		}
	}
}
void insertion_sort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i]; //�ӽ� ���� ������ ��
		int position=i; // ���Ե� ��ġ
		for (int j = 0; j < i; j++)
		{
			if (temp < arr[j])
			{
				position = j;
				break;
			}
		}
		for (int j = i; j >position; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[position] = temp;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	//bubble_sort(arr, n);
	//selection_sort(arr, n);
	insertion_sort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}