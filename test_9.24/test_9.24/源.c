#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;



struct ListNode* deleteDuplicates(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* p1 = head;
	struct ListNode* p2 = head->next;
	while (p2&&p1->val == p2->val)
	{
		p2 = p2->next;
		if (p2&&p2->next&&p1->val != p2->val)
		{
			p1 = p2;
			head = p1;
			if (p2->next)
				p2 = p2->next;
		}
	}
	if (p2 != head->next)
		head = p2;
	if (head == NULL || head->next == NULL || head->next->next == NULL)
		return head;
	struct ListNode* prev, *cur, *next;
	prev = head;
	cur = head->next;
	next = cur->next;
	while (next != NULL)
	{
		if (next->val != cur->val)
		{
			prev = prev->next;
			cur = prev->next;
			next = cur->next;
		}
		else
		{
			while (next&&cur->val == next->val)
			{
				next = next->next;
			}
			prev->next = next;
			cur = prev->next;
			if (next)
				next = cur->next;
		}
	}
	return head;
}

int main()
{
	ListNode A = { 0 };
	ListNode B = { 0 };
	ListNode *l1 = &A;
	ListNode *l2 = &B;
	l1->val = 1;
	l1->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->val = 1;
	//l1->next->next= NULL;
	l1->next->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->next->val = 2;
	l1->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->next->next->val = 3;
	l1->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->next->next->next->val = 3;
	l1->next->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->next->next->next->next->val = 3;
	l1->next->next->next->next->next->next = NULL;
	deleteDuplicates(l1);
	return 0;
}