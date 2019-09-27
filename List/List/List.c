#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
#include<assert.h>
#include<malloc.h>
#include<stdio.h>
//初始化
void InitList(List* list)
{
	assert(list);
	list->UseSize = 0;
	list->_arr = (int *)malloc(sizeof(int)* 5);
}

//插入、删除,
void ListPopback(List* list)
{
	assert(list);
	if (list->UseSize)
		list->UseSize--;
}

void ListPushback(List* list, int x)
{
	assert(list);
	ListCheck(list);
	list->_arr[list->UseSize++] = x;
}

void ListPopFront(List* list)
{
	assert(list);
	int i = 1;
	if (list->UseSize == 0)
		return;
	for (i; i < list->UseSize; i++)
	{
		list->_arr[i-1] = list->_arr[i];
	}
	list->UseSize--;
}

void ListPushFront(List* list, int x)
{
	assert(list);
	ListCheck(list);
	int i = list->UseSize;
	if (list->UseSize != 0)
	{
		for (i; i > 0; i--)
		{
			list->_arr[i] = list->_arr[i - 1];
		}
	}
	list->_arr[0] = x;
	list->UseSize++;
}


//检查容量
void ListCheck(List* list)
{
	assert(list);
	if (list->UseSize == list->arrSize)
	{
		list->_arr = (int *)realloc(list->_arr,sizeof(int)*list->arrSize * 2);
	}
}
//打印
void ListPrint(List* list)
{
	int i = 0;
	for (i; i < list->UseSize; i++)
	{
		printf("%d ", list->_arr[i]);
	}
	printf("\n");
}
void ListDestroy(List* list)
{
	free(list->_arr);
	free(list);
}

void test()
{
	List list;
	InitList(&list);
	ListPushback(&list, 1);
	ListPushback(&list, 2);
	ListPushback(&list, 3);
	ListPushback(&list, 4);
	//ListPopback(&list);
	//ListPopback(&list); 
	//ListPopback(&list);
	//ListPopback(&list);
	//ListPopback(&list);
	//ListPopback(&list);
	//ListPrint(&list);
	//ListPushFront(&list, 1);
	//ListPushFront(&list, 2);
	//ListPushFront(&list, 3);
	//ListPushFront(&list, 4);
	//ListPushFront(&list, 5);
	//ListPushFront(&list, 5);
	//ListPushFront(&list, 5);
	//ListPopFront(&list);
	//ListPrint(&list);
	//ListPopFront(&list);
	//ListPrint(&list);
	//ListPopFront(&list);
	//ListPrint(&list);
	//ListPopFront(&list);
	//ListPrint(&list);
	//ListPopFront(&list);
	//ListPrint(&list);
	//ListPopFront(&list);
	//ListPopFront(&list);
	//ListPrint(&list);

	ListDestroy(&list);

}
int main()
{
	test();
	return 0;
}