/*--------------------------------------------------------------------------
	* date:9-16-2014
	* author:doodlesomething  --> doodlesomething@163.com
	* version:1.3
	* description:实现带头结点单链表的初始化/判空/插入/删除/销毁/查找
	  前驱节点和后继节点元素/元素定位/
--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"




//创建节点
Status MakeNode(Link *s,ElemType *e) {
	int i;
	(*s) = (Link) malloc(sizeof(struct LNode));

	if( (*s) != NULL) {
		for(i = 0;i < DataLen;i++)
			(*s)->data[i] = e[i];
		(*s)->next = NULL;
		return OK;
	}

	return ERROR;
}




//初始化链表
Status InitList(LinkList *L) {
	Link p;
	p = (Link) malloc(sizeof(struct LNode));
	
	if(!p)
		exit(OVERFLOW);
	
	p->next = NULL;
	(*L).head = (*L).tail = p;
	(*L).len = 0;

	return OK;
}


//将节点插入链尾
Status Append(LinkList *L,Link s) {
	
	(*L).tail->next = s;
	(*L).tail = s;
	(*L).tail->next = NULL;
	(*L).len++;

	return OK;
}

