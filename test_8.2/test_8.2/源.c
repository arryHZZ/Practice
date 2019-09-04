#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<math.h>
#define ROW 4
#define COL ROW
#define ROW1 3





#if 0
void move(char *str, int n)
{
	int i = 0;
	while (*str != '\0')
	{
		*str = *(str + n);
		str++;
	}
}

char *DeleteChar(char *arr, const char *str)
	char *p = arr;
	char *q = arr;
	char *pc = str;
	int ASCLL[256] = { 0 };
	assert(arr != NULL&&str != NULL);
	while (*str!='\0')
	{
		ASCLL[*str]++;
		str++;
	}
	while (*p != '\0')
	{
		if (ASCLL[*p] != 1)
		{
			*q++ = *p;
			//move(arr, 1);
			//continue;
		}
		p++;
	}
	*q = '\0';
	return arr;
}
int main()
{
	char arr[] = "123456789";
	char str[] = "1234";
	DeleteChar(arr, str);
	printf("%s", arr);
	return 0;
}
#endif
#if 0
void Func2(int arr[][ROW1])
{
	int tmpRow = 0;
	int tmpCol = ROW1/2;
	int i = 2;
	arr[tmpRow][tmpCol] = 1;
	//2-n^2
	for (i = 2; i <= ROW1*ROW1; i++)
	{
		int x = tmpRow;
		int y = tmpCol;
		tmpRow = (tmpRow - 1 + ROW1) % ROW1;
		tmpCol = (tmpCol + 1) % ROW1;
		if (arr[tmpRow][tmpCol] == 0)
		{
			arr[tmpRow][tmpCol] = i;
		}
		else
		{
			arr[x + 1][y] = i;
			tmpRow = x + 1;
		}
	}

}

