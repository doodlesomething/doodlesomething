/*--------------------------------------------------------------------------------------
	* file:StaticSearch.c
	* date:10-18-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:静态查找表
	* more:包括顺序表的查找/折半查找/静态树表查找
----------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "staticsearch.h"

/*
	@description:创建顺序表,长度为n,数据由Data提供
*/
Status Create_Seq(SSTable *S,int n,ElemType *Data) {
	int i;

	if(n < 0)
		return ERROR;
	//申请空间,第0个留空,后面会使用到
	(*S).elem = (ElemType *) malloc( (n + 1) * sizeof(ElemType));
	if(!(*S).elem)
		exit(STACKOVER);
	//赋值
	for(i = 1 ; i <= n; i++ )  {
		(*S).elem[i] = Data[i - 1];
	}
	
	(*S).length = n;

	return OK;
}



/*
* @description:顺序查找，找到则返回元素位置，否则返回0
* @more:这里监视哨的作用是，为了避免每次循环都判断i是否小于0
	而且即使最后查找不成功也会返回0,程序变得简介
*/
int Search_Seq(SSTable S,KeyType key) {
	int i;
	S.elem[0].key = key;	//监视哨

	for(i = S.length ;!EQ(S.elem[i].key,key); i-- )
		;
	return i;
}


/*
* @description:将顺序表按关键词有序化(增序)
* @more:注意这里的最小值是一直在前面的 --》选择排序
*/
void Ascend(SSTable *S) {
	int i,j,k;

	for(i = 1; i < (*S).length ; i++) {
		k = i;
		(*S).elem[0] = (*S).elem[i];
		//在待排序的缘续中选择一个最小的
		for(j = i + 1; j <= (*S).length ; j++) {
			if(LT((*S).elem[j].key,(*S).elem[0].key)) {
				k = j;
				(*S).elem[0] = (*S).elem[j];
			}
		}
		/*
			表示有更小的值,则交换位置
			注意这里的(*S).elem并不是第三变量，其永远只复制给i
		*/
		if(i != k) {
			(*S).elem[k] = (*S).elem[i];
			(*S).elem[i] = (*S).elem[0];
		}
	}
}





/*
* @description:折半查找(折半查找建立在有序表上的)
*/
int Search_Bin(SSTable S,KeyType key) {
	int low,high,mid;

	low = 1;
	high = S.length;

	while(low <= high ) {
		mid = (low + high) / 2;
		//向前找
		if(LT(key,S.elem[mid].key))
			high = mid - 1;
		//向后找
		else if(LT(S.elem[mid].key,key))
			low = mid + 1;
		else
			return mid;
	}

	return 0;
}



/*
* @description:创建一个长度为n的增序的顺序表
*/
Status Create_Ord(SSTable *S,int n,ElemType *Data) {
	Status f;
	f = Create_Seq(S,n,Data);
	if(f)
		Ascend(S);

	return f;
}



/*
* @description:销毁顺序表
*/
void Destory(SSTable *S) {
	free((*S).elem);
	(*S).elem = NULL;
	(*S).length = 0;
}


/*
* @description:构造次优查找树,递归的思想无处不在
*/
void SecondOptimal(BiTree *T,ElemType R[],int sw[],int low,int high) {
	int i,j,dw,min;

	i = low;
	min = abs(sw[high] - sw[low]);
	dw = sw[high] - sw[low - 1];

	//选择最小的
	for(j = low + 1; j <= high ; j++) {
		if( abs(dw - sw[j] - sw[j - 1]) < min) {
			i = j;
			min = abs(dw - sw[j] - sw[j - 1]);
		}
	}

	//生成节点
	*T = (BiTree) malloc(sizeof(struct BiTNode));
	if(!(*T))
		exit(STACKOVER);
	(*T)->data = R[i];
	
	if(i == low)
		(*T)->lchild = NULL;
	else
		SecondOptimal(&(*T)->lchild,R,sw,low,i - 1);	//构造左子树
	
	if(i == high) 
		(*T)->rchild = NULL;
	else
		SecondOptimal(&(*T)->rchild,R,sw,i + 1,high);	//构造右子树
}

/*
* @description:创建有序的次优查找树
*/
Status CreateSOSTree(BiTree *T,SSTable S) {
	int *sw;	//存放累计权值
	
	if(S.length == 0)
		return ERROR;
	else {
		sw = (int *) malloc( (S.length + 1) * sizeof(int));
		if(!sw)
			exit(STACKOVER);
		FindSW(sw,S);
		SecondOptimal(T,S.elem,sw,1,S.length);
	}

	return OK;
}


/*
* @description:累计权值
*/
void FindSW(int *sw,SSTable S) {
	int i;

	sw[0] = 0;
	for(i = 1; i <= S.length; i++)
		sw[i] = S.elem[i].weight + sw[i - 1];
}


/*
* @description:静态树表的查找
* @more:注意这里T传进来之后是会改变的，即下次就不能在使用T来作为查找树了
	且这里无法返回在原来中的位置的，当然可以考虑加入一个记录序号的域
*/
Status  Search_SOSTree(BiTree *T,KeyType key) {
	while(*T) {
		if((*T)->data.key == key)
			return OK;
		else if((*T)->data.key > key)
			(*T) = (*T)->lchild;
		else
			(*T) = (*T)->rchild;
	}

	return ERROR;
}



/*
* @description:遍历顺序表
*/
Status Traverse(SSTable S,Status (*Visit) (KeyType)) {
	int i;

	for(i = 1; i <= S.length ; i++) 
		Visit(S.elem[i].key);

	return OK;
}

/*
* @description:打印关键词
*/
Status PrintElem(KeyType key) {
	printf("%d\t",key);
	return OK;
}



/*
* @description:前序遍历树
*/
Status PreOrderTraverse(BiTree T,Status (*Visit) (KeyTYpe)) {
	if(T) {
		if(Visit(T->data.key))
			if(PreOrderTraverse(T->lchild,Visit))
				if(PreOrderTraverse(T->rchild,Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}
