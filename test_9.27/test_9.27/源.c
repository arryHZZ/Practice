#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;

struct ListNode* creatNode(int x)
{
	struct ListNode *p = (struct ListNode*) malloc(sizeof(struct ListNode));
	p->val = x;
	p->next = NULL;
	return p;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	int sum = 0;
	int next = 0;
	struct ListNode *head = NULL;
	struct ListNode *end = NULL;
	while (l1&&l2)
	{
		sum = l1->val + l2->val + next;
		next = sum / 10;
		sum = sum % 10;
		if (head == NULL)
		{
			head = creatNode(sum);
			end = head;
		}
		else
		{
			end->next = creatNode(sum);
			end = end->next;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	if (l1)
	{
		while (l1)
		{
			sum = l1->val + next;
			next = sum / 10;
			sum = sum % 10;
			end->next = creatNode(sum);
			end = end->next;
			//next = 0;
			l1 = l1->next;
		}
	}
	else if (l2)
	{
		while (l2)
		{
			sum = l2->val + next;
			next = sum / 10;
			sum = sum % 10;

			end->next = creatNode(sum);
			end = end->next;
			//next = 0;
			l2 = l2->next;
		}
	}
	if (next)
	{
		end->next = creatNode(next);
	}
	return head;
}

int main()
{
	ListNode *l1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *l2 = (ListNode*)malloc(sizeof(ListNode));
	l1->val = 9;
	l1->next = (ListNode*)malloc(sizeof(ListNode));
	l1->next->val = 9;
	l1->next->next = NULL;
	//l1->next->next = (ListNode*)malloc(sizeof(ListNode));
	//l1->next->next->val = 6;
	//l1->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	//l1->next->next->next->val = 4;
	//l1->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	//l1->next->next->next->next->val = 5;
	//l1->next->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	//l1->next->next->next->next->next->val = 6;
	//l1->next->next->next->next->next->next = NULL;
	l2->val = 1;
	l2->next = NULL;
	addTwoNumbers(l1, l2);
	return 0;
}