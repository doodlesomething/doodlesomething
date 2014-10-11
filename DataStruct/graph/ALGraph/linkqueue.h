/*---------------------------------------------------------------
	* file:linkqueue.h -->head file for LinkQueue.c and test.c 
	* date:25-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:链队的基本操作
----------------------------------------------------------------*/


#define  TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int QElemType;

typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr font;
	QueuePtr rear;
}LinkQueue;


//初始化队列
Status InitQueue(LinkQueue *Q);

//判空
Status QueueEmpty(LinkQueue Q);

//入队
Status EnQueue(LinkQueue *Q,QElemType elem);

//出队
Status DeQueue(LinkQueue *Q,QElemType *elem);

