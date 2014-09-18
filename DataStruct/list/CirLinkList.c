/*--------------------------------------------------------------------
	* file:Circular.c 
	* date: 9-18-2014
	* author: doodlesomething@163.com
	* version:1.0
	* description:循环单链表的实现(带头结点和尾指针)
---------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "cirlinklist.h"

int main(int argc,char *argv[]) {
	LinkList La,Lb,ra,rb;
	char head_e,last_e;
	ra = CreateList(&La);
	rb = CreateList(&Lb);
	ListTraverse(La,visit);
	printf("\n");
	ListTraverse(Lb,visit);
	rb = MergeList(ra,rb);
	ListTraverse(La,visit);
	GetHead(ra,&head_e);
	GetLast(ra,&last_e);
	printf("\n head_e:%c, last_e:%c\n",head_e,last_e);
}

/*
* @description:创建带头结点和尾指针的单链表
* @param LinkList *L
* @return LinkList r
*/
LinkList CreateList(LinkList *L) {
	LinkList r;
	char w;

	*L = (LinkList) malloc(sizeof(struct LNode)); 
	if( (*L) == NULL)
		exit(OVERFLOW);
	//让头结点先自己指向自己
	(*L)->next = (*L);

	//输入赋值-->这里的插入顺序为顺序插入
	printf("please enter the linklist data:\n");
	scanf("%c,",&w);
	while(w != '#') {
		r = (LinkList) malloc(sizeof(struct LNode));
		r->data = w;
		r->next = (*L)->next;
		(*L)->next = r;
		scanf("%c,",&w);
	}
	//找到尾节点并返回	
	r = *L;
	while(*L != r->next)
		r = r->next;

	return r;
}

/*
* @description 遍历链表元素
* @param LinkList L
* @param void (*visit) (ElemType)
*/
void ListTraverse(LinkList L,void (*visit) (ElemType)) {
	LinkList p;
	p = L->next;
	while(p != L) {
		visit(p->data);
		p = p->next;
	}
}

/*
* @description 打印链表元素
* @param ElemType elem
* @return void
*/
void visit(ElemType elem) {
	printf("%c\t",elem);
}

/*
* @description 通过elem返回头结点的值
* @param LinkList rear
* @param ElemType *elem
* @return Status
*/
Status GetHead(LinkList rear,ElemType *elem) {
	LinkList tmp;
	tmp = rear->next->next;
	if(tmp != NULL) {
		*elem = tmp->data;
		return OK;
	}
	return  ERROR;
}

/*
* @description 通过elem返回尾指针所在节点
* @param LinkList rear
* @param ElemType *elem
* @return Status
*/
Status GetLast(LinkList rear,ElemType *elem) {
	if(rear->data) {
		*elem = rear->data;
		return OK;
	}
	return ERROR;
}


/*
* @description 合并两个链表,并返回合并后的链表尾指针
* @param LinkList rearA
* @param LinkList rearB
* @return LinkList rearB
*/
LinkList MergeList(LinkList rearA,LinkList rearB) {
	LinkList p,q;
	//保存rearA的头结点
	p = rearA->next;
	//让reaA的尾指针指向rearB的第一个节点(非头结点)
	rearA->next = rearB->next->next;
	//保存rearB的头结点
	q = rearB->next;
	//让rearB尾指针指向rear的头结点
	rearB->next = p;
	//将rearB的头结点删除
	free(q);

	return rearB;
}

