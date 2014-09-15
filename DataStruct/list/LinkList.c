/*--------------------------------------------------------------------------
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
	LinkList La,Lb,Lc;
	int n1,n2;
	printf("please enter the length for linklist one:");
	scanf("%d",&n1);
	CreateList(&La,n1);
	printf("\nplease enter the length for linklist two:");
	scanf("%d",&n2);
	CreateList(&Lb,n2);
	printf("\n");
	MergeList(La,Lb,&Lc);
	ListTraverse(Lc,vist);
}


/*
* 对两个链表中的元素求并集
* @param LinkList La
* @param LinKList Lb
* @return void
*/
void UnionList(LinkList La,LinkList Lb) {
	int la,lb;
	int e,i;

	la = ListLength(La);
	lb = ListLength(Lb);

	for(i=1;i <=lb;i++) {
		GetElem(Lb,i,&e);
		if(!LocateElem(La,e))
			ListInsert(La,++la,e);			
	}
}

/*
* MergeList  两个有序的单链表，将其合并保证有序性，重复的元素保留-->使用第三个单链表存储
* @param LinkList La
* @param LinkList Lb
* @param LinkList Lc
* @return void
*/
void MergeList(LinkList La,LinkList Lb,LinkList *Lc) {
	InitList(Lc);

	int i,j,k;
	int la,lb;
	int ai,bj;
	
	i = j =1;
	k = 0;
	la = ListLength(La);
	lb = ListLength(Lb);

	while( (i <= la) && (j <= lb)) {
		GetElem(La,i,&ai);
		GetElem(Lb,j,&bj);

		if(ai <= bj) {
			ListInsert(*Lc,++k,ai);
			++i;
		}
		else {
			ListInsert(*Lc,++k,bj);
			++j;
		}
	}

	//还有没有插入Lc中的继续插入
	while(i <= la) {
		GetElem(La,i++,&ai);
		ListInsert(*Lc,++k,ai);
	}

	while(j <= lb) {
		GetElem(Lb,j++,&bj);
		ListInsert(*Lc,++k,bj);
	}
}


/*
* print the element
* @param ElemType e
* @return void
*/
void vist(ElemType e) {
	printf("%d\t",e);
}


/*
*初始化单链表
*@param LinkList *L
@return Status
*/
Status InitList(LinkList *L) {
	*L = (LinkList) malloc(sizeof(struct LNode));

	if(L==NULL)
		exit(OVERFLOW);
	(*L)->next = NULL;

	return OK;
}



/*
* 销毁链表
* @param LinkList *L
* @return Status
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
* @param ListList L
* @return Status
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
* 判空
* @param LinkList L
* @return Status
*/
Status ListEmpty(LinkList L) {
	return L->next == NULL;
}

/*
* 链表长度
* @param LinkList L
* @return int len
*/
int ListLength(LinkList L) {
	int len = 0;
	LinkList p;
	p=L->next;
	while(p != NULL) {
		len++;
		p = p->next;
	}
	return len;
}

/*
* 初始条件：线性表L存在,i在1～ListLength(L)
* 操作结果：用e返回第i个值
* @param LinkList L
* @param int i
* @param ElemTYpe *e
* @return Status
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
* 返回某元素在链表中的位置
* @param LinkList L
* @param int e
8 @return Status
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
* 返回相应元素的前驱元素  cur_e不能为第一个元素
* 通过pre_e返回cur_e的前驱元素
* @param LinkList L
* @param ElemType cur_e
* @param ElemType *pre_e
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
* 返回某元素的后继元素  cur_e不能是最后一个元素
* 通过next_e返回后继元素
* @param LinkList L
* @param ElemType cur_e
* @param ElemType *next_e
* @return Status
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
* 插入元素
* 在第i个元素前插入新的元素e
* @param LinkList L
* @param int i
* @param ElemType e
* @return Status
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
	if(p== NULL || j > i)
		return ERROR;

	q = (LinkList ) malloc(sizeof(struct LNode));
	q->data = e;
	q->next = p->next;
	p->next = q;

	return OK;
}

/*
* 删除元素
* 删除第i个元素，并返回该通过e放回该元素
* @param LinkList L
* @param int i
* @param ElemType *e
* @return Status
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
* 对链表中每个元素调用visit()函数
* @param LinkList L
* @param void(*vist)(ElemType)
* @return Status
*/
Status ListTraverse(LinkList L,void (*visit)(ElemType)) {
	LinkList p;
	p = L->next;

	while(p != NULL) {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

/*
* 正序创建链表
* @param LinkList *L
* @param int n
* @return void
*/
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

/*
* @description:逆序创建链表
* @param LinkList *L
* @param int n
* @return void
*/
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



