#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int size = 0;
	int arr[] = { 2, 3, 2, 4, 2, 2, 8, 2, 1, 2 };
	size = sizeof(arr) / sizeof(arr[0]);
	int mid = size / 2;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i;j++)
		if (arr[j]>arr[j + 1])
		{
			tmp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp;
		}
	}
	for (i = 0; i < mid; i++)
	{
		if (arr[i] == arr[i + mid])
		{
			break;
		}
	}
	if (i==mid)
	    printf("没有出现次数超过该数组长度一半的数字\n");
	else
		printf("%d为次数超过该数组长度一半的数字\n",arr[i]);
	system("pause");
	return 0;
}