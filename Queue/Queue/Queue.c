#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

//初始化
void QueueInit(Queue* pq)
{	
	pq->_front = pq->_rear = NULL;
}

//销毁队
void QueueDestory(Queue* pq);

//创建节点
QueueNode* CreatQueueNode(QUDataType x)
{
	QueueNode* NewNode;
	NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	NewNode->_data = x;
	NewNode->_next = NULL;
}
//入队
void QueuePush(Queue* pq, QUDataType x)
{
	if (pq->_front == NULL)
	{
		pq->_rear = pq->_front = CreatQueueNode(x);
	}
	else
	{
		pq->_rear->_next = CreatQueueNode(x);
		pq->_rear = pq->_rear->_next;
	}
}
//出队
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* next;
	if (!pq->_front)
		return;
	next = pq->_front->_next;
	printf("%d ", pq->_front->_data);
	free(pq->_front);
	pq->_front = next;
}
//获取对头元素
QUDataType QueueFront(Queue* pq)
{
	assert(pq->_front);
	return pq->_front->_data;
}
//获取队尾元素
QUDataType QueueBack(Queue* pq)
{
	assert(pq->_front&&pq->_rear);
	return pq->_rear->_data;
}
//检查队是否为空
int QueueEmpty(Queue* pq)
{
	if (pq->_front == NULL)
		return 0;
	else
		return 1;
}
//返回队的长度
int QueueSize(Queue* pq)
{
	//assert(pq->_front);
	int count = 0;
	QueueNode *Node = pq->_front;
	while (Node)
	{
		count++;
		Node = Node->_next;
	}
	return count;
}

void test()
{
	Queue MyQueue;
	QueueInit(&MyQueue);
	QueuePush(&MyQueue, 1);
	QueuePush(&MyQueue, 2);
	QueuePush(&MyQueue, 3);
	QueuePush(&MyQueue, 4);
	QueuePush(&MyQueue, 5);
	printf("%d ", QueueSize(&MyQueue));
	QueuePop(&MyQueue);
	printf("%d ", QueueSize(&MyQueue));
	QueuePop(&MyQueue);
	printf("%d ", QueueSize(&MyQueue));
	QueuePop(&MyQueue);
	printf("%d ", QueueSize(&MyQueue));
	QueuePop(&MyQueue);
	printf("%d ", QueueSize(&MyQueue));
	QueuePop(&MyQueue);
	printf("%d ", QueueSize(&MyQueue));
	QueuePop(&MyQueue);
	printf("%d ", QueueSize(&MyQueue));
	/*QueuePush(&MyQueue, 1);
	QueuePush(&MyQueue, 2);
	QueuePush(&MyQueue, 3);
	QueuePush(&MyQueue, 4);
	QueuePush(&MyQueue, 5);
	QueuePop(&MyQueue);
	QueuePop(&MyQueue);
	QueuePop(&MyQueue);
	QueuePop(&MyQueue);
	QueuePop(&MyQueue);
	QueuePop(&MyQueue);*/

}

int main()
{
	test();
	return 0;
}