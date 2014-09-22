
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
	LinkStack S;
	int i;
	int pop_e,top_e;

	InitStack(&S);
	for(i = 1; i < 6; i++) {
		Push(&S,i);
	}
	StackTraverse(S,visit);
	printf("\n");

	printf("StackEmpty:%d, StackLength:%d\n",StackEmpty(S),StackLength(S));

	Pop(&S,&pop_e);
	printf("pop_e:%d\n",pop_e);
	GetTop(S,&top_e);
	printf("top_e:%d\n",top_e);
	ClearStack(&S);
	printf("StackEmpty:%d, StackLength:%d\n",StackEmpty(S),StackLength(S));
	/*测试用例结果：
	5	4	3	2	1	
	StackEmpty:0, StackLength:5
	pop_e:5
	top_e:4
	StackEmpty:1, StackLength:0

	*/

}
