
/*--------------------------------------------------------------
	*file:ListStack.c
	*date:22-9-2014
	*author:doodlesomething@163.com
	*version:1.0
	*description:链栈的基本操作
----------------------------------------------------------------*/

#include "liststack.h"
#include <stdio.h>

int main(int argc,char *argv[]) {
	LinkStack S,S1;
	int i;
	int pop_e,top_e;

	InitStack(&S);
	InitStack(&S1);
	for(i = 1; i < 6; i++) {
		Push(&S,i);
	}
	StackTraverse(S,visit);
	printf("\n");

	InsertQueue(&S,6);
	InsertQueue(&S,7);
	InsertQueue(&S,8);
	StackTraverse(S,visit);
	printf("\n%d\n",DeleQueue(&S,&S1));
	StackTraverse(S,visit);


	/*
	测试用例结果：
	5 4 3 2 1
	8 7 6 5 4 3 2 1
	1
	*/

}
