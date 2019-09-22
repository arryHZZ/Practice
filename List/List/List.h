#define N 5
typedef struct List
{
	int UseSize;
	int arrSize;
	int *_arr;
}List;


//初始化
void InitList(List * list);
//
void ListPopback(List* list);
void ListPopFront(List* list);
void ListPushback(List* list, int x);
void ListPushFront(List* list, int x);
//检查容量
void ListCheck(List* list);
//打印
void ListPrint(List* list);
//销毁
void ListDestroy(List* list);
