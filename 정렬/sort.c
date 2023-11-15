#include <stdio.h>
#pragma warning (disable : 4996)

int arr[1000];
void swap(int* a, int* b) //  swap 함수
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubble_sort(int* arr, int n)
{
	for (int i = 0; i < n; i++) // 0부터 n-1까지 반복
	{
		for (int j = 0; j < n - i-1; j++) // 0부터 n-i-2까지 반복
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}
void selection_sort(int* arr, int n)
{
	int min_value; // 가장 작은값
	int min_index; // 사장 작은 값의 인덱스
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
			swap(&arr[i], &arr[min_index]); // 위치에 swap한다.
		}
	}
}
void insertion_sort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i]; //임시 저장 삽입할 값
		int position=i; // 삽입될 위치
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