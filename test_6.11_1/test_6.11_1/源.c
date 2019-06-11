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
		tmp = *(p1 - 1 + k-t);                        //����ǰһ��Ҫת�Ƶ��ַ�
		for (i = 0; i < len - k ; i++)               //����������ǰ�ƶ�
		{
			*(p1 + k - 1 + i - t) = *(p1 + k + i - t);
		}
		*(p2 + len - 1 - t) = tmp;                   //��������ַ�����ƶ�
	}
}
int main()
{
	char arr[50] = { 0 };
	int n = 0;
	printf("�������ַ���:");
	scanf("%s", &arr);
	do
	{
		printf("������ӵڼ����ַ���ʼ��ת(n<=%d):",strlen(arr));
		scanf("%d", &n);
	} while (n <= 0 || n > strlen(arr));
	left_move(arr, n);
	printf("%s\n", arr);
	system("pause");
	return 0;
}