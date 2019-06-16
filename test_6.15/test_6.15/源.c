#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

const char *MyStrstr1(const char *str1, const char *str2)
{
	assert(str1 != NULL && str2 != NULL);
	while (*str1 != '\0')
	{
		const char *ret = str1;
		while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
		{
			str1++;
			str2++;
		}
		if (*str1 == '\0')
		{
			return NULL;
		}
		if (*str2 == '\0')
		{
			return ret;
		}
		str1++;
	}
	return NULL;
}

int main()
{
	//char *str1 = "abbcdef";
	char *str1 = "adefbbbc";
	char *str2 = "bbc";//NULL
	const char *p = MyStrstr1(str1, str2);
	//str1主串   str2：子串       BF朴素算法    KMP算法
	printf("%s\n", p);
	return 0;
}

#if 0
char *Mystrstr(const char * str1,const char *str2)
{
	char *p = str1;
	int i = 1;
	assert(str1 != NULL && str2 != NULL);
	while (*str1 != 0)
	{
		if (*str1 != *str2)
		{
			str1++;
			p = str1;
		}
		if (*str1 == *str2)
		{
			i = 1;
			str1++;
			while (*str2!=NULL)
			{
				if (*(str1 ++) != *(str2 + i))
					break;
			}
		}
	}
}
int main()
{
	char str1 = "abbcdef"; 
	char str2 = "abb";
	char *p = Mystrstr(str1, str2);
	printf("%s", p);
	system("pause");
	return 0;
}


int Mystrncmp(const char *str1,const char*str2,int n)
{
	int i = 0;
	assert(str1 != NULL && str2 != NULL);
	while ((*str1 != 0 || *str2 != 0)&&i++<n)
	{
		if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
			return -1;
		str1++;
		str2++;
	}
	return 0;
}
int main()
{
	
	char* str1 = "aacdef";
	char* str2 = "abdef";
	printf("%d", Mystrncmp(str1, str2, 2));
	system("pause");
	return 0;
}

char *Mystrncat(char *str, const char *src, int n)
{
	char *p = str;
	int i = 0;
	assert(str != NULL&&src != NULL);
	while (*str++ != 0);
	for (i = 0; i < n; i++)
	{
		*(str-1) = *src;
		str++;
		src++;
	}
	return p;
}

int main()
{
	char str[10] = "abcd";
	char *src = "hello";
	printf("%s",Mystrncat(str, src, 2));
	system("pause");
	return 0;
}


char *MyStrncmp(char *dest, const char*src, int n)
{
	int i = 0;
	char *p = dest;
	assert(dest != NULL && src != NULL);
	for (i = 0; i < n; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}


	return p;
}
int main()
{
	char dest[20] = "abcd";
	char *src= "hello";
	printf("%s\n",MyStrncmp(dest,src,2));
	system("pause");
	return 0;
}



int Mystrcmp(const char *str1,const char*str2)
{
	assert(str1 != NULL && str2 != NULL);
	while (*str1 != 0 || *str2 != 0)
	{
	
        if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
			return -1;
		str1++;
		str2++;
	}
	return 0;
}




char *MyStrcat(char * dest, const char *src)
{
	char *p = dest;
	assert(dest != NULL);
	while(*dest != 0)
	{
		dest++;
	}
	while (*dest++ = *src++);
	return p;
}

int main()
{
	char dest[20] = "hello";
	char *src = "bit";
	MyStrcat(dest, src);
	printf("%s", dest);
	system("pause");
	return 0;
}
#endif