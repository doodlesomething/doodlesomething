/*----------------------------------------------------
	* file:Sqlist.c
	* date:16-9-2014
	* author:doodlesomething -->doodlesomething@163.com
	* version:1.0
	* detail:使用数组实现线性表
-----------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

int main(int argc,char *argv[]) {
	Sqlist *L;
	ListInsert(L,1,1);
	ListTraverse(L,vist);
}


/*
* 初始化线性表
* @param Sqlist *L
* @param int InitSize
* @return Status
*/
Status InitList(Sqlist *L) {
	L->elem = (ElemType *) malloc(LISTINITSIZE * sizeof(ElemType));
	if(L->elem == NULL)
		exit(OVERFLOW);
	L->length = 0;
	L->listsize = LISTINITSIZE;
	
	return OK;
}

/*
*创建线性表-->基于InitList()创建
* @param Sqlist *L
* @return Status
*/
Status ListCreate(Sqlist *L) {
	InitList(L);


	return OK;
}


/*
* 在第i个元素前插入元素
* @param Sqlist *L
* @param int i
* @param int e
* @return Status
*/
Status ListInsert(Sqlist *L,int i,int e) {
	ElemType *newbase;
	ElemType *p,*q;
	//处理非法输入
	if(i < 1 || i > L->length )
		return ERROR;

	//分配空间不足则增加分配
	if(L->length >= L->listsize )
		newbase = (ElemType *) realloc(L->elem,(L->listsize + SIZEINCREMENT) * sizeof(ElemType) ) ;
	
	if(newbase == NULL)
		exit(OVERFLOW);

	L->elem = newbase;
	
	L->listsize += SIZEINCREMENT;
	//取所要插入元素位置
	q = &L->elem[i-1];
	//取最后一个元素的位置
	p = &L->elem[L->length -1];

	for( ; p >= q; p--) {
		*( p + 1) = *p; 
		*q = e;
	}
	L->length++;

	return OK;
}

/*
* 删除第i个元素,并通过指针返回
* @param  Sqlist *L
* @param int i
* @param ElemType *e
* @return Status
*/
Status ListDelete(Sqlist *L,int i,ElemType *e) {
	ElemType *p,*q;

	if(i < 1 || i > L->length)
		return ERROR;

	q = &L->elem[i - 1];
	p = &L->elem[L->length - 1];
	for( ; q < p ; q++)
		*q = *(q+1);

	L->length--;

	return OK;
}

/*
* 求线性表的长度
* @param Sqlist *L
* @return int L->length
*/
int ListLength(Sqlist *L) {
	return L->length;
}

/*
* 销毁线性表
* @param Sqlist *L
* @return void 
*/
void DestoryList(Sqlist *L) {
	L->length = 0;
	L->listsize = 0;
	free(L->elem);
	L->elem = NULL;
}

/*
* 清除线性表
* @param Sqlist *L
* @return void
*/
void ClearList(Sqlist *L) {
	L->length = 0;
}

/*
* 判空
* @param Sqlist *L
* @return Status
*/
Status ListEmpty(Sqlist *L) {
	if(L->length == 0)
		return TRUE;
	else 
		return FLASE;
}

/*
* 返回前驱元素
* @param Sqlist *L
* @param ElemType e
* @param ElemType *elem
* @return Status
*/
Status PriorElem(Sqlist *L,ElemType e,ElemType *elem) {
	ElemType *q,*p;

	if(e == L->elem[0])
		return ERROR;
	q = &L->elem[L->length - 1];

	for(p = L->elem;p <= q; p++ ) {
		if( *p == e) {
			*elem = *(p - 1);
			return OK;
		}
	}

	return ERROR; 
}

/*
* 返回后继元素
* @param Sqlist *L
* @param ElemType e
* @param ElemType *elem
* @return Status
*/
Status NextElem(Sqlist *L,ElemType e,ElemType *elem) {
	ElemType *q,*p;
	
	if(L->elem[L->length - 1] == e)
		return ERROR;
	q = &L->elem[L->length -1];
	for(p = L->elem; p < q; p++) {
		if(*p == e) {
			*elem = *(p+1);
			return OK;
		}
	}

	return ERROR;
}

/*
* 定位指定元素
* @param Sqlist *L
* @param ElemType e
* @return int i
*/
int LocateElem(Sqlist *L,ElemType e) {
	int i;
	ElemType *p,*q;

	i = 0;
	p = &L->elem[0];
	q = &L->elem[L->length -1];
	for( ; p <= q; p++) {
		i++;
		if( *p == e) {
			return i;		
		}
	}

	return ERROR;
}


/*
* 函数遍历线性表中的每个元素
* @param Sqlist *L
* @param void (*vist) (ElemType)
* @return void
*/
void ListTraverse(Sqlist *L,void (*vist) (ElemType)) {
	ElemType *p,*q;
	p = &L->elem[0];
	q = &L->elem[L->length - 1];

	for( ; p <= q; p++)
		vist(*p);
}

/*
* 打印单个元素
* @param ElemType elem
* @return void
*/
void vist(ElemType elem) {
	printf("%d\t",elem);
}
