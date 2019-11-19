#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int* creatArr(int *returnSize)
{
	*returnSize = 2;
	int *a = (int *)malloc(sizeof(int)*2);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	return a;
}

void Print(int a[],int *len)
{
	for (int i = 0; i < *len; i++)
	{
		printf("%d ", a[i]);
	}
}
//
//int change(int n)
//{
//	n = 2;
//	return 0;
//}

int main()
{
	int len = 0;
	//change(len);
	printf("%d\n", len);
	creatArr(&len);
	//Print();
	return 0;
}