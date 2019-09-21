#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int kConcatenationMaxSum(int* arr, int arrSize, int k){
	int max = arr[0];
	int sum = 0;
	int i = 0;
	int j = 0;
	int str[2] = { 0 };
	for (i = 0; i < k; ++i)
	{
		for (j = 0; j < arrSize; ++j)
		{
			sum += arr[j];
			if (sum < arr[j])
			{
				sum = arr[j];
			}
			if (sum > max)
			{
				max = sum;
			}
		}
		str[i / 2] = max;
		if (i>1 && (str[0] == str[1] || max<0))
			break;
	}
	return max>0 ? max : 0;
}

int main()
{
	int arr[] = { 1, -2, 1 };
	printf("%d", kConcatenationMaxSum(arr, sizeof(arr) / sizeof(arr[0]), 7));
	return 0;
}