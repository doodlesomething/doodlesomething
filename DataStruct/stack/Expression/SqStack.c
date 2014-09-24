/*-------------------------------------------------------------------
	* file:SqStack.c
	* date:22-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:实现顺序栈的基本操作
--------------------------------------------------------------------*/


#include "sqstack.h"
#include <stdlib.h>


/*
* @description:初始化栈
*/

Status InitStack1(SqStack *S) {
	
	(*S).base = (SElemType *) malloc(INTSIZE * sizeof(SElemType));
	if(!(*S).base)
		exit(OVERFLOW);
	(*S).top = (*S).base;
	(*S).stacksize = INTSIZE;

	return OK;
}

/*
* @description:进栈
*/
Status Push1(SqStack *S,SElemType elem) {
	if((*S).top - (*S).base > (*S).stacksize ) {
		(*S).base =(SElemType *) realloc((*S).base,((*S).stacksize+INCREMENT_SIZE)*sizeof(SElemType));
		if(!(*S).base)
			exit(OVERFLOW);
		else {
			(*S).top = (*S).base + (*S).stacksize;
			(*S).stacksize += INCREMENT_SIZE;
		}
	}

	*(*S).top = elem;
	(*S).top++;

	return OK;
}

/*
* @description:出栈
*/
Status Pop1(SqStack *S,SElemType *elem) {
	if((*S).base == (*S).top)
		return ERROR;

	(*S).top--;
	(*elem) = *(*S).top;

	return OK;
}

/*
* @description:获取栈顶元素（不弹出）
*/
Status GetTop1(SqStack S,SElemType *elem) {
	if(S.base == S.top )
		return ERROR;
	
	(*elem) = * (S.top - 1);

	return OK;
}


