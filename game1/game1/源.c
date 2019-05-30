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
	char excel[ROW][COL] = { 0 };        //设定存放棋盘内容数组
	c_excel(excel, ROW, COL);            //初始化棋盘
	printExcel(excel, ROW, COL);         //打印棋盘
	while (1)
	{
		printf("玩家走:>");
		myPlay(excel, ROW, COL);                 //玩家下棋 
		ret = is_win(excel, ROW, COL,RULE);
		system("cls");
		printExcel(excel, ROW, COL);         //打印棋盘
		if (ret != ' ')
			break;
		
		printf("电脑正在思考:\n");
		computerPlay(excel, ROW, COL);                 //电脑下棋 
		Sleep(2000);
		system("cls");
		printExcel(excel, ROW, COL);         //打印棋盘
	    ret = is_win(excel, ROW, COL, RULE);
		if (ret != ' ')
			break;
		
	}
	if (ret == '*')
		printf("玩家胜\n");
	if (ret == '#')
		printf("电脑胜\n");
	if (ret == 'q')
		printf("平局\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int me = 0;
	do
	{
		menu();
		printf("请输入你的选择:>");
		scanf("%d", &me);
		switch(me)
		{
			case 1:
				game(); 
				break;
			case 0:printf("成功退出\n"); break;
			default:printf("输入错误，请重新输入\n");
		}
	} while (me);
	system("pause");
	return 0;
}
