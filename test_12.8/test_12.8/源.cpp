#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>  
#include<cstring>  
#include<string>  
using namespace std;

//���ֲ���
#if 0
int Binarysearch(int arr[], int key, int n)    //  ���� ���ؼ��֣����鳤�ȡ�
{
	int left = 0;
	int right = n - 1;
	int mid = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (key < arr[mid])        // ���м�ֵ���
		{
			right = mid - 1;
		}
		else if (key>arr[mid])    //���м�ֵ�ұ�
		{
			left = mid + 1;
		}
		else                    //�м�ֵ���ڹؼ���
		{
			return mid;    //�ҵ��˷����±�
		}

	}
	return -1;     //�Ҳ���
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int key = 0;
	printf("���룺");
	scanf("%d", &key);
	int n = sizeof(arr) / sizeof(arr[0]);
	int t = Binarysearch(arr, key, n);
	if (t == -1)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("�ҵ����±���%d\n", t);
	}
	return 0;
}
#endif

//˳�����
#if 0
int find(int arr[], int x, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == x)
			return i;
	}
	return -1;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int x = 0;
	int ret = 0;
	printf("input:");
	scanf("%d", &x);
	ret = find(arr, x, sizeof(arr) / sizeof(arr[0]));
	if (ret == -1)
	{
		printf("no\n");
	}
	else
	{
		printf("is %d\n", ret);
	}
	return 0;
}
#endif

//����������
#if 1
int main()
{
	char str1[256], str2[256], temp[256];
	int a[256], b[256], c[256];
	int lena, lenb, lenc;
	int i;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));

	while (cin >> str1 >> str2){


		lena = strlen(str1);
		lenb = strlen(str2);




		for (i = 0; i <= lena - 1; i++)
			a[lena - i] = str1[i] - '0';
		for (i = 0; i <= lenb - 1; i++)
			b[lenb - i] = str2[i] - '0';

		i = 1;
		while (i <= lena || i <= lenb)
		{
			if (a[i]<b[i])
			{
				a[i] += 10;
				a[i + 1]--;
			}
			c[i] = a[i] - b[i];
			i++;
		}
		lenc = i;
		while ((c[lenc] == 0) && (lenc>1))
			lenc--;

		for (i = lenc; i >= 1; i--)
			cout << c[i];
		cout << endl;
	}
}
#endif