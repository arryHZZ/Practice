typedef int QUDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front; // 队头
	QueueNode* _rear; // 队尾
}Queue;

//初始化
void QueueInit(Queue* pq);
//销毁队
void QueueDestory(Queue* pq);
//入队
void QueuePush(Queue* pq, QUDataType x);
//出队
void QueuePop(Queue* pq);
//获取对头元素
QUDataType QueueFront(Queue* pq);
//获取队尾元素
QUDataType QueueBack(Queue* pq);
//检查队是否为空
int QueueEmpty(Queue* pq);
//返回队的长度
int QueueSize(Queue* pq);