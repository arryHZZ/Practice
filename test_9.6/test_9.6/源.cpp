#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

bool isUgly(int num){
	if (num == 0)
		return false;
	while (num != 1)
	{
		if (num % 5 == 0)
		{
			num = num / 5;
		}
		else if (num % 3 == 0)
		{
			num = num / 3;
		}
		else if (num % 2 == 0)
		{
			num = num / 2;
		}
		else
			return false;
	}
	return true;
}



int main()
{
	int n = 0;
	scanf("%d", &n);
	isUgly(n);
	
	system("pause");
	return 0;
}