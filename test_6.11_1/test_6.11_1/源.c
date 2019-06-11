#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void left_move(char *str, int k)
{
	assert(str != NULL);
	char *p1 = NULL;
	char *p2 = NULL;
	char tmp = 0;
	p1 = str ;
	p2 = str;
	int len = strlen(str);
	int i = 0;
	int t = 0;
	for (t = 0; t < k; t++)
	{
		tmp = *(p1 - 1 + k-t);                        //保存前一个要转移的字符
		for (i = 0; i < len - k ; i++)               //后面依次往前移动
		{
			*(p1 + k - 1 + i - t) = *(p1 + k + i - t);
		}
		*(p2 + len - 1 - t) = tmp;                   //将保存的字符向后移动
	}
}
int main()
{
	char arr[50] = { 0 };
	int n = 0;
	printf("请输入字符串:");
	scanf("%s", &arr);
	do
	{
		printf("请输入从第几个字符开始反转(n<=%d):",strlen(arr));
		scanf("%d", &n);
	} while (n <= 0 || n > strlen(arr));
	left_move(arr, n);
	printf("%s\n", arr);
	system("pause");
	return 0;
}