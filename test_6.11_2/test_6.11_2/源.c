#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int is_left_move(char *str, const char *p)
{
	assert(str != NULL);
	char *p1 = NULL;
	char *p2 = NULL;
	char tmp = 0;
	p1 = str;
	p2 = str;
	int len = strlen(str);
	int i = 0;
	int t = 0;
	int k = 0;
	if (strcmp(str, p) == 1)
		return 1;
	for (k = 1; k < strlen(str); k++)
	{
		tmp = *(p1 + k - 1);                         //保存第一个字符
			for (i = 0; i < strlen(p1 + k); i++)   //剩余向前移动
			{
				*(p1 + k -1+ i) = *(p1 + k + i);
			}
			*(p2 + len - 1) = tmp;                 //将保存的字符移动到最后位置上
			if (strcmp(str, p) == 1)
				return 1;
	}
	return 0;
}
int main()
{
	char arr[] = "AEBCD";
	char arr1[] = "BCDAE";
	int ret = 0;
	ret = is_left_move(arr, arr1);
	if (ret == 1)
		printf("是\n");
	else
		printf("不是\n");
	system("pause");
	return 0;
}