#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable : 4996)
int arr[1000000];

void quick_sort(int* arr, int s, int e)
{
	if (s >= e) // ������ 1�����ϸ� ���� ����
		return;
	int left = s, right = e;
	int pivot = arr[(left + right) / 2]; //�߰����� �ǹ����� ����
	while (left <= right) // �����ϱ� ������ �ݺ�
	{
		while (arr[left] < pivot) //�ǹ����� ũ�ų� ���� ���� ã�´�
			left++;
		while (arr[right] > pivot) //�ǹ����� �۰ų� ���� ���� ã�´�
			right--;
		if (left <= right) // �������� �ʾ����� ��ȯ�Ѵ�.
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++; //��ȯ�ϰ� ������ �̵�
			right--;
		}
	}
	quick_sort(arr, s, right); // ��������� �ݺ�
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
	for (int i = 0; i < n; i++) // ���� ����
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