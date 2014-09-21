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
* MergeList 合并两个有序递增链表保持依然有序，不允许开辟新的内存空间  
* @param LinkList La
* @param LinkList Lb
* @param LinkList Lc
* @return void
*/
void MergeList(LinkList *La,LinkList *Lb,LinkList *Lc) {
	LinkList pa,pb,pc;

	pa =(*La)->next;
	pb =(*Lb)->next;

	//把La链表的头结点用作Lc链表的头结点
	*Lc = pc = *La;	

	while(pa && pb) {
		if(pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	//处理剩余节点
	pc->next = pa ? pa : pb;

	free(*Lb);
}

/*
* 将有序递增链表中的重复元素去掉 -->因为有序所以重复的值必定相邻
* @param LinkList L
* @return void
*/
void DistinctSort(LinkList L) {
	LinkList p,tmp;
	p = L->next;
	while(p->next != NULL) {
		tmp = p->next;
		if(p->data == tmp->data) {
			p ->next = tmp->next;
			free(tmp);
		}
		p = p->next; 
	}
}

/*
* @description 删除无序链表中的重复节点
* @param LinkList L
* @return void
*/
void DistinctList(LinkList L) {
	LinkList p,tmp,q,r;
	
	p = q = L;

	while( p->next != NULL) {
		tmp = q->next;

		while(tmp != NULL) {

			if(p->next->data == tmp->data && tmp != p->next) {
				r = p->next;
				p->next = r->next;
				free(r);
			}

			tmp = tmp->next;
		}

		p = p->next;
	}
	
}


/*
* @description 删除链表中最小值 -->将第一个值设为最小值，然后一边一边调整min的值,注意在遍历的过程中记录前驱
* @param LinkList L
* @return void
*/
void DeleteMin(LinkList L) {
	LinkList p,minpre,min,pre;
	
	pre = L;
	p = L->next;
	minpre = pre;
	min = p;

	while(p != NULL) {
		if(p->data < min->data) {
			min = p;
			minpre = pre;
		}
		pre = p; 
		p = p->next;
	}

	minpre->next = min->next;
	free(min);
}

/*
* 就地逆置单链表
* @description:将头结点和第一个节点"作为"一个链表,第一个节点的next为NULL。剩下的为连一个链表，顺序将每个节点
		插入到头结点和"第一个"节点间
* @param LinkList L
* @return void
*/
void ListReverse(LinkList L) {
	LinkList p,tmp,q;
	p = L->next;

	if(p != NULL && p->next != NULL) {
		q = p->next;
		p ->next = NULL;

		while(q) {
			L->next = q;
			tmp = q->next;
			q->next = p;
			p = q;
			q = tmp;
		}
	}
}

/*
* 原地转置链表的另一种解法-->这是从网上看来的，感觉非常有意思
* 理解上只要看出p永远为头节点后的第一个节点即可
*/
void ListReverse1(LinkList L) {
	LinkList p,tmp,q;
	p = L->next;
	q = NULL;

	if(p != NULL && p->next != NULL) {
		q = p->next;
		p->next = NULL;
	}

	while(q) {
		tmp = q->next;
		q->next = p;
		p = q;
		q = tmp;
	}

	L->next = p;
}



/*
* @description 链表练习--->存在一个单链表为{a1,b1,a2,b2,..,an,bn}请将其分为{a1,a2,..,an}和{b1,b2,...,bn} 
* @param LinkList La
* @param LinkList Lb
* @Param LinkList Lc
* @return void
*/
void SplitList(LinkList La,LinkList Lb,LinkList Lc) {
	LinkList p,pb,pc;
	int i,j;

	i = j =1;
	p = La->next;
	pb = Lb;
	pc = Lc;

	while(p != NULL) {
		ListInsert(Lb,i++,p->data);
		pb = p;

		p = p->next;
		if(p != NULL) {
			ListInsert(Lc,j++,p->data);
			pc = p;
			p = p->next;
		}
	}

	//一定要记住要Lb,Lc的最后节点next置空,但不要删除尾节点
	pb->next == NULL ? (pb->next = NULL) : (pb->next->next = NULL);
	pc->next == NULL ? (pc->next = NULL) : (pc->next->next = NULL);
}

/*
* @descripton 删除有序递增链表中中大于min和小于max的值 -->无序的链表删除更加简单
* @param LinkList L
* @param ElmeType min
* @param ElemType max
* @return void
*/
void DeleteInRange(LinkList L,ElemType min,ElemType max) {
	LinkList p,start,end;

	p = L->next;

	while(p != NULL && p->data < min)
		p = p->next;

	start = p;

	while(p !=  NULL && p->data < max)
		p = p->next;
	
	end = p;
	
	start->next = end;

	/*释放节点
	LinkList tmp;
	while(start != end) {
		tmp = start->next;
		start = tmp->next;
		free(tmp);
	}
	*/
}


/*
* @description 判断一个链表是否单调递增 -->如果发现一个前一个节点的值大于后一个节点的值则不为单调递减
* @param LinkList L
* @return Status
*/
Status IsIncreasingList(LinkList L) {
	LinkList p,tmp;
	p= L->next;
	
	while(p->next != NULL) {
		tmp = p->next;

		if(p->data > tmp->data)
			return FALSE;

		p = p->next;
	}

	return TRUE;
}


/*
* print the element
* @param ElemType e
* @return void
*/
void visit(ElemType e) {
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
	LinkList p,q;
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
* @param void(*visit)(ElemType)
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
	
	p = NULL;
	(*L) = (LinkList) malloc(sizeof(struct LNode));
	(*L)->next = NULL;
	q = *L;

	for(i = 0;i < n;i++) {
		p = (LinkList) malloc(sizeof(struct LNode));
		if(scanf("%d",&p->data)) {
			q->next = p;
			q = q->next;
		}
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
	LinkList p;
	int i;

	(*L) = (LinkList) malloc(sizeof(struct LNode));
	(*L)->next = NULL;

	for(i=0;i < n;i++) {
		p = (LinkList) malloc(sizeof(struct LNode));
		if(scanf("%d",&p->data)) {
			p->next = (*L)->next;
			(*L)->next = p;
		}
	}
}



