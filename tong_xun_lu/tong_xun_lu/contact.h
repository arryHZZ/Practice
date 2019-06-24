#ifndef _CONTACT_H_
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define MAX_NAME 10
#define MAX_TEL 11
#define MAX_ADDR 15
#define MAX_SEX 3
#define MAX_NUMPERSON 1000
#define MAX_STR 20
//个人信息
typedef struct Personlnfo
{
	char name[MAX_NAME];
	short age;
	char tele[MAX_TEL];
	char addr[MAX_ADDR];
	char sex[MAX_SEX];
}Personlnfo;
//通讯录
typedef struct Contact
{
	Personlnfo per[MAX_NUMPERSON];
	int usedSize;
}Contact;


enum Option
{
	EXIT,
	ADD,
	SEAR,
	DEL,
	SHOW,
	CLEAR,
	SORT
};

void InitContact(Contact *pCon);
void AddContact(Contact *pCon);
int SearContact(Contact *pCon);    //找到返回下标
void DelContact(Contact *pCon);
void ShowContact(Contact *pCon);
void ClearContact(Contact *pCon);
void SortrContact(Contact *pCon);
#endif