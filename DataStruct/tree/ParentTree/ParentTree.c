/*------------------------------------------------------------------------
	*file:ParentTree.c
	*date:10-4-2014
	*author:doodlesomething@163.com
	*version:1.0
	*description:双亲表示法建树和操作
-------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include "parenttree.h"
#include "linkqueue.h"

/*
* @descripton:初始化树
*/
Status InitTree(PTree *T) {
	(*T).n = 0;
	return OK;
}

/*
* @description:创建树
*/
Status CreateTree(PTree *T) {
	LinkQueue Q;
	QElemType q,qq;
	int i,j,len;

	//莫忘初始化
	i = 0;

	char arr[MAX_TREE_SIZE];	//暂存数组

	InitQueue(&Q);
	//赋值根节点
	printf("please enter the root of the tree:");
	scanf("%c%*c",&(*T).nodes[0].data);

	if((*T).nodes[0].data != NULL) {
		//根节点没有父亲节点，指向-1
		(*T).nodes[0].parent = -1;
		qq.name = (*T).nodes[0].data;
		qq.num = 0;

		EnQueue(&Q,qq);

		while(i < MAX_TREE_SIZE && !QueueEmpty(Q)) {
			DeQueue(&Q,&qq);
			//输入每个节点的孩子
			printf("please enter the child of %c:",qq.name);
			
			len = GetLine(arr,MAX_TREE_SIZE);

			if(len < 1)
				break;

			//将每个节点的孩子顺序入队
			for(j = 0; j < len;j++) {
				++i;
				(*T).nodes[i].data = arr[j];
				(*T).nodes[i].parent = qq.num;
				q.num = i;
				q.name = arr[j];
				EnQueue(&Q,q);
			}

		}

		if(i > MAX_TREE_SIZE)
			exit(OVERFLOW);

		(*T).n = i;

		return OK;
	}
	else {
		(*T).n = 0;
		return ERROR;
	}

}

/*
* @description:由于gets不安全,fgets无法满足要求，故需要实现一个函数获取不定长的行
*/
int GetLine(char *arr,int lim) {
	char c;
	int i = 0;

	while( (c =getchar()) != '\n' && i < lim)
		arr[i++] = c;

	return i;
}


/*
* @description:清空数(注意这里的清空仅仅是一种障眼法上的清空)
*/
Status ClearTree(PTree *T)	{
	(*T).n = 0;
	return OK;
}


/*
* @description:判空
*/
Status TreeEmpty(PTree T) {
	return T.n == 0;
}

/*
* @description:返回树的总节点
*/
int TreeLength(PTree T) {
	return T.n;
}

/*
* @description:求树的深度
*/
int TreeDepth(PTree T) {
	int k,m,def,max;

	max = 0;
	//这里的方法在于找到最深的层
	for(k = 0;k < T.n;k++) {
		def = 1;	//初始化本次顺寻中def的值
		m = T.nodes[k].parent;

		while(m != -1) {
			m = T.nodes[m].parent;
			def++;
		}
	}

	if(max < def)
		max = def;

	return max;
}

/*
* @description:返回树的根的值
*/
TElemType Root(PTree T)	{
	if(!TreeEmpty(T))
		return T.nodes[0].data;
	else
		return NULL;
}

/*
* @descripton:返回树中第i个节点的值
*/
TElemType Value(PTree T,int i) {
	if(i < T.n)
		return T.nodes[i].data;
	else
		return NULL;
}

/*
* @description:cur_e是树中节点的值,该cur_e为value(保证树中节点值唯一，否则只能修改第一个)
*/
Status Assign(PTree *T,TElemType cur_e,TElemType value) {
	int i;

	for(i = 0;i < (*T).n ;i++) {
		if((*T).nodes[i].data == cur_e) {
			(*T).nodes[i].data = value;
			return OK;
		}
	}

	return ERROR;
}


/*
* @description:返回父亲节点的值
*/
TElemType Parent(PTree T,TElemType cur_e) {
	int i;

	for(i = 0; i < T.n; i++)
		if(T.nodes[i].data == cur_e)
			return T.nodes[T.nodes[i].parent].data;

	return NULL;
}


/*
* @description:根据某个在树中的值，返回其左孩子的值
		这里认为最左边的为左孩子，不存在右孩子的说法
*/
TElemType LeftChild(PTree T,TElemType cur_e) {
	int i,j;

	for(i = 0;i < T.n;i++)
		if(T.nodes[i].data == cur_e)
			break;
	for(j = i+1;j < T.n ;j++)
		if(T.nodes[j].parent == i)
			return T.nodes[j].data;
	
	return NULL;
}

/*
* @description:返回右兄弟的值(这里的右兄弟是指下一个与它有共同parent的节点)
*/
TElemType RightSibling(PTree T,TElemType cur_e) {
	int i;

	for(i = 0;i < T.n; i++)
		if(T.nodes[i].data == cur_e)
			break;
	
	if(T.nodes[i].parent == T.nodes[i+1].parent )
		return T.nodes[i+1].data;

	return NULL;
}



/*
* @description:返回左兄弟的值(这里的左兄弟是指上一个与它有共同parent的节点)
*/
TElemType LeftSibling(PTree T,TElemType cur_e) {
	int i;

	for(i = 0;i < T.n; i++)
		if(T.nodes[i].data == cur_e)
			break;
	
	if(T.nodes[i-1].parent == T.nodes[i].parent )
		return T.nodes[i-1].data;

	return NULL;
}


/*
* @description:遍历
*/
Status TreeTraverse(PTree T,Status (*Visit) (TElemType)) {
	int i;

	if(!TreeEmpty(T))
		for(i = 0;i <= T.n ; i++)
			Visit(T.nodes[i].data);
	return OK;
}

/*
* @description:打印元素
*/
Status PrintElem(TElemType elem) {
	printf("%c",elem);
	return OK;
}


/*
* @description:更加清晰的打印方式
*/
void PrintTree(PTree T) {
	int i;
	printf("该树共有%d个节点\n",T.n);
	printf("Node		Parent\n");

	for(i = 0;i < T.n; i++) {
		printf("%c(%d)",Value(T,i),i);
		if(T.nodes[i].parent >= 0)
			printf("		%c(%d)\n",Value(T,T.nodes[i].parent),T.nodes[i].parent);
		else
			printf("		\n");
	}
}
