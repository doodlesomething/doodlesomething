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
typedef int ElemType;

typedef struct QNode{
	ElemType data;
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

//返回长度
int QueueLength(LinkQueue Q);

//入队
Status EnQueue(LinkQueue *Q,ElemType elem);

//出队
Status DeQueue(LinkQueue *Q,ElemType *elem);

//销毁队列
void DestoryQueue(LinkQueue *Q);

//清空队列
void ClearQueue(LinkQueue Q);

//遍历数组 
Status QueueTraverse(LinkQueue Q,void (*visit) (ElemType));

//打印元素
void visit(ElemType elem);
