#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"


void InitContact(Contact *pCon)
{
	assert(pCon != NULL);
	pCon->usedSize = 0;
	memset(pCon->per, 0, sizeof(pCon->per));
}

void AddContact(Contact *pCon)
{
	if (pCon->usedSize == MAX_NUMPERSON)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	printf("����:");
	scanf("%s", pCon->per[pCon->usedSize].name);
	printf("����:");
	scanf("%d", &pCon->per[pCon->usedSize].age);
	printf("�Ա�:");
	scanf("%s", pCon->per[pCon->usedSize].sex);
	printf("�绰:");
	scanf("%s", pCon->per[pCon->usedSize].tele);
	printf("��ַ:");
	scanf("%s", pCon->per[pCon->usedSize].addr);
	pCon->usedSize++;
	printf("��ӳɹ�\n");
}

int SearContact(Contact *pCon)
{
	int i = 0;
	char find[MAX_NAME] = { 0 };
	assert(pCon != NULL);
	if (pCon->usedSize == 0)
	{
		printf("ͨѶ¼��δ�洢��Ϣ\n");
		return -1;
	}

	printf("������������");
	scanf("%s", find);
	for (i = 0; i < pCon->usedSize; i++)
	{
		if (strcmp(find, pCon->per[i].name) == 0)
			return i;
	}
	printf("���޴���\n");
	return -1;
}

void DelContact(Contact *pCon)
{
	int i = 0;
	int ret = SearContact(pCon);
	assert(pCon != NULL);
	if (ret == -1)
		printf("���޴���");
	for (i = ret; i < pCon->usedSize-1; i++)
	{
		strcpy (pCon->per[i].addr , pCon->per[i + 1].addr);
		pCon->per[i].age = pCon->per[i + 1].age;
		strcpy(pCon->per[i].name, pCon->per[i + 1].name);
		strcpy(pCon->per[i].sex, pCon->per[i + 1].sex);
		strcpy(pCon->per[i].tele, pCon->per[i + 1].tele);
	}
	pCon->usedSize--;
	printf("ɾ���ɹ�\n");
}
void ShowContact(Contact *pCon)
{
	int i = 0;
	assert(pCon != NULL);
	if (pCon->usedSize == 0)
	{
		printf("ͨѶ¼��δ�洢��Ϣ\n");
		return ;
	}
	printf("%-6s%-6s%-6s%-15s%-20s\n","����","����","�Ա�","�绰","��ַ");
	for (i = 0; i < pCon->usedSize; i++)
	{
		printf("%-6s", pCon->per[i].name);
		printf("%-6d", pCon->per[i].age);
		printf("%-6s", pCon->per[i].sex);
		printf("%-15s", pCon->per[i].tele);
		printf("%-20s\n", pCon->per[i].addr);
	}
}

void ClearContact(Contact *pCon)
{
	assert(pCon != NULL);
	InitContact(pCon);
	printf("��ʼ���ɹ�\n");
}

void change(Contact *pCon, int i)
{
	char tmp[MAX_STR] = { 0 };
	int age = 0;
	{
		strcpy(tmp, pCon->per[i].addr);
		age = pCon->per[i].age;
		strcpy(tmp, pCon->per[i].name);
		strcpy(tmp, pCon->per[i].sex);
		strcpy(tmp, pCon->per[i].tele);
	}
	{
		strcpy(pCon->per[i].addr, pCon->per[i + 1].addr);
		pCon->per[i].age = pCon->per[i + 1].age;
		strcpy(pCon->per[i].name, pCon->per[i + 1].name);
		strcpy(pCon->per[i].sex, pCon->per[i + 1].sex);
		strcpy(pCon->per[i].tele, pCon->per[i + 1].tele);
	}
	{
		strcpy(pCon->per[i+1].addr, tmp);
		pCon->per[i+1].age = age;
		strcpy(pCon->per[i+1].name, tmp);
		strcpy(pCon->per[i+1].sex, tmp);
		strcpy(pCon->per[i+1].tele, tmp);
	}
}

void SortrContact(Contact *pCon)
{
	int i = 0;
	int j = 0;
	int folg = 0;
	for (i = 0; i < pCon->usedSize - 1; i++)
	{
		folg = 0;
		for (j = 0; j < pCon->usedSize - i - 1; j++)
		{
			if (strcmp(pCon->per[j].name, pCon->per[j + 1].name)>0)
			{
				folg = 1;
				change(pCon, j);
			}
		}
		if (folg == 0)
			break;
	}
	printf("����ɹ�\n");
}