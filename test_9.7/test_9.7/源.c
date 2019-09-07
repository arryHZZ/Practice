#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int findPeakElement(int* nums, int numsSize){
	if (numsSize == 1)
		return 0;
	if (numsSize == 2)
		return nums[0]>nums[1] ? 0 : 1;
	int l = 0;
	int r = numsSize - 1;
	int mid = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if ((mid == 0 && nums[mid] > nums[mid + 1])
			|| (mid == numsSize - 1 && nums[mid]>nums[mid - 1])
			|| (nums[mid]>nums[mid - 1] && nums[mid] > nums[mid + 1]))
			break;
		else if (nums[mid] < nums[mid + 1])
		{
			l = mid + 1;
		}
		else if (nums[mid] < nums[mid - 1])
		{
			r = mid - 1;
		}
	}
	return mid;
}

int main()
{
	int arr[] = { 1,2,3,2,1 };
	printf("%d", findPeakElement(arr, sizeof(arr) / sizeof(arr[0])));
	system("pause");
	return 0;
}