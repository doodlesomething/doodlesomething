/*------------------------------------------------------------------------
	*file:ParentTree.c -->head file for ParentTree.c
	*date:10-4-2014
	*author:doodlesomething@163.com
	*version:1.0
	*description:双亲表示法建树和操作
-------------------------------------------------------------------------*/

#include "comman.h"

#ifndef _Parent_H

#define MAX_TREE_SIZE 100

typedef struct {
	TElemType data;
	int parent;	//指示双亲位置
}PTNode;

typedef struct {
	PTNode	nodes[MAX_TREE_SIZE];
	int n;	//总节点数
}PTree;




//初始化
Status InitTree(PTree *T);

//创建数
Status CreateTree(PTree *T);

//清空树
Status ClearTree(PTree *T);

//判空
Status TreeEmpty(PTree T);

//总节点数目
int TreeLength(PTree T);

//求树的深度
int TreeDepth(PTree T);

//返回树的根的值
TElemType Root(PTree T);

//返回树中第i个节点的值
TElemType Value(PTree T,int i);

//修改节点值
Status Assing(PTree *T,TElemType cur_e,TElemType vaule);

//返回父亲节点的值
TElemType Parent(PTree T,TElemType cur_e);

//返回左孩子的值
TElemType LeftChild(PTree T,TElemType cur_e);

//返回右兄弟的值
TElemType RightSibling(PTree T,TElemType cur_e);

//返回左兄弟的值
TElemType LeftSibling(PTree T,TElemType cur_e);

//遍历
Status TreeTraverse(PTree T,Status (*Visit) (TElemType));

//打印元素
Status PrintElem(TElemType elem);

//打印树
void PrintTree(PTree T);

int GetLine(char *arr,int lim);


#endif

