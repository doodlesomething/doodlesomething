/*--------------------------------------------------------------
	*file:ListStack.c
	*date:22-9-2014
	*author:doodlesomething@163.com
	*version:1.0
	*description:链栈的基本操作和习题
----------------------------------------------------------------*/


#include "liststack.h"
#include <stdlib.h>
#include <stdio.h>
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


//十进制转到任意进制(非负正整数)
void DecToAny(int n,int N) {
	int elem;
	LinkStack S;
	
	InitStack(&S);

	while(N) {
		Push(&S,N%n);
		N = N/n;
	}

	while(!StackEmpty(S)) {
		Pop(&S,&elem);
		printf("%d",elem);
	}
}


/*
* @description:括号匹配
* @more:当遇到左符号时则符号进栈;
	遇到右符号时，则弹出一个元素
	当该元素和当前元素是匹配的括号，
	则继续匹配，否则退出程序
	当遇到其他字符时跳过
	注意当匹配开始和结束时栈为空
*/
Status BracketsMatch(char *str) {
	LinkStack S;
	int elem,flag,len;
	
	flag = 0;
	len = strlen(str);
	InitStack(&S);

	while(str && len--) {
		switch(*str) {
			case '[':
			case '(':
			case '{':
				Push(&S,*str);
				str++;
				flag = 1;
				break;
			case ']':
			case ')':
			case '}':
				Pop(&S,&elem);
				if( (elem == '[' && *str == ']') || (elem == '(' && *str ==')') || (elem == '{' && *str == '}' ) ) {
				str++;
				}
				else {
					return ERROR;
				}
				break;
			default:
				str++;
				break;
		}
	}

	if(StackEmpty(S) && flag)
		return OK;
	else
		return ERROR;
}


/*
* @description:行编辑
*/
void LineEdit() {
	LinkStack S,S1;
	int ch,elem;

	InitStack(&S);
	InitStack(&S1);

	ch =getchar();

	while(ch != EOF) {
		while(ch != EOF && ch != '\n') {
			switch(ch) {
				case '#':
					Pop(&S,&elem);
					break;
				case '@':
					ClearStack(&S);
					break;
				default:
					Push(&S,ch);
					break;
			}

			ch = getchar();
		}
		while(!StackEmpty(S)) {
			Pop(&S,&elem);
			Push(&S1,elem);
		}
		while(!StackEmpty(S1)) {
			Pop(&S1,&elem);
			printf("%c",elem);
		}

		if(ch != EOF )
			ch = getchar();
	}
}
