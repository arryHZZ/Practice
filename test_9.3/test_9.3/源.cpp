#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
	int l = 0;
	int r = numbersSize - 1;
	*returnSize = 2;
	int *p = (int *)malloc(8);
	while (l<r)
	{
		if ((numbers[l] + numbers[r]) == target)
		{
			p[0] = l + 1;
			p[1] = r + 1;
			break;
		}
		if ((numbers[l] + numbers[r]) < target)
		{
			l++;
		}
		if (((numbers[l] + numbers[r]) > target))
		{
			r--;
		}
	}
	return p;
}


int main()
{
	int arr[] = { 2, 7, 11, 15 };
	twoSum(arr, 4, 9);
	return 0;
}