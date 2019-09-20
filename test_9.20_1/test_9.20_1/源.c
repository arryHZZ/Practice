#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void changeStr(char *l, char*r)
{
	char tmp = 0;
	l++;
	while (l<r)
	{
		tmp = *l;
		*l = *r;
		*r = tmp;
		l++;
		r--;
	}
}

char * reverseParentheses(char * s){
	char* arr[20] = { 0 };
	char *p = s;
	int i = 0;
	int tmp = 0;
	while (*s != '\0')
	{
		if (*s == '(')
		{
			arr[i++] = s;
			tmp++;
		}
		if (*s == ')')
		{
			changeStr(arr[--i], s - 1);
		}
		s++;
	}
	s = p;
	char *cur = 0;
	while (*s == '(' || *s == ')')
	{
		s++;
	}
	p = s;
	cur = s;
	while (*cur != '\0')
	{
		if (*cur == '(' || *cur == ')')
		{
			cur++;
			continue;
		}
		*p = *cur;
		p++;
		if (*cur)
			cur++;
	}
	*p = '\0';
	return s;
}

int main()
{
	char str[] = "(ed(et(oc))el)";
	printf("%s",reverseParentheses(str));
	return 0;
}