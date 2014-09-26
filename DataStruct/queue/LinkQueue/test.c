/*---------------------------------------------------------------
	* file:LinkQueue.c 
	* date:25-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:链队的基本操作
----------------------------------------------------------------*/

#include <stdio.h>
#include "linkqueue.h"

int main() {
	
	LinkQueue Q,Q1;
	int i;

	InitQueue(&Q);
	InitQueue(&Q1);

	for(i = 0; i < 6;i++)
		EnQueue(&Q,i);
	Push(&Q,&Q1,7);
	QueueTraverse(Q,visit);
	printf("\n%d\n",Pop(&Q,&Q1));
	QueueTraverse(Q,visit);

	printf("\nLength:%d,Empty:%d\n",QueueLength(Q),QueueEmpty(Q));
	

	/*
	测试用例结果：
	0 1 2 3 4 5 7
	0 1 2 3 4 5 
	7 
	6 0
	*/
}




