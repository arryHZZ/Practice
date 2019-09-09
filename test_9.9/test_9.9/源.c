#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//优化空间复杂度
int findDuplicate(int* nums, int numsSize){
	int *p = (int *)malloc(sizeof(int)*numsSize + 1);
	memset(p, 0, sizeof(int)*numsSize + 1);
	int i = 0;
	for (; i < numsSize; i++)
	{
		if (++p[nums[i]] == 2)
			break;
	}
	return nums[i];
}

int main()
{
	int arr[] = { 1, 3, 4, 2, 2 };
	printf("%d", findDuplicate(arr, sizeof(arr) / sizeof(arr[0]));
	system("pause");
	return 0;
}