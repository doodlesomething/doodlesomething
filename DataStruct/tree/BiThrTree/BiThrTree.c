/*----------------------------------------------------------------------------
	* file:BiThrTree.c
	* date:4-10-2014
	* author:doodlesomething@163.com
	* version:1.1
	* description:二叉树的线索化和遍历
------------------------------------------------------------------------------*/

#include <stdlib.h>
#include "bithrtree.h"

/*
* @param BiThrTree *T
* @return Status
* @description:前序建立二叉树
*/
Status CreateBiThrTree(BiThrTree *T) {
	TElemType ch;
	
	scanf("%c",&ch);

	if(ch == '#') 
		*T = NULL;
	else {
		*T = (BiThrTree) malloc(sizeof(struct BiThrNode));
		if(!(*T))
			exit(OVERFLOW);

		(*T)->data = ch;

		//递归建立左右子树
		CreateBiThrTree(&(*T)->lchild);
		//存在左孩子
		if((*T)->lchild)
			(*T)->LTag = Link;

		CreateBiThrTree(&(*T)->rchild);
		//存在右孩子
		if((*T)->rchild)
			(*T)->RTag = Link;
	
	}

	return OK;
}




/*
* @param BiThrTree *Thrt
* @param BiThrTree T
* @return Status
* @description:中序线索化二叉树
* @more:为了方便，在二叉树的线索链表上添加一个头结点,并它的lchild域的指针指向二叉树的根节点
，它的rchild节点指针指向中序遍历时访问的最后一个节点；同样，让二叉树中的第一个节点(非头结点)
的lchild指针指向头节点，中序遍历中最后一个访问的节点的rchild指向头节点(构成了链表)
  这里预设一个pre指针始终指向刚刚访问过的节点
*/
Status InOrderThread(BiThrTree *Thrt,BiThrTree T) {
	//建立头结点
	*Thrt = (BiThrTree) malloc(sizeof(struct BiThrNode));

	if(!(*Thrt))
		exit(OVERFLOW);

	//如果T不为空则头节点存在即根节点
	(*Thrt)->LTag = Link;
	(*Thrt)->RTag = Thread;

	//由于最后一个访问节点没有确定，故指针回指
	(*Thrt)->rchild = *Thrt;

	//若T为空树则指针回指
	if(T == NULL)
		(*Thrt)->lchild = *Thrt;
	else {	
		//头结点的左孩子为树的根节点
		(*Thrt)->lchild = T;
		//pre指向刚刚访问过的节点
		pre = *Thrt;
		//中序遍历线索化二叉树T
		InThreading(T);

		//最后一个结点指向头结点
		pre->rchild = *Thrt;
		pre->RTag = Thread;

		//头结点指向最后一个访问的节点
		(*Thrt)->rchild = pre;
	}

	return OK;
}


/*
* @description:中序遍历线索化二叉树
*/
void InThreading(BiThrTree p) {
	if(p) {

		if(p->LTag == Link)
			InThreading(p->lchild);	//线索化左子树

		//在当前节点和刚刚访问过的节点间建立关系
		if(! p->lchild) {
			p->LTag = Thread;
			p->lchild = pre;
		}
		//刚刚访问过的节点为当前节点的前驱；当前节点为刚刚访问过的节点的后继
		if(!pre->rchild) {
			pre->RTag = Thread;
			pre->rchild = p;
		}
		
		pre = p;	//保持pre为刚刚访问过的节点
		if(p->RTag == Link)
			InThreading(p->rchild);	//线索化右子树
	}
}



/*
* @description:为二叉树增加头结点和前序线索话二叉树
*/

Status PreOrderThread(BiThrTree *Thrt,BiThrTree T) {
	//建立头结点
	*Thrt = (BiThrTree) malloc(sizeof(struct BiThrNode));

	if(!(*Thrt))
		exit(OVERFLOW);

	//如果T不为空则头节点存在即根节点
	(*Thrt)->LTag = Link;
	(*Thrt)->RTag = Thread;

	//由于最后一个访问节点没有确定，故指针回指
	(*Thrt)->rchild = *Thrt;

	//若T为空树则指针回指
	if(T == NULL)
		(*Thrt)->lchild = *Thrt;
	else {	
		//头结点的左孩子为树的根节点
		(*Thrt)->lchild = T;
		//pre指向刚刚访问过的节点
		pre = *Thrt;
		//中序遍历线索化二叉树T
		PreThreading(T);

		//最后一个结点指向头结点
		pre->rchild = *Thrt;
		pre->RTag = Thread;

		//头结点指向最后一个访问的节点
		(*Thrt)->rchild = pre;
	}

	return OK;
}



/*
* @description:前序遍历线索化二叉树
*/
void PreThreading(BiThrTree p) {
	if(p) {

		//在当前节点和刚刚访问过的节点间建立关系
		if(! p->lchild) {
			p->LTag = Thread;
			p->lchild = pre;
		}
		//刚刚访问过的节点为当前节点的前驱；当前节点为刚刚访问过的节点的后继
		if(!pre->rchild) {
			pre->RTag = Thread;
			pre->rchild = p;
		}
		
		pre = p;	//保持pre为刚刚访问过的节点

		if(p->LTag == Link)
			PreThreading(p->lchild);	//线索化左子树
		if(p->RTag == Link)
			PreThreading(p->rchild);	//线索化右子树
	}
}



/*
* @description:中序遍历线索二叉树
*/
Status InOrderTraverse_Thr(BiThrTree T,Status (*Visit) (TElemType elem)) {
	BiThrTree p;

	//找到根节点
	p = T->lchild;	
	//当p == T时树为空或者遍历已经结束
	while(p != T) {
		//找到中序遍历中的第一个节点
		while(p->LTag == Link)
			p = p->lchild;

		if(!Visit(p->data))
			return ERROR;

		//当前节点的右孩子不是头节点
		while(p->RTag == Thread && p->rchild != T) {
			p = p->rchild;
			Visit(p->data);
		}

		p = p->rchild;
	}

	return OK;
}



/*
* @description:前序遍历线索二叉树
*/
Status PreOrderTraverse_Thr(BiThrTree T,Status (*Visit) (TElemType elem)) {
	BiThrTree p;

	//找到根节点
	p = T->lchild;	
	//当p == T时树为空或者遍历已经结束
	while(p != T) {
		if(!Visit(p->data))
			return ERROR;

		if(p->LTag == Link)
			p = p->lchild;

		else
			p = p->rchild;
	}

	return OK;
}




/*
* @description:打印节点元素
*/
Status PrintElem(TElemType elem) {
	printf("%c",elem);
	return OK;
}

