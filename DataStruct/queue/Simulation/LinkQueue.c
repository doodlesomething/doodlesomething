/*---------------------------------------------------------------
	* file:LinkQueue.c 
	* date:25-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:链队的基本操作
----------------------------------------------------------------*/


#include <stdlib.h>
#include "linkqueue.h"


/*
* @description:初始化链队
*/
Status InitQueue(LinkQueue *Q) {
	(*Q).font = (QueuePtr) malloc(sizeof(QNode));

	if(!(*Q).font)
		exit(OVERFLOW);
	
	(*Q).rear = (*Q).font;

	(*Q).font->next = NULL;

	return OK;
}


/*
* @description:判空
*/
Status QueueEmpty(LinkQueue Q) {
	return Q.font == Q.rear;
}


/*
* @description:取长
*/
int QueueLength(LinkQueue Q) {
	QueuePtr p;
	int len;

	p = Q.font->next;
	len = 0;

	while(p) {
		len++;
		p = p->next;
	}

	return len;
}

/*
* @description:返回队头元素
*/
Status GetHead(LinkQueue Q,QElemType *elem) {
	if(QueueEmpty(Q))
		return ERROR;

	(*elem) = Q.font->data;

	return OK;
}


/*
* @description:入队
*/
Status EnQueue(LinkQueue *Q,QElemType elem) {
	QueuePtr p;

	p = (QueuePtr) malloc(sizeof(QNode));

	if(!p)
		exit(OVERFLOW);
	
	p->data = elem;
	p->next = NULL;
	(*Q).rear->next = p;
	(*Q).rear = p;


	return OK;
}

/*
* @description:出队
*/
Status DeQueue(LinkQueue *Q,QElemType *elem) {
	if(QueueEmpty(*Q))
		return ERROR;
	
	QueuePtr p,tmp;

	p = (*Q).font;

	tmp = p->next;
	p->next = tmp->next;
	(*elem) = tmp->data;

	//注意当删除的是最后一个元素时，应该将队尾指针指向头结点
	if(tmp == (*Q).rear)
		(*Q).rear = (*Q).font;	

	free(tmp);

	return OK;
}


/*
* @description:销毁队列
*/
void DestoryQueue(LinkQueue *Q) {
	QueuePtr p,tmp;

	p = (*Q).font;

	while(p) {
		tmp = p->next;
		free(p);
		p = tmp;
	}
}


/*
* @description:清空队列
*/
void  ClearQueue(LinkQueue Q) {
	QueuePtr p,tmp;

	p = Q.font->next;

	while(p) {
		tmp = p->next;
		free(p);
		p = tmp;
	}
}


/*
* @description:遍历链队
*/
Status QueueTraverse(LinkQueue Q,void (*visit) (QElemType)) {
	QueuePtr p;

	if(QueueEmpty(Q))
		return ERROR;
	
	p = Q.font->next;
	while(p) {
		visit(p->data);
		p = p->next;
	}

	return OK;
}

//打印元素
void visitQueue(QElemType elem) {
	printf("%d:%d\t",elem.ArrivalTime,elem.Duration);
}
