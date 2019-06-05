#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void MoveArr(int *str, int size)
{
	assert(str != NULL);
	int *p1 = str;
	int *p2 = str;
	int a = 0;
	int tmp = 0;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (*p1 % 2 != 0)
		{
			p1++;
			p2++;
		}
		else
			break;
	}
	while (p2!=(str+size))
	{
		if ((*p2) % 2 != 0)
		{
			a = p2 - p1;
			for (i = 0; i < a; i++)
			{
				tmp = *(p2 - i);
				*(p2 - i) = *(p2 - i - 1);
				*(p2 - i - 1) = tmp;
			}
			p1++;
		}
		p2++;
	}
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	MoveArr(arr,sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
	system("pause");
	return 0;
}