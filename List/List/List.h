#define N 5
typedef struct List
{
	int UseSize;
	int arrSize;
	int *_arr;
}List;


//��ʼ��
void InitList(List * list);
//
void ListPopback(List* list);
void ListPopFront(List* list);
void ListPushback(List* list, int x);
void ListPushFront(List* list, int x);
//�������
void ListCheck(List* list);
//��ӡ
void ListPrint(List* list);
//����
void ListDestroy(List* list);
