typedef int QUDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front; // ��ͷ
	QueueNode* _rear; // ��β
}Queue;

//��ʼ��
void QueueInit(Queue* pq);
//���ٶ�
void QueueDestory(Queue* pq);
//���
void QueuePush(Queue* pq, QUDataType x);
//����
void QueuePop(Queue* pq);
//��ȡ��ͷԪ��
QUDataType QueueFront(Queue* pq);
//��ȡ��βԪ��
QUDataType QueueBack(Queue* pq);
//�����Ƿ�Ϊ��
int QueueEmpty(Queue* pq);
//���ضӵĳ���
int QueueSize(Queue* pq);