/*---------------------------------------------------------------
	* file:linkqueue.h -->head file for LinkQueue.c and test.c 
	* date:25-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:链队的基本操作
----------------------------------------------------------------*/

#include "comman.h"

#ifndef _LinkQueue_H

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

//返回长度
int QueueLength(LinkQueue Q);

//入队
Status EnQueue(LinkQueue *Q,QElemType elem);

//出队
Status DeQueue(LinkQueue *Q,QElemType *elem);

//销毁队列
void DestoryQueue(LinkQueue *Q);

//清空队列
void ClearQueue(LinkQueue Q);

//遍历数组 
Status QueueTraverse(LinkQueue Q,void (*visit) (QElemType));

//打印元素
void visit(QElemType elem);


//
void Push(LinkQueue *Q1,LinkQueue *Q2,QElemType elem);

QElemType Pop(LinkQueue *Q1,LinkQueue *Q2);


#endif
