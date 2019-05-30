#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void c_excel(char Ex[ROW][COL], int row, int col)      //���̳�ʼ��
{
	memset(Ex, ' ', row*col*sizeof(Ex[0][0]));
}
void printExcel(char Ex[ROW][COL], int row, int col)     //��ӡ����
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
void myPlay(char Ex[ROW][COL], int row, int col)    //�������
{
	int a = 0;
	int b = 0;
	while (1)
	{

		scanf("%d%d", &a, &b);
		if (a<1 || a>row || b<1 || b>col)
		{
			printf("�Ƿ�����������:>");
		}
		else if (Ex[a-1][b-1] != ' ')
		{
			printf("��������������������:>");
		}
		else if (Ex[a-1][b-1] == ' ')
		{
			Ex[a-1][b-1] = '*';
			break;
		}
	} 
}
void computerPlay(char Ex[ROW][COL], int row, int col)     //��������
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
static int win_1(char Ex[ROW][COL], int x, int y, int rule, char c)    //����������ʤ
{
	int count = 0;
	int i = 0;
	int j = 0;
	i = x;
	for (j = 0; j < rule; j++)               
	{
		if (Ex[i][y+j] == c)
			count++;                   //����Ŀ������+1
	}
	return count;      //����Ŀ�����Ӹ������Ƿ������涨��ͬ
}
static int win_2(char Ex[ROW][COL], int x, int y, int rule, char c)             //�ж���������
{
	int count = 0;                     
	int i = 0;
	int j = 0;
	j = y;
	for (i = 0; i < rule; i++)
	{
		if (Ex[x+i][j] == c)               //����Ŀ������+1 
			count++;
	}
	return count;                 //����Ŀ�����Ӹ������Ƿ������涨��ͬ
}
static int win_3(char Ex[ROW][COL], int x, int y, int rule, char c)           //�ж϶Խ��ߨK
{
	int count = 0;
	int i = 0;
	int j = 0;
	while (rule)
	{
		if (Ex[x + i][y + i] == c)
		{
			count++;                  //����Ŀ������+1 
		}
		i++;                        
		j++;
		rule--;
	}
	return count;                //����Ŀ�����Ӹ������Ƿ������涨��ͬ
}
static int win_4(char Ex[ROW][COL], int x, int y, int rule, char c)          //�ж϶Խ��ߨL
{
	int count = 0;
	int i = 0;
	int j = 0;
	while (rule)
	{
		if (Ex[x + i][y + i] == c)
		{
			count++;               //����Ŀ������+1 
		}
		i++;
		j--; 
		rule--;               
	}
	return count;              //����Ŀ�����Ӹ������Ƿ������涨��ͬ
}
static char is_full(char Ex[ROW][COL], int row, int col)       //�ж������Ƿ�����
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
		for (j = 0; j <= col - rule; j++)           //ÿһ����ֻ���жϵ���������������
		{
			ret_1 = win_1(Ex, i, j, rule,'*');
			ret_2 = win_1(Ex, i, j, rule, '#');
			if (ret_1 == rule)
				return '*';
			if (ret_2 == rule)
				return '#';
		}
	}
	for (i = 0; i <= row - rule; i++)              //ÿһ����ֻ���жϵ���������������
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
	for (i = 0; i <= row - rule; i++)            //�жϨK���д�0��ʼ��ֻ���жϵ���������������
	{
		for (j = 0; j <= col - rule; j++)        //ÿһ���Ŵ�0��ʼ��ֻ���жϵ���������������
		{
			ret_1 = win_3(Ex, i, j, rule, '*');
			ret_2 = win_3(Ex, i, j, rule, '#');
			if (ret_1 == rule)
				return '*';
			if (ret_2 == rule)
				return '#';
		}
	}
	for (i = 0; i <= row - rule; i++)         //�жϨL���д�0��ʼ��ֻ���жϵ���������������
	{
		for (j = rule - 1; j < col; j++)    //ÿһ�дӹ�������һ��ʼ�����߽�ֹͣ
		{
			ret_1 = win_4(Ex, i, j, rule, '*');
			ret_2 = win_4(Ex, i, j, rule, '#');
			if (ret_1 == rule)
				return '*';
			if (ret_2 == rule)
				return '#';
		}
	}
	ret = is_full(Ex, row, col);     //����
	if (ret == 'q')
		return ret;
	
	return ' ';
}