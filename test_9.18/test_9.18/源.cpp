#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<malloc.h>


 struct ListNode {
     int val;
     struct ListNode *next;
 };

bool hasCycle(struct ListNode *head) {
	struct ListNode*fast, *slow;
	fast = slow = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
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


	hasCycle(l1);
	return 0;
}