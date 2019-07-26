#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#define F(X,Y) ((X)+(Y))

int main()
{
	int a = 3,b = 4;
	printf("%d\n", F(a++, b++));
	system("pause");
	return 0;

#if 0
int main()
{
	int x, z, y;
	x = z = 2, y = 3;
	if (x > y)
		z = 1;
	else if (x == y)
		z = 0;
	else
		z = -1;
	printf("%d", z);
	system("pause");
	return 0;
}


int main()
{
	int a = 5;
	if (a = 0)
	{
		printf("%d", a - 10);
	}
	else
	{
		printf("%d", a++);
	}
	system("pause");
	return 0;
}


typedef struct{
	int a;
	char b;
	short c;
	short d;
}AA_t;

int main()
{
	printf("%d", sizeof(AA_t));
	system("pause");
	return 0;	
}


int main()
{
	int i, j, a = 0;
	for (int i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j % 2)
				break;
			a++;
		}
		a++;
	}
	printf("%d\n", a);
	system("pause");
	return 0;
}
#endif
