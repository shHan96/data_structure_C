#include <stdio.h>

#pragma warning (disable : 4996)
int arr[500000];
int temp[500000];
int find[500000];
void merge_sort(int* arr, int s, int e)
{
	if (s >= e) // 1������ �϶��� ����
		return;
	else if (e - s == 1) { // 2���϶� ũ�� ��ȯ
		if (arr[s] > arr[e])
		{
			int tmp = arr[s];
			arr[s] = arr[e];
			arr[e] = tmp;
		}
		return;
	}
	int mid = (s + e) / 2; // ������ �ڸ���
	merge_sort(arr, s, mid); // ���� ����
	merge_sort(arr, mid + 1, e); // ������ ����
	for (int i = s; i <= e; i++) // �ӽ� ������ �����Ѵ�.
	{
		temp[i] = arr[i];
	}
	int index = s; //��ó���� �־��� �ε��� ��ġ
	int lp = s; // ���� ���ĵ� �迭�� ���� �ε���
	int rp = mid + 1; // ������ ���ĵ� �迭�� ���� �ε���
	while (lp <= mid && rp <= e)
	{
		if (temp[lp] <= temp[rp]) // ���ϸ鼭 ����
		{
			arr[index] = temp[lp];
			lp++;
			index++;
		}
		else
		{
			arr[index] = temp[rp];
			rp++;
			index++;
		}
	}
	while (lp <= mid) // ���� �ִ�  �������� �� �迭���� �� �־��ش�
	{
		arr[index] = temp[lp];
		index++;
		lp++;
	}
	while (rp <= e) // ���� �ִ� ������ ���� �� �迭���� �� �־��ش�.
	{
		arr[index] = temp[rp];
		index++;
		rp++;
	}


}
int binary_search_right(int* arr, int s, int e, int v) // ������ index�� ����
{
	int f = s, l = e;
	while (f <= l)
	{
		int mid = (f + l) / 2;
		if (arr[mid] <= v)
		{
			f = mid + 1;
		}
		else if (arr[mid] > v)
		{
			l = mid - 1;
		}
	}
	return f;
}
int binary_search_left(int* arr, int s, int e, int v) // ���� index�� ����
{
	int f = s, l = e;
	while (f <= l)
	{
		int mid = (f + l) / 2;
		if (arr[mid] < v)
		{
			f = mid + 1;
		}
		else if (arr[mid] >= v)
		{
			l = mid - 1;
		}
	}
	return f;
}

int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &find[i]);
	}
	merge_sort(arr, 0, n - 1);
	for (int i = 0; i < m; i++)
	{
		printf("%d ", binary_search_right(arr,0,n-1,find[i]) - binary_search_left(arr, 0, n - 1, find[i]));
		
	}
	printf("\n");
}