#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

bool isMonotonic(int* A, int ASize){
	int count1 = 1;
	int count2 = 1;
	int i = 0;
	for (i; i < ASize - 1; i++)
	{
		if (A[i]>A[i + 1])
		{
			count1++;
		}
		else if (A[i]<A[i + 1])
		{
			count2++;
		}
		else
		{
			count1++;
			count2++;
		}
	}
	if (count1 == ASize || count2 == ASize)
		return true;
	else
		return false;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 4, 5 };
	if (isMonotonic(arr, sizeof(arr) / sizeof(arr[0])))
		printf("true\n");
	else
		printf("fasle");
	return 0;
}