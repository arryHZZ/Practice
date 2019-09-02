#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#if 1
int search(int* nums, int numsSize, int target){
	if (numsSize == 0)
		return -1;
	if (numsSize == 1 && nums[0] == target)
		return 0;
	int l = 0;
	int r = numsSize - 1;
	int i = 0;
	int mid = 0;
	int min = nums[0];
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i] < min)
		{
			min = nums[i];
			mid = i;
		}
	}
	if (nums[0] <= target)
	{
		l = 0;
		if (mid != 0)
			r = mid - 1;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] < target)
			{
				l = mid + 1;
			}
			else if (nums[mid] > target)
			{
				r = mid - 1;
			}
		}
	}
	else
	{
		l = mid;
		r = numsSize - 1;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] < target)
			{
				l = mid + 1;
			}
			else if (nums[mid] > target)
			{
				r = mid - 1;
			}
		}
	}
	return -1;
}


int main()
{
	int arr[] = { 1 , 3};
	printf("%d\n", search(arr, 2, 1));
	system("pause");
	return 0;
}
#endif