/*-----------------------------------------------------------------------------
	* file:BST.c
	* date:10-19-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:二叉查找树
	* more:包括初始化/动态删除/插入/查找/遍历
-------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


/*
* @description:初始化
*/
Status InitDSTable(BiTree *T) {
	*T = NULL;
	return OK;
}


/*
* @description:在二叉排序树中插入不存在的元素
*/
Status InsertBST(BiTree *T,TElemType key) {
	BiTree p,s;

	//二叉排序中不存在要插入的节点值
	if(!Search_BST(*T,key,NULL,&p)) {
		s = (BiTree) malloc(sizeof(struct BiTNode));
		if(!s)
			exit(OVERFLOW);

		s->data = key;
		s->lchild = NULL;
		s->rchild = NULL;

		//如果为根节点
		if(!p)
			*T = s;
		//小于当前值的则作为左孩子
		else if(key < p->data)
			p->lchild = s;	
		//大于当前值的则作为右孩子
		else 
			p->rchild = s;

		return TRUE;
	}
	else
		return FALSE;
}


/*
* @description:查找算法判断查找是否成功，主要是配合插入操作
* @more：*p指向当前节点，f直线父亲节点，查找成功则返回TRUE，否则返回FALSE
*/
Status Search_BST(BiTree T,TElemType key,BiTree f,BiTree *p) {
	if(!T) {
		*p = f;
		return FALSE;
	}
	//查找成功
	else if(T->data == key) {
		*p = T;
		return TRUE;
	}
	//小于当前节点的值则往左子树找
	else if(T->data > key ) 
		return Search_BST(T->lchild,key,T,p);
	//大于当前节点值则往右子树找
	else 
		return Search_BST(T->rchild,key,T,p);

}


/*
* @删除二叉排序树中某个节点
*/
Status DeleBST(BiTree *T,TElemType key) {
	if(!(*T))
		return FALSE;
	else {
		if((*T)->data == key)
			return Dele(T);
		else if((*T)->data > key)
			return DeleBST(&(*T)->lchild,key);
		else 
			return DeleBST(&(*T)->rchild,key);
	}

}


/*
* @description:具体的删除操作
* @more:1.如果左子树为空，则重新结它右子树；
	2.如果右子树为空，则重新结它的左子树
	3.如果左右子树都部位空，则用节点的前驱代替要删除的节点
	 且调整各项指针
*/
Status Dele(BiTree *p) {
	BiTree s,q;

	s = q = NULL;

	//如果左子树为空，则重新接为右子树
	if(! (*p)->lchild) {
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	//如果右子树为空，则重新接为左子树
	else if(! (*p)->rchild) {
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	//如果左右子树都不为空
	else {
		q = *p;
		s =(*p)->lchild;
		//向左转后，一直往右走直至尽头，为了找到p的前驱节点
		while(s->rchild) {
			q = s;
			s = s->rchild;
		}

		(*p)->data = s->data;	//赋值

		//这里s节点为q的右孩子，s为p节点的前驱
		if(*p != q)
			q->rchild = s->lchild;	//把s的左孩子结为q的右孩子
		else 
			q->lchild = s->lchild;	//重新结q的左孩子
		free(s);
	}

	return TRUE;
}


/*
* @description:递归查找二叉查找树是否存在否值
*/
BiTree SearchBST(BiTree T,TElemType key) {
	if(!T || T->data == key)
		return T;
	else if(T->data > key)
		return SearchBST(T->lchild,key);
	else
		return SearchBST(T->rchild,key);
}



/*
* @中序遍历二叉排序树
*/
void InOrderTraverse(BiTree T,Status (*Visit) (TElemType)) {
	if(T) {
		InOrderTraverse(T->lchild,Visit);		
		Visit(T->data);
		InOrderTraverse(T->rchild,Visit);
	}
}


/*
* @description:打印元素值
*/
Status PrintElem(TElemType elem) {
	printf("%d\t",elem);
	return OK;
}


/*
* @description:销毁二叉排序树
*/
void  DestoryTree(BiTree *T) {
	if(*T) {
		//删除左子树
		if((*T)->lchild)
			return DestoryTree(&(*T)->lchild);
		//删除右子树
		else if((*T)->rchild)
			return DestoryTree(&(*T)->rchild);

		free(*T);
		*T = NULL;
	}
}




