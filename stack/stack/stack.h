typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top; // 栈顶
	int _capacity; // 容量
}Stack;

//初始化
void StackInit(Stack* ps);
//出栈
void StackDestory(Stack* ps);
//入栈
void StackPush(Stack* ps, STDataType x);
//获取栈顶元素
void StackTop(Stack* ps);
//检查容量
void StackEmpty(Stack* ps);
//获取栈的大小
int StackSize(Stack* ps);