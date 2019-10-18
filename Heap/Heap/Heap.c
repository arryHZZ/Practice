#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Print(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void MaxHeap(int *arr, int len, int n)
{
	int parent = n;
	int child = parent * 2 + 1;
	int tmp = 0;
	while (child < len)
	{
		if (child + 1 < len && arr[child] < arr[child + 1])
			child++;
		if (arr[parent] < arr[child])
		{
			tmp = arr[parent];
			arr[parent] = arr[child];
			arr[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
		
	}
}

void BuildHeap(int *arr, int len)
{
	int i = len - 1;
	for (i; i >= 0; i--)
	{
		MaxHeap(arr, len, i);
	}
}


int main()
{
	int arr[] = { 3, 5, 8, 4, 7, 9, 1, 2, 6 };
	BuildHeap(arr, sizeof(arr) / sizeof(arr[0]));
	Print(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}
