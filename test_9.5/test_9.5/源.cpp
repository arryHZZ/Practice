#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool rotateString(char * A, char * B){
	int i = 0;
	char tmp = 0;
	int j = 0;
	if (strlen(A) == strlen(B) && strlen(A) == 0)
		return true;
	if (strlen(A) != strlen(B))
		return false;
	for (i; i < strlen(A); i++)
	{
		if (strcmp(A, B) == 0)
			return true;
		tmp = *A;
		for (j = 1; j < strlen(A); j++)
		{
			A[j - 1] = A[j];
		}
		A[j - 1] = tmp;
	}
	return false;
}

int main()
{
	char A[] = "abcdef";
	char B[] = "bcdefa";
	if (rotateString(A, B) == true)
	{
		printf("true\n");
	}
	else
		printf("false\n");
	system("pasue");
	return 0;
}