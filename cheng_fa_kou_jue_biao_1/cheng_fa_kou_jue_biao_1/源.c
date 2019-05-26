#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Print_kjb(int l)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= l; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%2d *%2d=%2d ", i, j, i*j);
		printf("\n");
	}
}
int main()
{
	int line = 0;
	printf("请输入要生成乘法口诀表的行数\n");
	scanf("%d",&line);
	Print_kjb(line);
	system("pause");
	return 0;
}
