#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;



struct ListNode* rotateRight(struct ListNode* head, int k){
	struct ListNode *ph = head;
	int count = 0;
	if (head == NULL)
		return head;
	while (ph != NULL)
	{
		ph = ph->next;
		count++;
	}
	k = k % count;
	if (k == 0)
		return head;
	ph = head;
	struct ListNode *prev = head;
	struct ListNode *fast = head;
	struct ListNode *slow = head;
	while (--k)
	{
		fast = fast->next;
	}
	while (fast->next != NULL)
	{
		prev = slow;
		fast = fast->next;
		slow = slow->next;
	}
	prev->next = NULL;
	fast->next = head;
	return slow;

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


	rotateRight(l1, 2);
	return 0;
}