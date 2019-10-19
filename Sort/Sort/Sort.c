#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Heap.h"
#include"Sort.h"
#include<malloc.h>

//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(int *arr, int len)
{
	int i = 0;
	int end;
	int tmp;
	for (i; i < len - 1; i++)
	{
		end = i;
		tmp = arr[end + 1];
		while (end >= 0 && tmp < arr[end])
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = tmp;
	}
}

void Print(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//œ£∂˚≈≈–Ú
void ShellSort(int *arr, int len)
{
	int tap = len / 2;
	int i = 0;
	int end = 0;
	int tmp = 0;
	while (tap)
	{
		
		for (i = 0; i < len - tap; i++)
		{
			end = i;
			tmp = arr[end + tap];
			while (end >= 0 && arr[end]>tmp)
			{
				arr[end + tap] = arr[end];
				end = end - tap;
			}
			arr[end + tap] = tmp;
		}
		tap = tap / 2;
	}	
}

//√∞≈›≈≈–Ú
void BubSort(int *arr, int len)
{
	int i = 0;
	int j = 0;
	int tmp;
	int folg = 0;
	for (i; i < len - 1; i++)
	{
		folg = 0;
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				folg = 1;
			}
		}
		if (folg == 0)
		{
			break;
		}
	}
}

//∂—≈≈–Ú
void HaepSort(int *arr, int len)
{
	BuildHeap(arr, len); //Ω®∂—
	int tmp = 0;
	int n = len - 1;
	for (int i = len; i > 0; i--)
	{
		tmp = arr[0];    // Ωªªª
		arr[0] = arr[i - 1];
		arr[i - 1] = tmp;
		MaxHeap(arr, --len, 0);  //‘Ÿ¥ŒΩ®∂—
	}
}

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//øÏÀŸ≈≈–Ú
int PartSort(int *arr, int left, int right)
{
	int key = arr[left];
	int start = left;
	int tmp = 0;
	while(left < right)
	{
		while (left<right && arr[right] >= key)
		{
			right--;
		}
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[start], &arr[left]);
	return left;
}

void QSort(int *arr, int left, int right)
{
	int mid = PartSort(arr, left, right);
	if (left<mid - 1)
		QSort(arr, left, mid - 1);
	if (mid + 1<right)
		QSort(arr, mid + 1, right);
}

//πÈ≤¢≈≈–Ú
void _MergeSort(int *arr, int* NewArr, int left, int right, int mid)
{
	int begin1 = left;
	int begin2 = mid+1;
	int tmp = left;
	while (begin1 <= mid && begin2 <= right)
	{
		if (arr[begin1] < arr[begin2])
			NewArr[tmp++] = arr[begin1++];
		else
			NewArr[tmp++] = arr[begin2++];
	}
	while (begin1<=mid)
	{
		NewArr[tmp++] = arr[begin1++];
	}
	while (begin2 <= right)
	{
		NewArr[tmp++] = arr[begin2++];
	}
	for(tmp = left; tmp <= right; tmp++)
	{
		arr[tmp] = NewArr[tmp];
	}
}

void MergeSort(int *arr, int* NewArr, int left, int right)
{
	int mid = left + (right - left)/2;
	if (left < right)
	{
		MergeSort(arr, NewArr,left, mid);
		MergeSort(arr, NewArr, mid + 1, right);
	}
	_MergeSort(arr, NewArr, left, right, mid);
}

//—°‘Ò≈≈–Ú
void SelectSort(int *arr, int len)
{
	int max = 0;
	int min = 0;
	int begin = 0;
	int end = len - 1;
	int i = 0;
	while (begin < end)
	{
		for (i = begin; i <= end; i++)
		{
			if (arr[i] < arr[min])
				min = i;
			if (arr[i]>arr[max])
				max = i;
		}
		Swap(&arr[begin], &arr[min]);
		if (max == begin)
			max = min;
		Swap(&arr[end], &arr[max]);
		begin++;
		end--;
	}
}

int main()
{
	int arr1[] = { 3, 5, 8, 4, 7, 9, 1, 2, 6 };
	int* NewArr = (int *)malloc(sizeof(int)*(sizeof(arr1)/sizeof(arr1[0])));
	//InsertSort(arr1, sizeof(arr1) / sizeof(arr1[0]));
	//ShellSort(arr1, sizeof(arr1) / sizeof(arr1[0]));
	//BubSort(arr1, sizeof(arr1) / sizeof(arr1[0]));
	//HaepSort(arr1, sizeof(arr1) / sizeof(arr1[0]));
	//QSort(arr1,0, sizeof(arr1) / sizeof(arr1[0])-1);
	//SelectSort(arr1, 9);
	//MergeSort(arr1, NewArr, 0, sizeof(arr1) / sizeof(arr1[0])-1);
	Print(arr1, sizeof(arr1) / sizeof(arr1[0]));
	return 0;
}