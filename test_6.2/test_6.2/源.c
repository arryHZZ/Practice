#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char find_char(char *str)
{
	int aicll[256] = {0};
	char *head = NULL;
	assert(str != NULL);
	head = str;
	while (*str!='\0')
	{
		aicll[(int)(*str)]++;
		str++;
	}
	str = head;
	while (*str != '\0')
	{
		if (aicll[(int)(*str)]==1)
		 return *str;
		str++;
	}
}
int main()
{
	char ret = 0;
	char arr[] = "abceabdcd";
	ret = find_char(arr);
	printf("%c", ret);
	system("pause");
	return 0;
}
