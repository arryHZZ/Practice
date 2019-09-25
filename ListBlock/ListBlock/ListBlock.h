

typedef struct ListNode
{
	int date;
	struct ListNode* next;
}ListNode;

typedef struct List
{
	ListNode* head;
}List;
//创建节点
ListNode* SListCreatNode(int x);
//初始化
void SListInit (List* plist);
//头插，头删
void SListPushFront (List* plist, int x);
void SListPopFront (List* plist);
//尾插，尾删
void SListPushBake(List* plist, int x);
void SListPopFBake(List* plist);
//销毁
void SListDestory (List* plist);
//逆置
void SListReverse(List* plist);
//打印
void SListPrint(List* plist);