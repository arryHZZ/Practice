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
		tmp = *(p1 + k - 1);                         //�����һ���ַ�
			for (i = 0; i < strlen(p1 + k); i++)   //ʣ����ǰ�ƶ�
			{
				*(p1 + k -1+ i) = *(p1 + k + i);
			}
			*(p2 + len - 1) = tmp;                 //��������ַ��ƶ������λ����
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
		printf("��\n");
	else
		printf("����\n");
	system("pause");
	return 0;
}