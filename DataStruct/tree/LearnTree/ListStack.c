/*--------------------------------------------------------------
	*file:ListStack.c
	*date:22-9-2014
	*author:doodlesomething@163.com
	*version:1.0
	*description:链栈的基本操作
----------------------------------------------------------------*/


#include "liststack.h"
#include <stdlib.h>


/*
* @description:初始化链栈
*/
void InitStack(LinkStack *S) {
	(*S).top = NULL;
	(*S).len = 0;
}

/*
* @description:进栈
*/
Status Push(LinkStack *S,SElemType elem) {
	StackPoint s = (StackPoint) malloc(sizeof(StackNode));
	if(!s)
		exit(OVERFLOW);
	
	s->data = elem;
	s->next = (*S).top;
	(*S).top = s;
	(*S).len++;

	return OK;
}


/*
* @description:判空
*/
Status StackEmpty(LinkStack S) {
	return S.top == NULL ? TRUE : FALSE;
}

/*
* @description:出栈
*/
Status Pop(LinkStack *S,SElemType *elem) {
	StackPoint p;

	if(StackEmpty(*S))
		return ERROR;

	//保存栈顶，以便删除
	p = (*S).top;
	(*elem) = p->data;
	(*S).top = p->next;
	free(p);
	(*S).len--;

	return OK;
}



/*
* @description:获取栈顶元素（不弹出）
*/
Status GetTop(LinkStack S,SElemType *elem) {
	if(!S.top)
		return ERROR;

	(*elem) = S.top->data;

	return OK;
}


