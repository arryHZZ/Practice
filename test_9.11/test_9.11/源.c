#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void PrintChineseNum(char *str, int sz, char *ret)
{
	char a[] = {'l', 'a', 'b', 'c', 'd',
					'e', 'f', 'g', 'h', 'i',
					'w', 'y', 'Y', 'J', 'F' ,
					'z'};
	char b[4] = { 'Q', ' ', 'S', 'B' };
	char *i = str;
	int tmp = 0;
	int zero = 0;
	while (*i != '\0')
	{
		if (*i == '.')
			break;
		i++;
	}
	while (str < i)
	{

 // 小数点前的所有数字
			    //s b q
			while (((i - str) % 4) != 1 && tmp!=1)
			{
				if (*str != '0')
				{
					tmp = 0;
				}
				if (tmp == 0)
					*ret++ = a[*str - 48];     //判断是几
				if (*str == '0')
				{
					tmp = 1;
				}
				if ((i - str )%4 != 1&& tmp == 0)
					*ret++ = b[(i - str) % 4];        //千 百 十
				str++;
			}
			if (*str != '0')
			{
				*ret++ = a[*str - 48];
				if ((i - str)%4 != 1)
					*ret++ = b[(i - str) % 4];
				tmp = 0;
			}
			if ((i - str) > 4 && *str != '0')
			{
				*ret++ = a[((i - str) / 4) + 9];    //万  亿

			}
		str++;
	}
	*ret++ = a[12];
	while (*str != '\0')
	{
		if (str > i)    // 小数点后的数字
		{
			if (*str != '0')
			{
				*ret++ = a[*str - 48];      
				*ret++ = a[str - i + 12];
			}
			else
			{
				zero++;
			}
		}
		str++;
	}
	if (str == i || zero == 2)
	{
		*ret++ = a[15];
	}
	ret = '\0';
}

int main()
{
	char arr[] = "10010010";
	char ret[50] = { 0 };
	PrintChineseNum(arr, sizeof(arr) / sizeof(arr[0]), ret);
	printf("%s", ret);
	system("pause");
	return 0;
}