#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


 struct ListNode {
     int val;
     struct ListNode *next;
 };



struct ListNode* deleteDuplicates(struct ListNode* head){
	struct ListNode *per, *cur;
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *next = head;
	per = head;
	cur = head->next;
	while (cur != NULL)
	{
		if (per->val == cur->val)
		{
			next = cur;
			per->next = cur->next;
			cur = cur->next;
			free(next);
		}
		else
		{
			per = per->next;
			cur = cur->next;
		}
	}
	return head;
}
//int maxNumberOfBalloons(char * text){
//	int ascii[256] = { 0 };
//	if (text == NULL)
//		return text;
//	char *p = text;
//	while (*p != '\0')
//	{
//		++ascii[*p];
//		p++;
//	}
//	ascii['l'] = ascii['l'] / 2;
//	ascii['o'] = ascii['o'] / 2;
//	int min = ascii['b'];
//	char arr[] = "balon";
//	int i = 0;
//	while (arr[i] != '\0')
//	{
//		if (ascii[arr[i]]<min)
//			min = ascii[arr[i]];
//		i++;
//	}
//	return min;
//}

int main()
{
	char text[] = "ballon";
	maxNumberOfBalloons(text);
	return 0;
}