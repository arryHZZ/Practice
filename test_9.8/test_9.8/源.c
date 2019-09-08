#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int arrangeCoins(int n){
	int i = 0;
	int sum = 0;
	do
	{
		i++;
		sum = sum + i;
	
	} while (sum < n);
	if (sum == n)
		return i;
	else
		return i - 1;
}

int main()
{
	printf("%d ", arrangeCoins(5));
	system("pause");
	return 0;
}