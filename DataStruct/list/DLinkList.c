/*----------------------------------------------------------------------------
	* file:DLinkList.c
	* date:9-18-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:循环双向链表的实现
------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "dlinklist.h"

int main(int argc,char *argv[]) {
	LinkList La;
	int del_e,i,pre_e,next_e;
	InitList(&La);
	for(i = 1;i < 6;i++)
		ListInsert(La,1,i);
	ListTraverse(La,visit);
	printf("\n");
	PriorElem(La,3,&pre_e);
	NextElem(La,3,&next_e);
	printf("pre_e:%d, next_e:%d\n",pre_e,next_e);
	printf("ListLength:%d\n",ListLength(La));
	ListDelete(La,5,&del_e);
	ListTraverse(La,visit);
	printf("\n");
	printf("%d\n",del_e);
	return 0;
	
	/*
	测试用例结果:	
	5	4	3	2	1	
	pre_e:4, next_e:2
	ListLength:5
	5	4	3	2	
	1
	*/
}


/*
* @description 初始化链表
* @param LinkList *L
* @return void
*/
Status InitList(LinkList *L) {
	*L = (LinkList) malloc(sizeof(struct LNode));

	if(*L == NULL)
		exit(OVERFLOW);

	(*L)->next = (*L)->prior = (*L);

	return OK;
}

//判空
Status ListEmpty(LinkList L) {
	return L->next == L ? TRUE : FALSE;
}

/*
* @description 求链表的长度
* @param LInkList L
* @return len
*/
int ListLength(LinkList L) {
	LinkList p;
	int len;
	
	len = 0;
	p = L->next;

	while(p != L) {
		len++;
		p = p->next;
	}

	return len;
}

//获取后继元素
Status NextElem(LinkList L,ElemType elem,ElemType *next_e) {
	LinkList p;

	p = L->next->next;

	while(p != L) {
		if(p->prior->data == elem) {
			*next_e = p->data;
			return OK;
		}
		p = p->next;
	}

	return ERROR;
}

//获取前驱元素
Status PriorElem(LinkList L,ElemType elem,ElemType *pre_e) {
	LinkList p;
	p=L->next->next;

	while(p != L) {
		if(p->data == elem) {
			*pre_e = p->prior->data;
			return OK;
		}
		p = p->next;
	}

	return ERROR;
}


/*
* @description 返回第i个元素的地址 供插入和删除算法使用
* @param LinkLink L
* @param int i
* @return LinkList p*/

LinkList GetElemP(LinkList L,int i) {
	int j;
	LinkList p;
	
	p = L;
	j = 1;

	while(j <= i && p->next != L) {
		p = p->next;
		j++;
	}

	return p;
}

/*
* @description 在第i个元素前插入指定元素
* @param LinkList L
* @param int i
* @param ElemType elem
* @return Status
*/
Status ListInsert(LinkList L,int i,ElemType elem) {
	LinkList p,q;

	
	if(i < 1 || i > ListLength(L) + 1)
		return ERROR;

	p = GetElemP(L,i-1);
	if(!p)
		return ERROR;
		
	q = (LinkList) malloc(sizeof(struct LNode));
	
	if(q == NULL)
		exit(OVERFLOW);

	q->data = elem;

	q->prior = p;
	q->next = p->next;
	p->next->prior = q;
	p->next = q;

	return OK;
}  


/*
* @description 删除第i元素,并通过elem返回
* @param LinkList L
* @param int i 
* @param ElemType *elem
* @return Status
*/
Status ListDelete(LinkList L,int i,ElemType *elem) {
	LinkList p;

	if(i < 1 || i > ListLength(L))
		return ERROR;

	p = GetElemP(L,i);
	if(!p)
		return ERROR;
	*elem = p->data;

	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);

	return OK;
}

/*
* @description 遍历链表元素
* @param LinkList L
* @param void (*visit) (ElemType)
* @return void
*/
void ListTraverse(LinkList L,void (*visit) (ElemType)) {
	LinkList p;
	p = L->next;
	
	while(p != L) {
		visit(p->data);
		p = p->next;
	}
}

//输出链表元素
void visit(ElemType elem) {
	printf("%d\t",elem);
}
