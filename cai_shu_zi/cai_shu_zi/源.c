#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<Windows.h>
void menu()                     //�˵�����
{
	printf("***********************\n");
	printf("***    1.��ʼ��Ϸ    **\n");
	printf("***    0.�˳���Ϸ    **\n");
	printf("***********************\n");
}
void game()            //ʵ��ҳ�湦�ܺ���
{
	int guess = 0;      //�趨����
	int a = 0;
	a = rand()%100+1;      //���������
	while (1)
	{
		printf("��������Ҫ�µ�����");    //���뻺�棡������
		scanf("%d", &guess);     //��ȡ�û����µ�����
		while('\n' != getchar());            //��ֹ���������ַ���������ѭ��
		if (guess > a)
		{
			printf("�´���\n");
		}
		else if (guess < a)
		{
			printf("��С��\n");
		}
		else 
		{
			printf("�¶���\n");
			break;
		}
	}
	
	
}
int main()
{
	srand((unsigned int)time(NULL));     //�趨��������
	int a;
	
	do
	{
		
		menu();        //���ò˵�����
		printf("���������ѡ��:>");
		scanf("%d", &a);
		system("cls");
		switch(a)
		{
			case 1:game(); break;
			case 0:printf("�˳���Ϸ\n"); break;
			default:printf("�������\n");
		}
	} while (a);
	system("pause");
	return 0;
}