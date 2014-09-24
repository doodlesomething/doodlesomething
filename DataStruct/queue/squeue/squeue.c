/*---------------------------------------------------------------------
	* file:squeue.c 
	* date:24-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:数组实现队列的基本操作
-----------------------------------------------------------------------*/

#include <stdlib.h>
#include "squeue.h"



/*
* @description:初始化队列
*/
Status InitQueue(Queue *Q) {
	(*Q).elem = (ElemType *) malloc(QUEUE_SIZE * (sizeof(ElemType)));
	if(!(*Q).elem)
		exit(OVERFLOW);

	(*Q).capacity = QUEUE_SIZE;
	(*Q).font = 0;
	(*Q).rear = 0;
	(*Q).size = 0;

	return OK;
}


/*
* @description:判空
*/
Status QueueEmpty(Queue Q)  {
	return Q.size == 0;
}

/*
* @description:队列长度
*/
int QueueLength(Queue Q) {
	return Q.size;
}

/*
* @description:队列是否满
*/
Status QueueFull(Queue Q) {
	return Q.size == Q.capacity; 
}

/*
* @实现循环数组 即当头指针和尾指针到达数组临界时，
  而此时队列的前面已经有元素被出队了，则此时应将
  头指针或尾指针置为0
*/
int ReSet(int value,Queue Q) {
	if(++value == Q.capacity ) 
		value = 0;

	return value;
}


/*
* @description:从队尾插入元素
*/
Status EnQueue(Queue *Q,ElemType e) {
	if(QueueFull(*Q))
		return ERROR;
	

	(*Q).elem[(*Q).rear] = e;
	(*Q).size++;
	(*Q).rear = ReSet((*Q).rear,*Q);

	return OK;
}	

/*
* @description:删除队头元素
*/
Status DeQueue(Queue *Q,ElemType *e)  {
	if(QueueEmpty(*Q))
		return ERROR;
	
	(*e) = (*Q).elem[(*Q).font];
	(*Q).size--;
	(*Q).font = ReSet((*Q).font,*Q);

	return OK;
}


/*
* @遍历队列元素
*/
Status QueueTraverse(Queue Q,void (*visit) (ElemType)) {
	int i;

	if(QueueEmpty(Q))
		return ERROR;
	
	for(i = 0; i < Q.size; i++) 
		visit(Q.elem[i]);

	return OK;
}


/*
* @description:打印元素
*/
void visit(ElemType elem) {
	printf("%d\t",elem);
}
