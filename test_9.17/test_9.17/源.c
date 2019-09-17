#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct ListNode {
     int val;
     struct ListNode *next;
 }ListNode;



struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* p1, *p2, *p3;
	if (head->next == NULL)
		return head;
	p1 = head;
	p2 = head->next;
	p3 = head->next->next;
	while (p2 != NULL)
	{
		p3 = p2->next;
		p2->next = p1;
		if (p1 == head)
			p1->next = NULL;
		p1 = p2;
		p2 = p3;

	}
	return p1;
}

int main()
{
	ListNode A = { 0 };
	ListNode B = { 0 };
	ListNode *l1 = &A;
	ListNode *l2 = &B;
	l1->val = 1;
	l1->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->val = 2;
	//l1->next->next= NULL;
	l1->next->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->next->val = 3;
	l1->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->next->next->val = 4;
	l1->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->next->next->next->val = 5;
	l1->next->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->next->next->next->next->val = 6;
	l1->next->next->next->next->next->next = NULL;


	reverseList(l1);
	return 0;
}