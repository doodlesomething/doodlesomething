/*-------------------------------------------------------------------
	* file:test.c --->test file for SqStack.c 
	* date:22-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:实现顺序栈的基本操作
--------------------------------------------------------------------*/

#include <stdio.h>
#include "sqstack.h"

int main(int argc,char *argv[]){
	SqStack S;
	int pop_e,top_e;
	int i;

	InitStack(&S);
	printf("StackEmpty:%d\n",StackEmpty(S));
	for(i = 1; i < 6; i++) {
		Push(&S,i);
	}
	StackTraverse(S,visit);
	printf("\n");
	printf("StackLength:%d\n",StackLength(S));

	Pop(&S,&pop_e);
	StackTraverse(S,visit);
	printf("\n");
	GetTop(S,&top_e);
	printf("pop_e:%d, top_e:%d\n",pop_e,top_e);

	/*测试用例结果输入：
	StackEmpty:1
	5	4	3	2	1	
	StackLength:5
	4	3	2	1	
	pop_e:5, top_e:4

	*/
}
