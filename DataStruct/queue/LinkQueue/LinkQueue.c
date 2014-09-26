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
* @description:入队
*/
Status EnQueue(LinkQueue *Q,ElemType elem) {
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
Status DeQueue(LinkQueue *Q,ElemType *elem) {
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
Status QueueTraverse(LinkQueue Q,void (*visit) (ElemType)) {
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
void visit(ElemType elem) {
	printf("%d\t",elem);
}






/*
* @description:两个队列q1,q2实现一个栈的功能（两个队列足够大，不出现队满的情况）
* @more:栈的特性是先进后出，举一个序列1,2,3,4来说，我们试着往一个queue1里面push进去，这时候queue1的队头是1，队尾是4，这时候要实现delete的话，对应的栈应该删除4，对于queue1的队尾，前面的1,2,3，都是不需要的。
实现dalete解决方法就是，依次弹出1,2,3并且压入queue2中，queue1里面只保存4，这时候要delete_head的话，对queue1进行pop操作就行了，然后queue1为空（注意这个状态）,然后我要继续delete,这个时候也是按照上面的思路，将queue2的1,2依次弹出，压入queue1里面，知道剩下最后一个队尾元素3，将它pop掉就行了！这时候的状态是queue1不为空，queue2为空。
实现append的话也容易。注意上面的删除头以后的两种状态其实可以可以归结为一种，那就是其中一个queue为空，另一个可以为空（这个时候模拟的stack就是空），或者不为空，append来说，只需往非空的queue里面添到队尾就行了，若是都为空，随便选一个即可

*/
void Push(LinkQueue *Q1,LinkQueue *Q2,ElemType elem) {
	LinkQueue *p,*q;

	if(QueueEmpty(*Q1)) {
		p = Q2;
		q = Q1;
	}
	else {
		p = Q1;
		q = Q2;
	}
	
	EnQueue(p,elem);
}

ElemType Pop(LinkQueue *Q1,LinkQueue *Q2) {
	ElemType elem;
	LinkQueue *p,*q;

	if(QueueEmpty(*Q1)) {
		p = Q2;
		q = Q1;
	}
	else {
		p = Q1;
		q = Q2;
	}

	if(QueueEmpty(*Q1) && QueueEmpty(*Q2))
		exit(OVERFLOW);

	while(QueueLength(*p) != 1) {
		DeQueue(p,&elem);
		EnQueue(q,elem);
	}
	
	DeQueue(p,&elem);
	
	return elem;
}
