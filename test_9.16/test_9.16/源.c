#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct ListNode{
     int val;
     struct ListNode *next;
 }ListNode;



//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//	struct ListNode* pb, *head;
//	head = pb = NULL;
//	if (l1 == NULL)
//		return l2;
//	if (l2 == NULL)
//		return l1;
//	while (l1 != NULL && l2 != NULL)
//	{
//		if (l1->val < l2->val)
//		{
//			if (pb == NULL)
//			{
//				head = pb = l1;
//			}
//			else
//			{
//				pb->next = l1;
//				pb = pb->next;
//			}
//			l1 = l1->next;
//		}
//		else
//		{
//			if (pb == NULL)
//			{
//				head = pb = l2;
//			}
//			else{
//				pb->next = l2;
//				pb = pb->next;
//			}
//			l2 = l2->next;
//		}
//	}
//	if (l2 == NULL)
//	{
//		pb->next = l1;
//	}
//	if (l1 == NULL)
//	{
//		pb->next = l2;
//	}
//	return head;
//}
struct ListNode* partition(struct ListNode* head, int x){
	struct ListNode *bp, *bl, *sp, *sl, *cur, *p;
	p = NULL;
	bl = bp = (struct ListNode *)malloc(sizeof(struct ListNode));
	sl = sp = (struct ListNode *)malloc(sizeof(struct ListNode));
	cur = head;
	while (cur != NULL)
	{
		if (cur->val < x)
		{
			sl->next = cur;
			sl = sl->next;
		}
		else
		{
			bl->next = cur;
			bl = bl->next;
		}
		cur = cur->next;
	}
	bl->next = NULL;
	sl->next = bp->next;
	p = sp->next;
	free(bp);
	free(sp);
	return p;
}

int main()
{
	ListNode A = { 0 };
	ListNode B = { 0 };
	ListNode *l1 = &A;
	ListNode *l2 = &B;
	l1->val = 1;
	l1->next = (ListNode* )malloc(sizeof(ListNode));
	l1->next->val = 4;
	l1->next->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->next->val = 3;
	l1->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->next->next->val = 2;
	l1->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->next->next->next->val = 5;
	l1->next->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->next->next->next->next->val = 2;
	l1->next->next->next->next->next->next = NULL;


	partition(l1, 3);
	return 0;
}