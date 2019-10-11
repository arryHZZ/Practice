typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top; // ջ��
	int _capacity; // ����
}Stack;

//��ʼ��
void StackInit(Stack* ps);
//��ջ
void StackDestory(Stack* ps);
//��ջ
void StackPush(Stack* ps, STDataType x);
//��ȡջ��Ԫ��
void StackTop(Stack* ps);
//�������
void StackEmpty(Stack* ps);
//��ȡջ�Ĵ�С
int StackSize(Stack* ps);