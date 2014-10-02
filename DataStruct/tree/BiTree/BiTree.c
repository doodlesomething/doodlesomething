/*------------------------------------------------------------------------
	* file:BiTree.c
	* date:1-10-2014
	* author:doodlesomething@63.com
	* version:1.0
	* description:二叉树的基本操作
	* attention:这里的二叉树中无法满足二叉树的节点用#代替以构成二叉树的形式，但是不会生成节点
--------------------------------------------------------------------------*/


#include <stdio.h>
#include "bitree.h"


/*
* @param BiTree *T
* @return Status
* @description:初始化二叉树
*/
Status InitBiTree(BiTree *T) {
	*T = NULL;

	return OK;
}

/*
* @param BiTree T
* @description:判空 空树则返回TRUE ，非空树返回FALSE
*/
Status BiTreeEmpty(BiTree T) {
	return T == NULL;
}


/*
* @description:二叉树的深度
* @param BiTree T
* @return int depth
*/
int BiTreeDepth(BiTree T) {
	int l,r;

	if(T) {
		l = BiTreeDepth(T->lchild);
		r = BiTreeDepth(T->rchild);
		return (l > r ? l : r) + 1; 
	}

	return 0;
}

/*
* @param BiTree T
* @return BiTree T
* @description:返回树的根
*/
Position Root(BiTree T) {
	return T;
}

/*
* @description:返回节点node的值
*/
TElemType Value(BiTree T,Position node) {
	return node->data;
}

/*
* @description:将节点node的值赋值为value
*/
Status Assign(BiTree T,Position *node,TElemType value) { 
}


/*
* @param BiTree *T
* @return Status
* @description:前序建立二叉树
*/
Status CreateBiTree(BiTree *T) {
	TElemType ch;
	
	scanf("%c",&ch);

	if(ch == '#') 
		*T = NULL;
	else {
		*T = (BiTree) malloc(sizeof(struct BiTNode));
		if(!(*T))
			exit(OVERFLOW);

		(*T)->data = ch;
		//递归建立左右子树
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}

	return OK;
}


/*
* @description:前序遍历二叉树
*/
Status PreOrderTraverse(BiTree T,Status (*visit) (TElemType elem)) {
	if(T) {
		if(visit(T->data))
			if(PreOrderTraverse(T->lchild,visit))
				if(PreOrderTraverse(T->rchild,visit))
					return OK;
		return ERROR;
	}
	
	return OK;
}


/*
* @description:中序遍历二叉树
*/
Status InOrderTraverse(BiTree T,Status (*visit)(TElemType elem)) {
	if(T) {
		if(InOrderTraverse(T->lchild,visit))
			if(visit(T->data))
				if(InOrderTraverse(T->rchild,visit))
					return OK;
		return ERROR;
	}

	return OK;
}


/*
* @description:后序遍历二叉树
*/
Status PostOrderTraverse(BiTree T,Status (*visit)(TElemType elem)) {
	if(T) {
		if(PostOrderTraverse(T->lchild,visit))
			if(PostOrderTraverse(T->rchild,visit))
				if(visit(T->data))
					return OK;
		return ERROR;
	}

	return OK;
}



/*
* @param TElemType elem
* @description:打印元素 -->遍历元素使用
*/
Status PrintElem(TElemType elem) {
	printf("%c",elem);
	return OK;
}



/*
* @param BiTree T
* @param int nLayer
* @return void
* @description:树状打印树
*/
void PrintAsTree(BiTree T,int nLayer) {
	int i;
	if(T == NULL)
		return;
	
	PrintAsTree(T->lchild,nLayer+1);
	for(i = 0; i < nLayer;i++)
		printf("  ");
	printf("%c\n",T->data);
	PrintAsTree(T->rchild,nLayer+1);
}
