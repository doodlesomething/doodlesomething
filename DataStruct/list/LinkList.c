/*-------------------------------------------------------------------------
	* date:9-11-2014
	* author:doodlesomething  --> doodlesomething@163.com
	* version:1.0
	* description:实现带头结点单链表的初始化/判空/插入/删除/销毁/查找
	  前驱节点和后继节点元素/元素定位/
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


int main(int argc,char *argv[]) {
	void vist(ElemType e);
	LinkList L;
	int n;
	int getE,preE,nextE;
	printf("please input how long you want to make the linklist is?\n");
	scanf("%d",&n);
	printf("please input %d number for the linklist for test\n",n);
	CreateListReverse(&L,n);
	printf("List:");
	ListTraverse(L,vist);
	GetElem(L,1,&getE);
	printf("\nGetElem:%d",getE);
	ListDelete(L,1,&getE);
	printf("\nDeleteElem:%d\n",getE);
	printf("List:");
	ListTraverse(L,vist);
	printf("\nListEmpty:%d",ListEmpty(L));
	printf("\nListLength:%d",ListLength(L));
	PreElem(L,2,&preE);
	printf("\nPreElem:%d",preE);
	NextElem(L,2,&nextE);
	printf("\nNextElem:%d\n",nextE);
	ListInsert(L,3,4);
	printf("\nList:");
	ListTraverse(L,vist);
	printf("\nLocateElem:%d",LocateElem(L,6));
	ClearList(L);
	printf("\nClearList:-->isEmpty:%d, Lenght:%d\n",ListEmpty(L),ListLength(L));
	printf("\nDestoryList:%d\n",DestoryList(&L));
	if(L)
		printf("Here it's\n");
}

void vist(ElemType e) {
	printf("%d\t",e);
}

/*
初始化单链表
*/
Status InitList(LinkList *L) {
	*L = (LinkList) malloc(sizeof(struct LNode));

	if(L==NULL)
		exit(OVERFLOW);
	(*L)->next = NULL;

	return OK;
}

/*
销毁链表
*/
Status DestoryList(LinkList *L) {
	LinkList tmp;
	while(*L != NULL) {
		//因为要取当前节点的下一个节点的地址，所以要先保存，才释放当前节点
		tmp = (*L)->next;
		free(*L);
		*L = tmp;
	}
	return OK;
}

/*
清空链表-->和销毁链表的区别在于保留了头结点,但其指针域为空
*/
Status ClearList(LinkList L) {
	LinkList tmp,p;
	p = L->next;
	L->next = NULL;

	while(p != NULL) {
		tmp = p->next;
		free(p);
		p = tmp;
	}

	return OK;
}

/*
判空
*/
Status ListEmpty(LinkList L) {
	return L->next == NULL;
}

/*
链表长度
*/
int ListLength(LinkList L) {
	int i = 0;
	LinkList p;
	p=L->next;
	while(p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

/*
初始条件：线性表L存在,i在1～ListLength(L)
操作结果：用e返回第i个值
*/
Status GetElem(LinkList L,int i,ElemType *e) {
	int j;
	LinkList p;
	//计数器
	j = 1;
	p = L->next;

	while(p != NULL && j < i) {
		p = p->next;
		j++;
	}
	//当i==j时，即取第一个元素
	if(p == NULL || j>i)
		return ERROR;
	*e = p->data;

	return OK;
}

/*
返回某元素在链表中的位置
*/
int LocateElem(LinkList L,int e) {
	LinkList p;
	int i;
	
	i = 0;
	p = L->next;
	while(p != NULL) {
		i++;
		//当出现相等的情况则返回所在位置
		if(p->data == e)
			return i;
		p = p->next;
	}
	return ERROR;
}

/*
返回相应元素的前驱元素  cur_e不能为第一个元素
通过pre_e返回cur_e的前驱元素
*/
Status PreElem(LinkList L,ElemType cur_e,ElemType *pre_e) {
	LinkList p;
	p = L->next;
	while(p->next != NULL) {
		if(p->next->data == cur_e) {
			*pre_e = p->data;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

/*
返回某元素的后继元素  cur_e不能是最后一个元素
通过next_e返回后继元素
*/
Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e) {
	LinkList p;
	p = L->next;
	while(p->next != NULL) {
		if(p->data == cur_e) {
			*next_e = p->next->data;
			return OK;
		}	

		p = p->next;
	}
	return ERROR;
}

/*
插入元素
在第i个元素前插入新的元素e
*/
Status ListInsert(LinkList L,int i,ElemType e) {
	LinkList p,q,tmp;
	int j;

	j = 1;
	p = L;

	while(p != NULL && j < i) {
		j++;
		p = p->next;
	}
	//这里的j>i主要是用来控制非法传参的
	if(p->next == NULL || j > i)
		return ERROR;

	q = (LinkList ) malloc(sizeof(struct LNode));
	q->data = e;
	q->next = p->next;
	p->next = q;

	return OK;
}

/*
删除元素
删除第i个元素，并返回该通过e放回该元素
*/
Status ListDelete(LinkList L,int i,ElemType *e) {
	LinkList p,q;
	int j;

	j = 1;
	p = L ;

	while( p->next != NULL && j < i) {
		j++;
		p = p->next;
	}
	if(j > i || p->next == NULL) 
		return ERROR;

	//当i为最后一个元素时，q->next为NULL过可以完成操作
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);

	return OK;
}

/*
对链表中每个元素调用visit()函数
*/
Status ListTraverse(LinkList L,void (*visit)(ElemType)) {
	LinkList p;
	p = L->next;

	while(p != NULL) {
		visit(p->data);
		p = p->next;
	}

	return OK;
}

//
void CreateList(LinkList *L,int n) {
	LinkList q,p;
	int i;
	//
	(*L) = (LinkList) malloc(sizeof(struct LNode));
	(*L)->next = NULL;
	q = *L;

	for(i = 0;i < n;i++) {
		p = (LinkList) malloc(sizeof(struct LNode));
		scanf("%d",&p->data);
		q->next = p;
		q = q->next;
	}

	p->next = NULL;
}

void CreateListReverse(LinkList *L,int n) {
	LinkList p,q;
	int i;

	(*L) = (LinkList) malloc(sizeof(struct LNode));
	(*L)->next = NULL;

	for(i=0;i < n;i++) {
		p = (LinkList) malloc(sizeof(struct LNode));
		scanf("%d",&p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
