#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#define ROW 3    //创建棋盘宽度
#define COL 3    //创建棋盘长度
#define RULE 3   //选择几子相连获胜
void c_excel(char Ex[ROW][COL], int row, int col);
void printExcel(char Ex[ROW][COL], int row, int col);
void myPlay(char Ex[ROW][COL], int row, int col);
void computerPlay(char Ex[ROW][COL], int row, int col);
char is_win(char Ex[ROW][COL], int row, int col, int rule);