#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int find_max(int *p, int n)
{
	int num = 0;
	int i = 0;
	assert(p != NULL);
	num = *p;
	for (i = 1; i < n; i++)
	{
		if (*(p + i)>num)
			num = *(p + i);
	}
	return num;
}
int main()
{
	int arr[10] = { 5, 7, 1, 2, 3, 9, 8, 4, 5, 5 };
	int input = 0;
	int ret = 0;
	int size = 0;
	printf(" ‰»Î");
	size = sizeof(arr) / sizeof(arr[0]);
	scanf("%d", &input);
	ret = find_max(arr, input);
	printf("%d", ret);
	system("pause");
	return 0;
}