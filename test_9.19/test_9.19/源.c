#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<malloc.h>


typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;

struct ListNode* middleNode(struct ListNode* head){
	if (head == NULL&&head->next == NULL)
		return head;
	struct ListNode *slow;
	struct ListNode *fast;
	slow = head;
	fast = head;
	while (fast != NULL&&fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		fast = fast->next;
	}
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
	middleNode(l1);
	return 0;
}