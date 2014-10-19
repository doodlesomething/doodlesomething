/*--------------------------------------------------------------------------------
	* file:AVL.c
	* date:10-29-2014
	* author:doodlesomething@163.com
	* version:1.o
	* description:平衡二叉树的建立查找
	* more:包括建立(插入)/遍历/查找	--->这东西真不是人看的
--------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "avl.h"



/*
* @descripton:树的初始化
*/
Status InitTree(BiTree *T) {
	*T = NULL;
	return TRUE;
}




/*
* @description:插入平衡二叉树中不存在的元素值，并保证树的平衡性
* @more:这个真心问候很多人的祖宗
* @param Status *taller	 用于判断是否有新节点加入树中
*/
Status InsertAVL(BiTree *T,TElemType key,Status *taller) {
	

	//当树或者子树为空的情况,则需要生成新节点
	if(!(*T)) {
		*T = (BiTree)  malloc(sizeof(struct BiTNode));
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->data = key;
		//标记有新节点加入
		*taller = TRUE;
		(*T)->bf = EH;
	}
	else {
		//树中已经存在相同的节点值则不插入
		if((*T)->data == key) {
			*taller = FALSE;
			return FALSE;
		}
		//当前节点的值大于key则说明应该往左边找或插入
		if((*T)->data > key) {
			//没有插入则返回FALSE
			if(!InsertAVL( &(*T)->lchild,key,taller )) 
				return FALSE;
			//已经插入到左边且左边增高
			if(*taller) {
				switch((*T)->bf) {
					//原本左子树比右子树高则在往左边加入新界点后，则需要做左平衡
					case LH:
						LeftBalance(T);
						*taller = FALSE;
					break;
					//原本左右子树高度相等，加入新节点后，现在左子树高于右子树
					case EH:
						(*T)->bf = LH;
						*taller = TRUE;
					break;
					//原本右子树高于左子树，加入新节点后，现在左右子树高度相等
					case RH:
						(*T)->bf = EH;
						*taller = FALSE;
						break;
				}
			}
		}
		else {
			if(! InsertAVL(&(*T)->rchild,key,taller)) {
				*taller = FALSE;
				return FALSE;
			}
			//成功往右插入节点，且右边增高
			if(*taller) {
				switch((*T)->bf) {
					//原来左子树高于右子树，现在加入新节点后，左右子树高度相等
					case LH:
						(*T)->bf = EH;
						*taller = FALSE;
					break;
					//原来左右子树高度相等，现在加入新节点后，右子树高度高于左子树
					case EH:
						(*T)->bf = RH;
						*taller = TRUE;
					break;
					//原来右子树高于左子树，现在往右加入新节点后，需要做右平衡
					case RH:
						RightBalance(T);
						*taller = FALSE;
					break;
				}
			}
		}
	}

	return TRUE;
}




/*
* @description:左平衡-->旋转处理
*/
Status LeftBalance(BiTree *T) {
	BiTree lc,rd;
	//指向*T的左子树根节点
	lc = (*T)->lchild;
	switch(lc->bf) {
		//新节点插在了*T的左孩子的左子树，则需要做单右旋处理
		case LH:
			(*T)->bf = lc->bf = EH;
			R_Rotate(T);
		break;
		//新节点插在了*T的左孩子的右子树上，则需要双旋处理，先左后右
		case RH:
			rd = lc->rchild;
			//关于LH和RH的情况不是明白，有明白的求教
			switch(rd->bf) {
				case LH:
					(*T)->bf = RH;
					lc->bf = EH;
				break;

				case EH:
					(*T)->bf = lc->bf = EH;
				break;

				case RH:
					(*T)->bf = EH;
					lc->bf = LH;
				break;
			}

			rd->bf = EH;
			//先做左旋转，针对*T的左孩子
			L_Rotate(&(*T)->lchild);
			//对*T做右旋转
			R_Rotate(T);

		break;
	}

	return TRUE;
}


/*
* @description:右平衡
*/
Status RightBalance(BiTree *T) {
	BiTree lc,rd;
	//指向*T的右孩子
	lc = (*T)->rchild;

	switch(lc->bf) {
		case RH:
			(*T)->bf = lc->bf = EH;
			L_Rotate(T);
		break;
		//新节点插入在*T的右孩子的左子树上
		case LH:
			//指向*T的右孩子的左孩子
			rd = lc->lchild;
			switch(rd->bf) {
				case LH:
					(*T)->bf = EH;
					lc->bf = RH;
				break;

				case EH:
					(*T)->bf = lc->bf = EH;
				break;

				case RH:
					(*T)->bf = LH;
					lc->bf = EH;
				break;
			}
			rd->bf = EH;
			//先将*T的右孩子为根节点的子树右旋转
			R_Rotate(&(*T)->rchild);
			//再左旋
			L_Rotate(T);
		break;
	}


	return TRUE;
}



/*
* @description:左旋转
*/
void L_Rotate(BiTree *p) {
	BiTree lc;

	lc = (*p)->rchild;
	//这一行的作用不明白
	(*p)->rchild = lc->lchild;

	lc->lchild = *p;
	//将*p重新调整
	*p = lc;
}


/*
* @description:右旋转
*/
void R_Rotate(BiTree *p) {
	BiTree lc;
	//lc指向*p的左孩子
	lc = (*p)->lchild;
	//这一行的作用不明白
	(*p)->lchild = lc->rchild;
	
	//*p成为lc的右孩子
	lc->rchild = *p;
	//将*p指向调整
	*p = lc;
}


/*
* @description:平衡二叉树查找
*/
BiTree SearchTree(BiTree T,TElemType key) {
	//找到
	if(!T || T->data == key)
		return T;
	//往左子树找
	else if(T->data > key)
		return SearchTree(T->lchild,key);
	//往右子树找
	else
		return SearchTree(T->rchild,key);
}




/*
* @description:中序遍历平衡二叉树
*/
void InOrderTraverse(BiTree T,Status (*Visit) (TElemType)) {
	if(T)  {
		//中序遍历左子树
		InOrderTraverse(T->lchild,Visit);
		//输出当前节点
		Visit(T->data);
		//中序遍历右子树
		InOrderTraverse(T->rchild,Visit);
	}
}


//打印节点值
Status PrintElem(TElemType elem) {
	printf("%d\t",elem);
	return TRUE;
}




