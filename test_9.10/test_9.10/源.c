#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int mirrorReflection(int p, int q){
	if (p == q)
		return 1;
	int x = 0;
	int y = 0;     // p = 3    q = 2
	int n = 1;
	q = p - q;      // q = p-q = 3 - 2 = 1  // q = 1
	int tmp = p;

	while (1)
	{
		x += p;   // 0 3 0 3
		y += q;   // 0 1 2 3
		if (y > tmp)
		{
			y = y%p;
			n = -n;
		}
		if (x == tmp && y == tmp && n == 1)
			return 0;
		else  if ((x == 0 && y == 0) || (x == 0 && y == tmp))
			return 2;
		else if (x == tmp && n == -1 && (y == 0 || y == tmp))
			return 1;
		p = -p;   //-3
	}
}

int main()
{
	printf("%d ", mirrorReflection(3, 1));
	system("pause");
	return 0;
}