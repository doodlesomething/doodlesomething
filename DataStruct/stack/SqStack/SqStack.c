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

Status InitStack(SqStack *S) {
	
	(*S).base = (SElemType *) malloc(INTSIZE * sizeof(SElemType));
	if(!(*S).base)
		exit(OVERFLOW);
	(*S).top = (*S).base;
	(*S).stacksize = INTSIZE;

	return OK;
}

/*
* @description:判空
*/
Status StackEmpty(SqStack S) {
	return S.base == S.top ? TRUE : FALSE;
}


/*
* @description:栈长
*/
int StackLength(SqStack S) {
	return S.top - S.base;	
}

/*
* @description:进栈
*/
Status Push(SqStack *S,SElemType elem) {
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
Status Pop(SqStack *S,SElemType *elem) {
	if((*S).base == (*S).top)
		return ERROR;

	(*S).top--;
	(*elem) = *(*S).top;

	return OK;
}

/*
* @description:获取栈顶元素（不弹出）
*/
Status GetTop(SqStack S,SElemType *elem) {
	if(S.base == S.top )
		return ERROR;
	
	(*elem) = * (S.top - 1);

	return OK;
}

/*
* @description:遍历所有栈元素
*/
void StackTraverse(SqStack S,void (*visit) (SElemType)) {
	while(S.base != S.top ) {
		S.top--;
		visit(*S.top);
	}
}

/*
* @description 打印栈元素
*/
void visit(SElemType elem) {
	printf("%d\t",elem);
}

/*
* @description 清空栈
*/
void ClearStack(SqStack *S) {
	while((*S).base != (*S).top ) 
		(*S).top--;

	(*S).stacksize = 0;
}

/*
* @description 销毁栈
*/
void DestoryStack(SqStack *S) {
	ClearStack(S);

	(*S).top = (*S).base = NULL;
}

