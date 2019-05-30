#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void c_excel(char Ex[ROW][COL], int row, int col)      //棋盘初始化
{
	memset(Ex, ' ', row*col*sizeof(Ex[0][0]));
}
void printExcel(char Ex[ROW][COL], int row, int col)     //打印棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", Ex[i][j]);
			if (j < row - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
void myPlay(char Ex[ROW][COL], int row, int col)    //玩家下棋
{
	int a = 0;
	int b = 0;
	while (1)
	{

		scanf("%d%d", &a, &b);
		if (a<1 || a>row || b<1 || b>col)
		{
			printf("非法请重新输入:>");
		}
		else if (Ex[a-1][b-1] != ' ')
		{
			printf("坐标已落子请重新输入:>");
		}
		else if (Ex[a-1][b-1] == ' ')
		{
			Ex[a-1][b-1] = '*';
			break;
		}
	} 
}
void computerPlay(char Ex[ROW][COL], int row, int col)     //电脑下棋
{
	int a = 0;
	int b = 0;

	while (1)
	{
		a = rand() % row + 1;
		b = rand() % col + 1;
	 if (Ex[a - 1][b - 1] == ' ')
		{
		 Ex[a - 1][b - 1] = '#';
			break;
		}
	}
}
static int win_1(char Ex[ROW][COL], int x, int y, int rule, char c)    //横着相连获胜
{
	int count = 0;
	int i = 0;
	int j = 0;
	i = x;
	for (j = 0; j < rule; j++)               
	{
		if (Ex[i][y+j] == c)
			count++;                   //若有目标棋子+1
	}
	return count;      //返回目标棋子个数，是否与规则规定相同
}
static int win_2(char Ex[ROW][COL], int x, int y, int rule, char c)             //判读竖着相连
{
	int count = 0;                     
	int i = 0;
	int j = 0;
	j = y;
	for (i = 0; i < rule; i++)
	{
		if (Ex[x+i][j] == c)               //若有目标棋子+1 
			count++;
	}
	return count;                 //返回目标棋子个数，是否与规则规定相同
}
static int win_3(char Ex[ROW][COL], int x, int y, int rule, char c)           //判断对角线↘
{
	int count = 0;
	int i = 0;
	int j = 0;
	while (rule)
	{
		if (Ex[x + i][y + i] == c)
		{
			count++;                  //若有目标棋子+1 
		}
		i++;                        
		j++;
		rule--;
	}
	return count;                //返回目标棋子个数，是否与规则规定相同
}
static int win_4(char Ex[ROW][COL], int x, int y, int rule, char c)          //判断对角线↙
{
	int count = 0;
	int i = 0;
	int j = 0;
	while (rule)
	{
		if (Ex[x + i][y + i] == c)
		{
			count++;               //若有目标棋子+1 
		}
		i++;
		j--; 
		rule--;               
	}
	return count;              //返回目标棋子个数，是否与规则规定相同
}
static char is_full(char Ex[ROW][COL], int row, int col)       //判断棋盘是否下满
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (Ex[i][j] == ' ')
				return ' ';
		}
	}
	return 'q';
}
char is_win(char Ex[ROW][COL], int row, int col, int rule)
{
	int ret_1 = 0;
	int ret_2 = 0;
	char ret = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)       
	{
		for (j = 0; j <= col - rule; j++)           //每一横排只需判断到列数减规则数个
		{
			ret_1 = win_1(Ex, i, j, rule,'*');
			ret_2 = win_1(Ex, i, j, rule, '#');
			if (ret_1 == rule)
				return '*';
			if (ret_2 == rule)
				return '#';
		}
	}
	for (i = 0; i <= row - rule; i++)              //每一数列只需判断到列数减规则数个
	{
		for (j = 0; j < col; j++)
		{
			ret_1 = win_2(Ex, i, j, rule, '*');
			ret_2 = win_2(Ex, i, j, rule, '#');
			if (ret_1 == rule)
				return '*';
			if (ret_2 == rule)
				return '#';
		}
	}
	for (i = 0; i <= row - rule; i++)            //判断↘，列从0开始，只需判断到列数减规则数个
	{
		for (j = 0; j <= col - rule; j++)        //每一横排从0开始，只需判断到行数减规则数个
		{
			ret_1 = win_3(Ex, i, j, rule, '*');
			ret_2 = win_3(Ex, i, j, rule, '#');
			if (ret_1 == rule)
				return '*';
			if (ret_2 == rule)
				return '#';
		}
	}
	for (i = 0; i <= row - rule; i++)         //判断↙，列从0开始，只需判断到列数减规则数个
	{
		for (j = rule - 1; j < col; j++)    //每一列从规则数减一开始，到边界停止
		{
			ret_1 = win_4(Ex, i, j, rule, '*');
			ret_2 = win_4(Ex, i, j, rule, '#');
			if (ret_1 == rule)
				return '*';
			if (ret_2 == rule)
				return '#';
		}
	}
	ret = is_full(Ex, row, col);     //判满
	if (ret == 'q')
		return ret;
	
	return ' ';
}