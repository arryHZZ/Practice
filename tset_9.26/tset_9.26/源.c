#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode *fast = headA;
	struct ListNode *slow = headB;
	int count1, count2;
	count1 = count2 = 0;
	while (fast)
	{
		count1++;
		fast = fast->next;
	}
	while (slow)
	{
		count2++;
		slow = slow->next;
	}
	int num = 0;
	if (count1<count2)
	{
		fast = headB;
		slow = headA;
		num = count2 - count1;
	}
	else
	{
		fast = headA;
		slow = headB;
		num = count1 - count2;
	}
	while (num--)
	{
		fast = fast->next;
	}
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

//Î´±àĞ´²âÊÔ´úÂë