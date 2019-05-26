#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int a = 0;
	int i = 0;
	int sum = 0;
	printf("请输入索要求得数字:");
	scanf("%d", &a);
	for (i = 1; i <= 5; i++)
	{
		sum += a * pow(10, 5 - i)*i;
	}
	printf("%d", sum);
	system("pause");
	return 0;
}