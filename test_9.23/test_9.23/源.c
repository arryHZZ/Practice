#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct ListNode {
     int val;
     struct ListNode *next;
 }ListNode;



struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	struct ListNode* per = head;
	while (n--)
	{
		fast = fast->next;
	}
	while (fast != NULL)
	{
		per = slow;
		fast = fast->next;
		slow = slow->next;
	}
	if (slow == head)
		return head->next;
	per->next = slow->next;
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


	removeNthFromEnd(l1, 2);
	return 0;
}