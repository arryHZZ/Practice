#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<Windows.h>
void menu()                     //菜单函数
{
	printf("***********************\n");
	printf("***    1.开始游戏    **\n");
	printf("***    0.退出游戏    **\n");
	printf("***********************\n");
}
void game()            //实现页面功能函数
{
	int guess = 0;      //设定变量
	int a = 0;
	a = rand()%100+1;      //生成随机数
	while (1)
	{
		printf("请输入你要猜的数字");    //输入缓存！！！！
		scanf("%d", &guess);     //获取用户所猜的数字
		while('\n' != getchar());            //防止输入其他字符，陷入死循环
		if (guess > a)
		{
			printf("猜大了\n");
		}
		else if (guess < a)
		{
			printf("猜小了\n");
		}
		else 
		{
			printf("猜对了\n");
			break;
		}
	}
	
	
}
int main()
{
	srand((unsigned int)time(NULL));     //设定随机数起点
	int a;
	
	do
	{
		
		menu();        //调用菜单函数
		printf("请输入你的选项:>");
		scanf("%d", &a);
		system("cls");
		switch(a)
		{
			case 1:game(); break;
			case 0:printf("退出游戏\n"); break;
			default:printf("输入错误\n");
		}
	} while (a);
	system("pause");
	return 0;
}