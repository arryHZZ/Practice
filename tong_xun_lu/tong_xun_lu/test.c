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
	//创建通讯录
	Contact con;
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请输入你的操作：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:    // 添加
			AddContact(&con);
			break;
		case SEAR:     //查找
			ret = SearContact(&con);
			printf("%-6s%-6s%-6s%-15s%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
			printf("%-6s", con.per[ret].name);
			printf("%-6d", con.per[ret].age);
			printf("%-6s", con.per[ret].sex);
			printf("%-15s", con.per[ret].tele);
			printf("%-20s\n", con.per[ret].addr);
			break;
		case DEL:     //删除
			DelContact(&con);
			break;
		case SHOW:    //显示
			ShowContact(&con);
			break;
		case CLEAR:     //清空
			ClearContact(&con);
			break;
		case SORT:    //以姓名排序
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