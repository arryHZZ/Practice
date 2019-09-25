#define _CRT_SECURE_NO_WARNINGS
#include"ListBlock.h"
#include<malloc.h>
#include<stdio.h>
#include<assert.h>

//创建节点
ListNode* SListCreatNode(int x)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->date = x;
	p->next = NULL;
	return p;
}

//初始化
void SListInit(List* plist)
{
	plist->head = NULL;
}

//头插，头删
void SListPushFront(List* plist, int x)
{
	assert(plist);
	ListNode* next = plist->head;
	ListNode* NewNode = SListCreatNode(x);
	NewNode->next = next;
	plist->head = NewNode;
}

void SListPopFront(List* plist)
{
	assert(plist);
	ListNode *newHead = NULL;
	if (plist->head != NULL)
	{
		newHead = plist->head->next;
	}
	if (plist->head)
	{
		free(plist->head);
		plist->head = newHead;
	}
}

//尾插，尾删
void SListPushBake(List* plist, int x)
{
	assert(plist);
	ListNode *newNode = SListCreatNode(x);
	ListNode *Node = NULL;
	if (plist->head == NULL)
	{
		plist->head = newNode;
	}
	else
	{
		Node = plist->head;
		while (Node->next)
		{
			Node = Node->next;
		}
		Node->next = newNode;
	}
}

void SListPopFBake(List* plist)
{
	assert(plist);
	ListNode *Node = plist->head;
	ListNode *prev = plist->head;
	if (Node)
	{
		while (Node->next)
		{
			prev = Node;
			Node = Node->next;
		}
		if (prev->next == NULL)
		{
			plist->head = NULL;
			free(prev);
		}
		else
		{
			prev->next = NULL;
			free(Node);
		}
	}
}
//销毁
void SListDestory(List* plist)
{
	assert(plist);
	ListNode *Node = plist->head;
	ListNode *cur = plist->head;
	while (Node)
	{
		cur = Node;
		Node = Node->next;
		free(cur);
	}
	plist->head = NULL;
}
//逆置
void SListReverse(List* plist)
{
	ListNode* p1, *p2, *p3;
	if (plist->head == NULL || plist->head->next == NULL)
		return;
	p1 = plist->head;
	p2 = plist->head->next;
	p3 = plist->head->next->next;
	while (p2 != NULL)
	{
		p3 = p2->next;
		p2->next = p1;
		if (p1 == plist->head)
			p1->next = NULL;
		p1 = p2;
		p2 = p3;

	}
	plist->head = p1;
}
//打印
void SListPrint(List* plist)
{
	assert(plist);
	ListNode *p = plist->head;
	while (p != NULL)
	{
		printf("%d->", p->date);
		p = p->next;
	}
	printf("\n");
}

void ListTest()
{
	List list;
	SListInit(&list);

	SListPushBake(&list, 1);
	SListPushBake(&list, 2);
	SListPushBake(&list, 3);
	SListPushBake(&list, 4);
	SListPushBake(&list, 5);
	SListPrint(&list);
	SListReverse(&list);
	SListPrint(&list);
	//SListPopFBake(&list);
	//SListPrint(&list);
	//SListPopFBake(&list);
	//SListPrint(&list);
	//SListPopFBake(&list);
	//SListPrint(&list);
	//SListPopFBake(&list);
	//SListPrint(&list);
	//SListPopFBake(&list);
	//SListPrint(&list);
	//SListPopFBake(&list);
	//SListPrint(&list);

	//SListDestory(&list);


	//SListPushFront(&list, 1);
	//SListPushFront(&list, 2);
	//SListPushFront(&list, 3);
	//SListPushFront(&list, 4);
	//SListPushFront(&list, 5);
	//SListPrint(&list);
	//SListPopFront(&list);
	//SListPrint(&list);
	//SListPopFront(&list);
	//SListPrint(&list);
	//SListPopFront(&list);
	//SListPrint(&list);
	//SListPopFront(&list);
	//SListPrint(&list);
	//SListPopFront(&list);
	//SListPrint(&list);
	//SListPopFront(&list);
	//SListPrint(&list);
}

int main()
{
	ListTest();
	return 0;
}