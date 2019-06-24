#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
void menu()
{
	printf("******1.add*************2.search*********\n");
	printf("******3.del*************4.show**********\n");
	printf("******5.clear***********6.sort**********\n");
	printf("******0.exit****************************\n");
}

void start()
{
	int ret = 0;
	int input = 0;
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��������Ĳ�����");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:    // ���
			AddContact(&con);
			break;
		case SEAR:     //����
			ret = SearContact(&con);
			printf("%-6s%-6s%-6s%-15s%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
			printf("%-6s", con.per[ret].name);
			printf("%-6d", con.per[ret].age);
			printf("%-6s", con.per[ret].sex);
			printf("%-15s", con.per[ret].tele);
			printf("%-20s\n", con.per[ret].addr);
			break;
		case DEL:     //ɾ��
			DelContact(&con);
			break;
		case SHOW:    //��ʾ
			ShowContact(&con);
			break;
		case CLEAR:     //���
			ClearContact(&con);
			break;
		case SORT:    //����������
			SortrContact(&con);
			break;
		default:
			break;
		}
	} while (input);
}


int main()
{
	start();
	system("pause");
	return 0;
}