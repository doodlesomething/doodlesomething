/*---------------------------------------------------------------------------------------------
	* file:SLinkList.c
	* date:9-17-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:静态链表的实现，静态链表主要用在没有指针的高级语言中，使其可以使用链表结构
	* more : 数组的元素都是由两个数据域组成, 也钮 和 cur 。也就是说,数组的每个
	下标都对应一个 也ta 和一个 cur o 数据域也 ta ,用来存放数据元素, 也就是通常我
	们要处理的数据;而游标 cur 相当于单链表中的 next 指针,存放该元素的后继在数组
	中的下标。在静态链表中,操作的是如且,不存在像动态链表的结点申请和释放问题,所以
	我们需要自己实现这两个 函数,才可以做插入和删除的操作
	* somethingelse: 1.L[MAXSIZE-1] 相当于链表头结点,当链表为空时L[MAXSIZE-1].cur等于0
		  当链表不为空时其L[MAXSIZE-1].cur等于1-->即其始终指向第一个节点
		  2.所谓的备用链表即原数组中空闲节点，只是方便理解罢了
----------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "slinklist.h"




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
* @description 销毁链表
* @param SLinkList L
* @return void
*/
void DestoryList(SLinkList L) {
	int i;

	for(i = 0; i < MAXSIZE - 1; i++)
		L[i].cur = 0;
}


/*
* @description 清空链表
* @param SLinkList L
* @return void
*/
void ClearList(SLinkList L) {
	InitList(L);	
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
* @description 有elem返回L中第i个元素的值
* @param SLinkList L
* @param int i
* @param ElemType *elem
* @return Status
*/
Status GetElem(SLinkList L,int i,ElemType *elem) {
	int k,j;
	
	if( i < 1 || i > ListLength(L) + 1)
		return ERROR;
	j = 1;
	k = L[MAXSIZE-1].cur;

	while(k) {
		if(i == j) {
			*elem = L[k].data;
			return OK;
		}
		k = L[k].cur;
		j++;
	}

	return ERROR;
}


/*
* @description 返回指定元素的位置
* @param SLinkList L
* @param ElemType elem
* @return int i
*/
int LocateElem(SLinkList L,ElemType elem) {
	int k,i;

	k = L[MAXSIZE-1].cur;
	i = 1;

	while(k) {
		if(L[k].data == elem)
			return i;
		k = L[k].cur;
		i++;
	}

	return 0;
}

/*
* @description 获取某个指定元素(不是第一个)的前驱元素
* @param SLinkList L
* @param ElemType elem
* @param ElemType *pre_e
* @return Status
*/
Status PreElem(SLinkList L,ElemType elem,ElemType *pre_e) {
	int k,j;

	k = L[MAXSIZE-1].cur;

	while(k) {
		j = L[k].cur;
		if(j  && (L[j].data == elem) ) {
			*pre_e = L[k].data;
			return OK;
		}

		k = L[k].cur;
	}
	return ERROR;
}

/*
* @description 返回某个指定元素(非最后一个)的后继元素
* @param SLinkList L
* @param ElemType elem
* @param ElemType *next_e
* @return void
*/
Status NextElem(SLinkList L,ElemType elem,ElemType *next_e) {
	int k,j;

	k = L[MAXSIZE-1].cur;

	while(k) {
		j = L[k].cur;
		if(j && (L[k].data == elem) ) {
			*next_e = L[j].data;
			return OK;
		}
		k = L[k].cur;
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
* @description 判空
* @param SLinkList L
* @return Status
*/
Status ListEmpty(SLinkList L) {
	return L[MAXSIZE-1].cur ? FALSE : TRUE ;
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

	Free_SL(L,j);

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

/*
* @求集合 （A-B） U （B-A）
* @param SLinkList L
* @param int S
* @return void
*/
void DifferenceList(SLinkList L)  {
	int r,i,p,k,S;
	int j,tmp;
	int la,lb;

	InitList(L);
	S = Malloc_SL(L);
	r = S;

	printf("Enter the number of La and Lb:");
	scanf("%d %d\n",&la,&lb);
	//输入A集合
	for(j = 0; j < la; j++) {
		i = Malloc_SL(L);
		scanf("%d",&L[i].data);
		L[r].cur = i;
		r = i;
	}
	L[r].cur = 0;

	for(j = 0; j < lb; j++) {
		scanf("%d",&tmp);
		p = S;
		k = L[S].cur;

		while(k != L[r].cur && L[k].data != tmp) {
			/*
			由于删除元素需要调整前一个元素的游标
			p 指向前一个元素，k指向所要比较的元素
			*/
			p = k;
			k = L[k].cur;
		}

		
		if( k == L[r].cur) {
			i = Malloc_SL(L);
			L[i].data = tmp;
			L[i].cur = L[r].cur;
			L[r].cur = i;
		}
		else {
			L[p].cur = L[k].cur; 
			Free_SL(L,k);
			//当所删除的节点为最后一个是应该调整尾指针
			if(r == k)
				r = p;
		}
	}
}

/*
Difference 测试用例：
Enter the number of La and Lb:6 4
1 2 3 4 5 6
7 6 8 4
>>
	1 2 3 5 8 7
*/





/*
静态链表总结：

缺点：
1.没有解决连镇存储分配带来的表长难以确定的问题
2.失去了存储结构随机存取的特性

优点：
在插入和删除操作时 ,只需要修改游标,不需
要移动元素,从而改进了在顺序存储结构中的
插人和删除操作需要移动大量元素的缺点
*/
