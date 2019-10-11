#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"
#include<assert.h>
#include<malloc.h>
#include<stdio.h>

//初始化
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)* 10);
	ps->_top = 0;
	ps->_capacity = 10;
}

//销毁栈
void StackDestory(Stack* ps)
{
	free(ps->_a);
	free(ps);
}
//入栈
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	StackEmpty(ps);
	ps->_a[ps->_top] = x;
	ps->_top++;
}
//出栈
void StackTop(Stack* ps)
{
	assert(ps);
	if (!ps->_top)
		return;
	--ps->_top;
	printf("%d ", ps->_a[ps->_top]);

}
//检查容量
void StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		ps->_a = (STDataType*) realloc (ps->_a,sizeof(STDataType)* ps->_capacity*2);
		ps->_capacity = 2 * ps->_capacity;
	}
}
//获取栈的大小
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

void test()
{
	Stack MyStack;
	StackInit(&MyStack);
	StackPush(&MyStack, 1);
	StackPush(&MyStack, 2);
	StackPush(&MyStack, 3);
	StackPush(&MyStack, 4);
	StackPush(&MyStack, 5);
	StackTop(&MyStack);
	StackTop(&MyStack);
	StackTop(&MyStack);
	StackTop(&MyStack);
	StackTop(&MyStack);
	StackTop(&MyStack);	
}

int main()
{
	test();
	return 0;
}