#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define SIZE 3

int FindNum(int arr[SIZE][SIZE], int size, int find)
{
	assert(arr != NULL);
	int i = 0;
	int j = 0;
	int p = 0;
		for (i = 0; i < size; i++)
		{
			if (find > arr[i][i])
			{
				if (arr[i][size-1]>=find)
				{
					for (p = i; p < size; p++)
					{
						if (arr[i][p] == find)
							return 1;
					}
				}
				if (arr[size-1][i]>=find)
				    for (p = i; p < size; p++)
				    {
				  	    if (arr[p][i] == find)
						     return 1;
				    }
			}
			else
				return 0;
		}
	
}
int main()
{
	int arr[SIZE][SIZE] = {1,2,3,3,7,9,4,8,10};
	int ret = 0;
	int find = 0;
	printf("请输入你要查询的数字：");
	scanf("%d", &find);
	ret = FindNum(arr,SIZE,find);
	if (ret == 1)
		printf("有这个数字\n");
	else
		printf("没有这个数字\n");
	system("pause");
	return 0;
}