int main()
{
	int arr[3][3] = {0};
	Func2(arr);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
#endif

#if 0
int FindNum(int *arr, int row, int col ,int n)
{
	int Rowtmp = 0;
	int Coltmp = COL - 1;
	while ( Rowtmp<ROW && Coltmp>=0 )
	{
		if (arr[Rowtmp*col+Coltmp]>n)
			Coltmp--;
		if (arr[Rowtmp*col + Coltmp] < n)
			Rowtmp++;
		if (arr[Rowtmp*col + Coltmp] == n)
			return 1;
	}
	return 0;

}
int main()
{
	int arr[ROW][COL] = { 1, 2, 8, 9, 
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15 };
	int ret = 0;
	int num = 0;
	printf("输入：");
	scanf("%d",&num);
	ret = FindNum(arr,ROW,COL ,num);
	if (ret == 1)
		printf("有\n");
	else
		printf("没有\n");
	system("pause");
	return 0;
}

#endif

#if 0
int CharCount(char *str)
{
	char *p = str;
	int count = 1;
	while (*str == *(str + 1))
	{
		count++;
		str++;
	}
	if (*(str + 1) == '\0')
	{
		*p = '\0';
		return 0;
	}
	return count;
}

void move(char *str, int n)
{
	int i = 0;
	while (*str != '\0')
	{
		*str = *(str + n);
		str++;
	}
}

char *last(char *str)
{
	int n = 0;
	char *p = str;
	while (*str!='\0')
	{
		if (str == p && *str == ' ')
		{
			n = CharCount(str);
			move(str, n);
		}
		else if (str != p && *str == ' ')
		{
			n = CharCount(str);
			if (n == 0)
				break;
			else
				move(++str, n);
		}
		str++;
	}
	return p;
}

int main()
{
	char str[] = "      as        dsdsaaads     ";
	last(str);
	printf("%s", str);
	system("pause");
	return 0;
}
#endif

#if 0
//p47
void move(char *str, int count , int n)
{
	char *first = str + n + 1;
	int i = 0;
	while (*first != '\0')
	{
		*first = *(first + count - n - 1);
		first++;
	}
}

int CharCount(char *str)
{
	int count = 1;
	while (*str == *(str+1))
	{
		count++;
		str++;
	}
	return count;
}
void AddNum(char * str, int count, int n)
{
	int i = 0;
	int y = n;
	for (i; i < n; i++)
	{
		y = y - 1;
		*str++ = 48 + count / pow(10, y);
		count = count % (int)pow (10, y);
	}
}

int num_n(int count)
{
	int n = 1;
	while(count > 9)
	{
		count = count / 10;
		n++;
	}
	return n;
}
char * Y_S_str(char *str)
{
	char * p = str;
	int count = 0;
	int n = 0;
	while (*str != '\0')
	{
		count = 0;
		n = 0;
		if (*str == *(str + 1))
		{
			count = CharCount(str);
			if (count > 2)
			{
				n = num_n(count);
				AddNum(str, count, n);
			}
			move(str, count, n);
		}
		str++;
	}
	return p;
}

int main()
{
	char str[] = "xxxxyyyyz";
	Y_S_str(str);
	printf("%s", str);
	system("pause");
	return 0;
}

#endif
#if 0
//p42
void find_x_y(int arr[], int *x, int *y, int sz , int num)
{
	int *head = arr;
	int *least = arr + sz - 1;
	assert(arr != NULL);
	while (least > head)
	{
		if ((*head + *least) < num)
			head++;
		if ((*head + *least)>num)
			least--;
		if ((*head + *least) == num)
		{
			*x = head - arr;
			*y = least - arr;
			break;
		}
	}

}

int main()
{
	int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int x = 0;
	int y = 0;
	int num = 0;
	printf("输入:");
	scanf("%d", &num);
	find_x_y(arr, &x, &y, size ,num);
	printf("%d,%d", x, y);
	system("pause");
	return 0;
}


#endif

//p35
#if 0
int is_num(int num)
{
	int n = num;
	int sum = 0;
	while (num)
	{
		sum = sum*10+ num % 10;
		num /= 10;
	}
	if (sum == n)
		return 1;
	else
		return 0;
}

int main()
{
	int num = 0;
	int ret = 0;
	printf("输入：");
	scanf("%d", &num);
	ret = is_num(num);
	if (ret == 1)
	{
		printf("%d是回文数\n",num);
	}
	else
	{
		printf("%d不是回文数\n", num);
	}
	system("pause");
	return 0;
}

#endif
#if 0
//p32
char move(char *arr)
{
	char *p = arr;
	assert(arr != NULL);
	while (*arr!='\0')
	{
		*arr = *(arr + 1);
		arr++;
	}
	return p;
}

char *DeleteChar(char *arr, const char *str)
{
	char *p = arr;
	char *pc = str;
	assert(arr != NULL&&str != NULL);
	while (*arr!='\0')
	{
		str = pc;
		while (*str != '\0')
		{
			if (*arr == *str)
				move(arr);
			str++;
		}
		arr++;
	}
	return p;
}

int main()
{
	char arr[] = "123456789";
	char str[] = "1234";
	DeleteChar(arr, str);
	printf("%s", arr);
	system("pause");
	return 0;
}
#endif

//p27
#if 0
char find_char(char *str)
{
	int aicll[256] = { 0 };
	assert(str != NULL);
	while (*str != '\0')
	{
		if(++aicll[(*str)]==2)
			return *str;
		str++;
	}
	return NULL;
}
int main()
{
	char arr[] = "qywyer23tdd";
	char ret = 0;
	ret = find_char(arr);
	if (ret != NULL)
		printf("%c\n", ret);
	else
		printf("无\n");
	system("pause");
	return 0;
}
#endif

//p25
#if 0
char find_char(char *str)
{
	int aicll[256] = {0};
	char *head = NULL;
	assert(str != NULL);
	head = str;
	while (*str!='\0')
	{
		aicll[((*str))]++;
		str++;
	}
	str = head;
	while (*str != '\0')
	{
		if (aicll[(*str)] == 1)
			return *str;
		str++;
	}
	return 0;
}
int main()
{
	char ret = 0;
	char arr[] = ".abcfbda";
	ret = find_char(arr);
	if (ret != NULL)
	{
		printf("%c\n", ret);
	}
	else
		printf("无\n");
	system("pause");
	return 0;
}
#endif

#if 0
//p2
int FindNum(int arr[ROW][COL] , int n )
{
	int i = 0;
	int j = COL - 1;
	while ( i<ROW && j>=0 )
	{
		if (arr[i][j]>n)
			j--;
		if (arr[i][j] < n)
			i++;
		if (arr[i][j] == n)
			return 1;
	}
	return 0;

}
int main()
{
	int arr[ROW][COL] = { 1, 2, 8, 9, 
		              2, 4, 9, 12,
					  4, 7, 10, 13,
					  6, 8, 11, 15 };
	int ret = 0;
	int num = 0;
	printf("输入：");
	scanf("%d",&num);
	ret = FindNum(arr, num);
	if (ret == 1)
		printf("有\n");
	else
		printf("没有\n");
	system("pause");
	return 0;
}

#endif

#if 0
//p9
int One_count( unsigned int n)
{
	int count = 0;
	while ( n )
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}

int main()
{
	unsigned int num = 0;
	printf("输入数字：");
	scanf("%d", &num);
	printf("%d\n", One_count(num));
	system("pause");
	return 0;
}
#endif


#if 0
//p6
int Fibonacci(int n)
{
	int i = 0;
	int num1 = 1;
	int num2 = 1;
	int sum = 1;
	if (n > 2)
		for (i = 0; i < n - 2; i++)
		{
			sum = num1 + num2;
			num1 = num2;
			num2 = sum;
		}
	return sum;
}

int main()
{
	int n = 0;
	int ret = 0;
	printf("要求第几个斐波那契数：");
	scanf("%d", &n);
	ret = Fibonacci(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

#endif
#if 0
//p4
void move(char *str)
{
	int i = 0;
	char *right = str + 1;
	int len = strlen(str);
	right = right + len;
	char *right1 = right + 2;
	assert(str != NULL);
	for ( i = 0; i <= len; i++)
	{
		*(right1 - i) = *(right - i);
	}
}

void Tihuan(char *str)
{
	int len = strlen(str);
	assert(str != NULL);
	while (*str != 0)
	{
		if (*str == ' ')
		{
			move(str);
			*(str++) = '%';
			*(str++) = '2';
			*str = '0';
		}
		str++;
	}
}

int main()
{
	char arr[50] = " abc de fgh " ;
	Tihuan(arr);
	printf("%s", arr);
	system("pause");
	return 0;
}
#endif