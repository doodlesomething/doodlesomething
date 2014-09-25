/*---------------------------------------------------------------
	* file:LinkQueue.c 
	* date:25-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:链队的基本操作
----------------------------------------------------------------*/

#include <stdio.h>
#include "linkqueue.h"

int main(int argc,char *argv[]) {
	LinkQueue Q;
	int i;

	InitQueue(&Q);
	for(i = 0; i < 6;i++)
		EnQueue(&Q,i);
	
	QueueTraverse(Q,visit);
	printf("\nLength:%d,Empty:%d\n",QueueLength(Q),QueueEmpty(Q));

}




