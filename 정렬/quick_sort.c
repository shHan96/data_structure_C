#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable : 4996)
int arr[1000000];

void quick_sort(int* arr, int s, int e)
{
	if (s >= e) // 갯수가 1개이하면 정렬 안함
		return;
	int left = s, right = e;
	int pivot = arr[(left + right) / 2]; //중간값을 피벗으로 설정
	while (left <= right) // 교차하기 전까지 반복
	{
		while (arr[left] < pivot) //피벗보다 크거나 같은 값을 찾는다
			left++;
		while (arr[right] > pivot) //피벗보다 작거나 같은 값을 찾는다
			right--;
		if (left <= right) // 교차하지 않았으면 교환한다.
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++; //교환하고 다음값 이동
			right--;
		}
	}
	quick_sort(arr, s, right); // 재귀적으로 반복
	quick_sort(arr, left, e);
}

int main()
{
	int n;
	srand(time(NULL));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) // 랜덤 셔플
	{
		int index = rand() % n;
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}

}