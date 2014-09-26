/*--------------------------------------------------------------------------
	* date:9-16-2014
	* author:doodlesomething  --> doodlesomething@163.com
	* version:1.3
	* description:实现带头结点单链表的初始化/判空/插入/删除/销毁/查找
	  前驱节点和后继节点元素/元素定位/
--------------------------------------------------------------------------*/
#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>




//创建节点
Status MakeNode(Link *s,ElemType e) {
	(*s) = (Link) malloc(sizeof(struct LNode));

	if( (*s) != NULL) {
		(*s)->data = e;
		(*s)->next = NULL;
		return OK;
	}

	return ERROR;
}


//释放节点
void FreeNode(Link *p) {
	free(*p);
	(*p) = NULL;
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

/*
* @description:清空链表
*/
Status ClearList(LinkList *L) {
	Link p,tmp;

	if(ListEmpty(*L))
		return ERROR;

	p = (*L).head;
	while(p->next) {
		tmp = p->next;
		p->next = tmp->next;
		free(tmp);
	}
	//如果删除的是尾节点则需要调整尾指针
	if(p == (*L).tail)
		(*L).tail = (*L).head;

	(*L).len = 0;

	return OK;
}


/*
* @description:销毁链表
*/
Status DestoryList(LinkList *L) {
	if(!ClearList(L))
		return ERROR;

	(*L).head = (*L).tail = NULL;

	return OK;
}

/*
* @description 将生成的节点插入链表中
*/
void InsFirst(LinkList *L,Link q,Link s) {
	s->next = q->next;
	q->next = s;
	
	(*L).len++;

	if(q == (*L).tail)
		(*L).tail = q->next;

}



//删除节点
Status DeleFirst(LinkList *L,Link h,Link *p) {
	(*p) = h->next;
	if(*p) {
		h->next = (*p)->next;
		if(!h->next)
			(*L).tail = h;

		(*L).len--;
		return OK;
	}
	else 
		return ERROR;

	
}


//判空
Status ListEmpty(LinkList L) {
	return L.len == 0 ; 
}


//获取头节点的地址
Position GetHead(LinkList L) {
	return L.head;
	
}

//返回尾节点的地址
Position GetLast(LinkList L) {
	return L.tail;
}

//获取当前指针的值
ElemType GetCurElem(Link p) {
	return p->data;
}


//将节点插入链尾
Status Append(LinkList *L,Link s) {
	
	(*L).tail->next = s;
	(*L).tail = s;
	(*L).tail->next = NULL;
	(*L).len++;

	return OK;
}

//删除最后一个节点，并通过q返回
Status Remove(LinkList *L,Link *q) {
	Link p;
	
	if(ListEmpty(*L))
		return ERROR;
	
	p = (*L).head;

	while(p->next != (*L).tail)
		p = p->next;

	(*q) = (*L).tail;
	free((*L).tail);

	(*L).tail = p;
	(*L).len--;

	return OK;
}


//将s所指节点插入在p所指节点之前
Status InsBefore(LinkList *L,Link s,Link p) {
	Link q;

	if(ListEmpty(*L))
		return ERROR;
	
	if((*L).head == s)
		return ERROR;
	
	q = (*L).head;

	while(q->next) {
		if(s == q->next)  {
			p->next = q->next;
			q->next = p;
			(*L).len++;
			
			return OK;
		}
		q = q->next;
	}
	
	return ERROR;
}


//将s所指节点插入在p所指节点之后
Status InsAfter(LinkList *L,Link s,Link p) {
	Link q;

	
	q = (*L).head;

	while(q) {
		if(s == q) {
			p->next = q->next;
			q->next = p;
			(*L).len++;
			if(s==(*L).tail) {
				(*L).tail = p;
				(*L).tail->next = NULL;
			}
			return OK;
		}
	}
	
	return ERROR;
}


//求链表的长度
int ListLength(LinkList L) {
	return L.len;
}


//更新p节点所指的值
Status SetCurElem(Link *p,ElemType elem) {
	(*p)->data = elem;
	return OK;
}

//返回前驱元素的地址
Position PriorElem(LinkList L,ElemType elem,Status (*compare) (ElemType,ElemType)) {
	Link p;

	if(ListLength(L) < 2) 
		return NULL;
	
	p = L.head->next;

	while(p->next) {
		if(!compare(elem,p->next->data))
			return p;

		p = p->next;
	}
	

	return NULL;
}

//返回后继元素的地址
/*
Position NextElem(LinkList L,ElemType elem,Status (*compare) (ElmeType,ElemType) ) {
	Link p;

	if(ListLength(L) < 2)
		return NULL;
	
	p = L.head->next;

	while(p->next) {
		if(!compare(elem,p->data))
			return p->next;

		p = p->next;
	}
		
	return NULL;
}
*/
//定位元素,返回其地址
Status LocateElem(LinkList L,Link *p,ElemType elem,Status (*compare) (ElemType,ElemType)) {
	Link q;
	if(ListEmpty(L))
		return ERROR;
	
	q = L.head->next;
	while(q) {
		if(!compare(elem,q->data)) {
			(*p) = q;
			return OK;
		}
		q = q->next;
	}

	return ERROR;
}

//返回第i个元素的指针
Position LocatePos(LinkList L,int i){
	Link p;
	int j;

	j = 1;
	p = L.head->next;

	if(i < 1 || i > ListLength(L))
		return NULL;
	
	while(p && j < i) {
		p = p->next;
		j++;
	}

	return p;
}


//遍历链表
Status ListTraverse(LinkList L,void (*visit) (ElemType)) {
	Link p;

	if(ListEmpty(L))
		return ERROR;

	p = L.head->next;

	while(p) {
		visit(p->data);
		p = p->next;
	}

	return OK;
}

//打印元素
void print(ElemType elem) {
	printf("%d:%d\t",elem.OccurTime,elem.NType);
}	


//比较两个的元素的大小
Status compare(ElemType elem,ElemType e) {
	if(elem.OccurTime == e.OccurTime)
		return 0;
	else if(elem.OccurTime > e.OccurTime )
		return 1;
	else 
		return -1;
}



/*
* @description:将新事件插入升序链表中,保持升序
*/
Status OrderInsert(LinkList *L,ElemType elem,Status (*cmp) (ElemType,ElemType)) {
	Link p,q,tmp;

	q = (*L).head;
	p = q->next;

	while(p && cmp(p->data,elem) < 0 ) {
		q = p;
		p = p->next;
	}

	tmp = (Link) malloc(sizeof(LNode));

	if(!tmp)
		exit(OVERFLOW);

	
	tmp->data = elem;
	q->next = tmp;
	tmp->next = p;
	(*L).len++;
	//倘若是在尾节点则改变尾指针
	if(!p)
		(*L).tail = tmp;

	
	return OK;
}



/*
* @比较两个客户的到达时间
*/
Status cmp(ElemType elem,ElemType e) {
	if(elem.OccurTime == e.OccurTime)
		return 0;
	else if(elem.OccurTime > e.OccurTime )
		return 1;
	else 
		return -1;
}
