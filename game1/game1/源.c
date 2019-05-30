#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu()
{
	printf("***********************\n");
	printf("*****  1 . play   *****\n");
	printf("*****  0 . exit   *****\n");
	printf("***********************\n");

}
void game()
{
	system("cls");
	char ret = 0;
	char excel[ROW][COL] = { 0 };        //�趨���������������
	c_excel(excel, ROW, COL);            //��ʼ������
	printExcel(excel, ROW, COL);         //��ӡ����
	while (1)
	{
		printf("�����:>");
		myPlay(excel, ROW, COL);                 //������� 
		ret = is_win(excel, ROW, COL,RULE);
		system("cls");
		printExcel(excel, ROW, COL);         //��ӡ����
		if (ret != ' ')
			break;
		
		printf("��������˼��:\n");
		computerPlay(excel, ROW, COL);                 //�������� 
		Sleep(2000);
		system("cls");
		printExcel(excel, ROW, COL);         //��ӡ����
	    ret = is_win(excel, ROW, COL, RULE);
		if (ret != ' ')
			break;
		
	}
	if (ret == '*')
		printf("���ʤ\n");
	if (ret == '#')
		printf("����ʤ\n");
	if (ret == 'q')
		printf("ƽ��\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int me = 0;
	do
	{
		menu();
		printf("���������ѡ��:>");
		scanf("%d", &me);
		switch(me)
		{
			case 1:
				game(); 
				break;
			case 0:printf("�ɹ��˳�\n"); break;
			default:printf("�����������������\n");
		}
	} while (me);
	system("pause");
	return 0;
}
