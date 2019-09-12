#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

bool isPerfectSquare(int num){
	int l = 0;
	int r = num;
	int mid = 0;
	while (l < r)
	{
		mid = (l - r) / 2 + l;  //8 3
		if ((mid*mid)>num)
		{
			r = mid - 1;   //7 
		}
		else if ((mid*mid) < num)
		{
			l = mid + 1;  //1
		}
		else if ((mid*mid) == num)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	isPerfectSquare(16);
	system("pause");
	return 0;
}