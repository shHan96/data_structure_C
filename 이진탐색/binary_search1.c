#include <stdio.h>

#pragma warning (disable : 4996)
int arr[100000];
int temp[100000];
int find[100000];
void merge_sort(int* arr, int s, int e)
{
	if (s >= e) // 1개이하 일때는 종료
		return;
	else if (e - s == 1) { // 2개일때 크면 교환
		if (arr[s] > arr[e])
		{
			int tmp = arr[s];
			arr[s] = arr[e];
			arr[e] = tmp;
		}
		return;
	}
	int mid = (s + e) / 2; // 반으로 자른다
	merge_sort(arr, s, mid); // 왼쪽 정렬
	merge_sort(arr, mid + 1, e); // 오른쪽 정렬
	for (int i = s; i <= e; i++) // 임시 변수에 복사한다.
	{
		temp[i] = arr[i];
	}
	int index = s; //맨처음에 넣어줄 인덱스 위치
	int lp = s; // 왼쪽 정렬된 배열의 시작 인덱스
	int rp = mid + 1; // 오른쪽 정렬된 배열의 시작 인덱스
	while (lp <= mid && rp <= e)
	{
		if (temp[lp] <= temp[rp]) // 비교하면서 정렬
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
	while (lp <= mid) // 남아 있는  왼쪽정렬 된 배열값들 다 넣어준다
	{
		arr[index] = temp[lp];
		index++;
		lp++;
	}
	while (rp <= e) // 남이 있는 오른쪽 정렬 된 배열값들 다 넣어준다.
	{
		arr[index] = temp[rp];
		index++;
		rp++;
	}


}
int binary_search(int* arr, int s,int e, int v)
{
	int f = s, l = e;
	while (f <= l)
	{
		int mid = (f + l) / 2;
		if (arr[mid] == v)
		{
			return 1;
		}
		else if (arr[mid] < v)
		{
			f = mid + 1;
		}
		else if (arr[mid] > v)
		{
			l = mid - 1;
		}
	}
	return 0;
}


int main()
{
	int n,m;
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
		printf("%d\n", binary_search(arr, 0, n - 1, find[i]));
	}
}