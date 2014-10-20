/*---------------------------------------------------------------------------------
	* FileName:BTree.c
	* date:10-20-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:B树插入和查找
	* more:这玩意又让我找了一天的bug
------------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "btree.h"


/*
* @description:初始化B树
*/
Status InitBTree(BTree *T) {
	*T = NULL;
	return TRUE;
}


/*
* @description:B树中的查找
* @more:若查找成功，则tag == 1,指向节点中和K相等的关键词
	否则tag == 0，pt指向节点的第i个元素，意味着关键词应该插入在第i和第i+1之间
*/
Result SearchBTree(BTree T,KeyType key) {
	BTree p,q;
	Status found;
	int i;
	Result r;

	//初始化
	p = T;
	q = NULL;	//q用于指向双亲节点
	found = 0;
	i = 0;

	while(p && !found) {
		//返回当前节点中等于K或是第一个大于K的关键词的序号
		i = Search(p,key);
		//找到关键词
		if(i > 0 && p->node[i].key == key)
			found = 1;
		//在当前节点查找失败
		else {
			q = p;
			p = p->node[i].ptr;	//指向下一个待查找节点
		}
	}

	r.i = i;

	//查找成功
	if(found) {
		r.pt = p;
		r.tag = 1;
	}
	//查找失败
	else {
		r.pt = q;
		r.tag = 0;
	}
	
	return r;
}



/*
* @description:返回节点中等于关键词K的下标i或是第一个大于关键词i的前一个关键词的序号
*/
int Search(BTree p,KeyType key) {
	int j,i;
		
	j = 0;

	for(i = 1; i <= p->keynum; i++) 
		if(p->node[i].key <= key)
			j = i;
	return j;
}


/*
* @description:在T的节点*q的第i和第i+1个关键词间插入关键词K,
		倘若引起节点过大，则顺的双亲链进行必要的分裂
		调整，是T仍然是m阶B树
*/
Status InsertBTree(BTree *T,KeyType key,BTree q,int i) {
	BTree ap;
	Status finished;
	int s;
	KeyType rx;
	rx = key;

	//初始化
	ap = NULL;
	finished = 0;

	while(q && !finished) {
		//插入关键词
		Insert(&q,i,rx,ap);
		//插入关键词后节点的关键词书目小于m,则插入完成
		if(q->keynum < m)
			finished = 1;
		//节点关键词数目过大,需要进行分裂
		else {
			s = (m + 1) / 2;
			//分割调整
			split(&q,&ap);
			//中间节点
			rx = q->node[s].recptr;
			//顺着父亲链往上找合适插入的节点
			q = q->parent;
			if(q)
				i = Search(q,key);
		}
	}

	//顺着父亲链往上找没有找到，则树可能为空或是根节点已经分裂，则需要生成新的根节点
	if(!finished)
		NewRoot(T,rx,ap);

	return TRUE;
}

/*
* @description:生成新的根节点
*/
void NewRoot(BTree *T,KeyType key ,BTree ap) {
	BTree p;
	p = (BTree) malloc(sizeof(struct BTNode));
	
	//调整根节点中第一个节点元素
	p->node[0].ptr = *T;
	*T = p;
	if((*T)->node[0].ptr)
		(*T)->node[0].ptr->parent = *T;

	(*T)->parent = NULL;
	(*T)->keynum = 1;
	//调整根节点的第一(唯一)个关键词
	(*T)->node[1].key = key;
	(*T)->node[1].ptr = ap;
	(*T)->node[1].recptr = key;
	if((*T)->node[1].ptr)
		(*T)->node[1].ptr->parent = *T;

}



/*
* @desciption:分割调整
*/
void split(BTree *q,BTree *ap) {
	int i,s;
	s = (m + 1) / 2;

	*ap = (BTree) malloc(sizeof(struct BTNode));
	(*ap)->node[0].ptr = (*q)->node[s].ptr;		//后一半移入新节点中

	for(i = s + 1; i <= m ; i++) {
		(*ap)->node[i - s] = (*q)->node[i];
		if((*ap)->node[i - s].ptr)
			(*ap)->node[i - s].ptr->parent = *ap;
	}

	(*ap)->keynum = m -s;
	(*ap)->parent = (*q)->parent;
	(*q)->keynum = s - 1;
}




/*
* @description:在第i个关键词后插入新的关键词
* @more:需要将第i个后所有的关键词后移，且做相应的调整
*/
void Insert(BTree *q,int i,KeyType key,BTree ap) {
	int j;

	//后移相应节点
	for( j = (*q)->keynum; j > i; j--) 
		(*q)->node[j + 1] = (*q)->node[j];
	
	//新加入节点做相应的调整
	(*q)->node[i + 1].ptr = ap;
	(*q)->node[i + 1].key = key;
	(*q)->node[i + 1].recptr = key;

	//节点关键词数目加一
	(*q)->keynum++;

}





/*
* @description:遍历输出
*/
void TraverseTree(BTree T,void (*Visit) (KeyType key)) {
	int j;

	if(T) {
		if(T->node[0].ptr)
			TraverseTree(T->node[0].ptr,Visit);
		for(j = 1; j <= T->keynum ; j++) {
			Visit(T->node[j].key);

			if(T->node[j].ptr)
				TraverseTree(T->node[j].ptr,Visit);
		}
	}
}



/*
* @description:打印元素
*/
void PrintElem(KeyType key) {
	printf("%d\t",key);
}



