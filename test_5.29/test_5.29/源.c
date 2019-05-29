#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void is_tow(int value)
{
	int count = 0;
	int i = 0;
	if (value <= 0)
	{
		printf("%d不是该类型数字\n", value);
	}
	for (i = 0; i < 32; i++)
	{
		if (((value >> i) & 1) == 1)
			count++;
	}
	if (count == 1)
		printf("%d是该类型数字\n",value);
	else
		printf("%d不是该类型数字\n",value);
}
int main()
{
	int num = 0;
	printf("请输入一个整数：");
	scanf("%d", &num);
	is_tow(num);
	system("pause");
	return 0;
}