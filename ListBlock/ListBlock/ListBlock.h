

typedef struct ListNode
{
	int date;
	struct ListNode* next;
}ListNode;

typedef struct List
{
	ListNode* head;
}List;
//�����ڵ�
ListNode* SListCreatNode(int x);
//��ʼ��
void SListInit (List* plist);
//ͷ�壬ͷɾ
void SListPushFront (List* plist, int x);
void SListPopFront (List* plist);
//β�壬βɾ
void SListPushBake(List* plist, int x);
void SListPopFBake(List* plist);
//����
void SListDestory (List* plist);
//����
void SListReverse(List* plist);
//��ӡ
void SListPrint(List* plist);