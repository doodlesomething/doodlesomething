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
Status Push(LinkStack *S,ElemType elem) {
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
Status Pop(LinkStack *S,ElemType *elem) {
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
* @description:栈长
*/
int StackLength(LinkStack S) {
	return S.len;
}

/*
* @description:遍历链栈所有元素
*/
void StackTraverse(LinkStack S,void (*visit) (ElemType)) {
	StackPoint p;
	p = S.top;

	while(p) {
		visit(p->data);
		p = p->next;
	}
}

/*
* @description:打印栈元素
*/
void visit(ElemType elem) {
	printf("%d\t",elem);
}


/*
* @description:获取栈顶元素（不弹出）
*/
Status GetTop(LinkStack S,ElemType *elem) {
	if(!S.top)
		return ERROR;

	(*elem) = S.top->data;

	return OK;
}


/*
* @description:清空链栈
*/
void ClearStack(LinkStack *S) {
	StackPoint p,tmp;
	p = (*S).top;
	tmp = NULL;

	while(p) {
		tmp = p->next;
		free(p);
		p = tmp;
	}

	(*S).top = NULL;
	(*S).len = 0;
}

/*
* @description:销毁链栈
*/
void DestoryStack(LinkStack *S) {
	ClearStack(S);
}



/*
* @description:用两个s1,s2栈实现队列的出入队的功能
* @思路:把栈s2作为缓冲区
	入队时，直接进栈s1;
	出队时，首先判断栈s2是否为空，若为空则将栈s1的全部元素依次弹出，并压入栈s2中，把s2栈顶元素弹出
	即为出队；
	倘若不为空，则将s2的栈顶元素弹出即可
*/
void InsertQueue(LinkStack *S,ElemType elem) {
	Push(S,elem);
}

ElemType DeleQueue(LinkStack *S1,LinkStack *S2) {
	ElemType e;
	
	while(StackEmpty(*S2)) {
		while(!StackEmpty(*S1)) {
			Pop(S1,&e);
			Push(S2,e);
		}
	}
	
	Pop(S2,&e);

	return e;
}
