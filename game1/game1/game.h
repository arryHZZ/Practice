#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#define ROW 3    //�������̿��
#define COL 3    //�������̳���
#define RULE 3   //ѡ����������ʤ
void c_excel(char Ex[ROW][COL], int row, int col);
void printExcel(char Ex[ROW][COL], int row, int col);
void myPlay(char Ex[ROW][COL], int row, int col);
void computerPlay(char Ex[ROW][COL], int row, int col);
char is_win(char Ex[ROW][COL], int row, int col, int rule);