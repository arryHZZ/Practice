#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>









#if 0
int is_left_move(char *arr, const char *p)
{

}

void left_move(char *str, int k)
{
	//assert(str != NULL);
	//
	char* p1 = str;
	char* p2 = str + k - 1;
	char* p3 = str + strlen(str) - 1;
	char tmp = 0;
	while (p1<=p2)
	{
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}
	*p2 = str + k;
	while (p2<=p3)
	{
		tmp = *p3;
		*p3 = *p2;
		*p2 = tmp;
		p2++;
		p3--;
	}
	p3 = str + strlen(str) - 1;
	p1 = str;
	while (p1 <= p3)
	{
		tmp = *p1;
		*p1 = *p3;
		*p3 = tmp;
		p1++;
		p3--;
	}
}
int main()
{
	char arr[] = "abcdef";
	int n = 0;
	//printf("请输入字符串:");
	//scanf("%s", &arr);
	//do
	//{
	//	printf("请输入从第几个字符开始反转(n<=%d):", strlen(arr));
	//	scanf("%d", &n);
	//} while (n <= 0 || n > strlen(arr));
	left_move(arr, 2);
	printf("%s\n", arr);
	system("pause");
	return 0;
}


int find(int arr[3][3], int *px, int *py, int key)
{
	int x = 0;
	int y = *py - 1;
	while (x < *px && y >= 0)
	{
		if (arr[x][y] == key)
		{
			*px = x;
			*py = y;
			return 1;
		}
		else if (arr[x][y]>key)
		{
			y--;
			continue;
		}
		else if (arr[x][y] < key)
		{
			x++;
			continue;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = { 1, 2, 3, 2, 3, 4, 3, 4, 5 };
	int x = 3;
	int y = 3;
	if (find(arr, &x, &y, 4) == 1)
	{
		printf("下表为：%d %d",x,y);
	}
	else 
		printf("没有此数字\n");
	system("pause");
	return 0;
}



void Function(int *left, int *right)
{
	int tmp = 0;
	while (left < right)
	{
		while (*left % 2 != 0)
		{
			left++;
		}
		while (*right % 2 != 1)
		{
			right--;
		}
		if (left < right)
		{
			tmp = *right;
			*right = *left;
			*left = tmp;
		}
	}
}

int main()
{
	int i = 0;
	int arr[] = { 1, 2, 3, 12, 67, 32, 97, 100 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Function(arr, arr + len - 1);
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}
#endif