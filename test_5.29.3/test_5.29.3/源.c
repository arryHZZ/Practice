#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void revovle(char *str, int n)
{
	int len = 0;
	int r = 0;
	int l = 0;
	char tmp = 0;
	len = strlen(str) - 1;
	l = len;
	r = n - 1;
	while(r <= l)
	{
		tmp = *(str + r);
		*(str + r) = *(str + l);
		*(str + l) = tmp;
		r++;
		l--;
	}
	assert(str != NULL);
	if (str == NULL)
		printf("ָ��Ϊ��\n");

}
int main()
{
	int n = 0;
	char arr[] = { "abcdefg" };
	printf("�ӵڼ����ַ���ʼ��ת\n");
	do
	{
		scanf("%d", &n);
		if (n < 0)
			printf("n����Ϊ�������������룺");
		else if (n>sizeof(arr))
			printf("nֵ�����ַ������ȣ��������룺");
		else break;
	} while (1);
	revovle(arr, n);
	printf("%s", arr);
	system("pause");
	return 0;
}