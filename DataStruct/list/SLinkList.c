/*---------------------------------------------------------------------------------------
	* file:SLinkList.c
	* date:9-17-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:静态链表的实现，静态链表主要用在没有
	指针的高级语言中，使其可以使用链表结构
	* more : 
	* somethingelse: 1.L[MAXSIZE-1] 相当于链表头结点,当链表为空时L[MAXSIZE-1].cur等于0
		  当链表不为空时其L[MAXSIZE-1].cur等于1-->即其始终指向第一个节点
		  2.所谓的备用链表即原数组中空闲节点，只是方便理解罢了
------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "slinklist.h"


int main(int argc,char *argv[]) {
	SLinkList L;
	int i;
	InitList(L);

	for(i=0;i < 10;i++)
		ListInsert(L,1,i);

	ListTraverse(L,visit);

	printf("\n");
}


/*
* 初始化静态链表-->将提前分配的数组空间初始化成一个链表
* @param SLinkList L
* @return void
*/
void InitList(SLinkList L) {
	int i;

	for( i = 0; i < MAXSIZE-1; ++i) {
		L[i].cur = i+1;
	}
	
	//最后一个节点的cur值为0
	L[MAXSIZE-1].cur = 0;
}


/*
* 从备用空间取得一个节点
* @description 若备用链表非空，则返回分配的节点下标，否则返回0
* @param SLinkList L
* @return int i
*/
int Malloc_SL(SLinkList L) {
	int i;

	i = L[0].cur;

	if(L[0].cur) 
		L[0].cur = L[i].cur;

	return i;
}




/*
* @description 返回链表的长度
* @param SLinkList L
* @return int len
*/
int ListLength(SLinkList L) {
	int len,k;

	len = 0;
	k = L[MAXSIZE-1].cur;

	while(k) {
		k = L[k].cur;
		len++;
	}
	
	return len;
}


/*
* @description 将元素插入静态链表第i个元素前即使表是空的,当输入非法或无空闲节点是返回ERROR
* @param SLinkList L
* @param int i
* @param int e
* @return Status
*/

Status ListInsert(SLinkList L,int i,int elem) {
	int k,z,j;

	k = MAXSIZE - 1;

	if( i < 1 || i > ListLength(L) + 1)
		return ERROR;

	//申请一个空闲节点存放所插入的元素
	j = Malloc_SL(L);
	
	if(j) {
		L[j].data = elem;

		//插入元素前，前后两个元素的游标关系需要找到第i个元素的前一个元素
		for(z = 1; z < i - 1;z++) {
			k = L[k].cur;
		}
		//调整游标指向
		L[j].cur = L[k].cur;
		L[k].cur = j;

		return OK;
	}
	
	return ERROR;
}


/*
* 将空闲节点放到备用链表上
* @param SLinkList L
* @return void
*/
void Free_SL(SLinkList L,int k) {
	L[k].cur = L[0].cur;
	L[0].cur = k;
}


/*
* @description:删除第i个节点,传参非法时返回ERROR,否则返回OK
* @param SLinkList L
* @param int i
* @return Status
*/
Status ListDelete(SLinkList L,int i) {
	int k,z,j;

	if( i < 1 || i > (ListLength(L) + 1))
		return ERROR;

	k = MAXSIZE-1;

	for(z = 0 ; z < i - 1 ; z++ ) {
		k = L[k].cur;
	}

	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SL(L,k);

	return OK;
}


/*
* @description 遍历链表中每个元素
* @param SLinkList L 
* @param void (*vist) (ElemType)
* @return void
*/
void ListTraverse(SLinkList L,void (*visit) (ElemType)) {
	int k;

	k = L[MAXSIZE-1].cur;

	while(k) {
		visit(L[k].data);
		k = L[k].cur;
	}
}

/*
* @description 打印链表元素
* @param ElemType elem
* @return void
*/
void visit(ElemType elem) {
	printf("%d\t",elem);
}
