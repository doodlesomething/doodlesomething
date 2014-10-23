/*-----------------------------------------------------------------------------
	* FileName:SelectSort.c
	* date:10-22-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:选择排序,包括简单选择排序和堆排序
------------------------------------------------------------------------------*/


#include "sort.h"


/*
* @description:交换两元素位置
*/
void swap(SqList *L,int i,int j) {
	ElemType temp;
	temp = (*L).r[i];
	(*L).r[i] = (*L).r[j];
	(*L).r[j] = temp;
}



/*
* @description:返回i至L.length最小的关键词的序号
*/
int SelectMinKey(SqList L,int i) {
	KeyType min;
	int k,j;
	min = L.r[i].key;

	for(j = i + 1 ; j <= L.length ; j++)
		if(L.r[j].key < min) {
			k = j;
			min = L.r[j].key;
		}

	return k;
}



/*
* @description:简单选择排序
*/
void SelectSort(SqList *L) {
	int i,j;
	for(i = 1; i < (*L).length ; i++) {
		j = SelectMinKey(*L,i);
		if(i != j)
			swap(L,i,j);
	}
}


/*
* @descirption:调整使堆成为大顶堆，即堆顶的元素为最大值
*/
void HeapAdjust(SqList *L,int s,int m) {
	int i;
	ElemType elem;

	elem = (*L).r[s];
	//这里的2 * s是由完全二叉树的性质得来的，同样递增量也是完全二叉树的性质
	for(i = 2 * s; i <= m ; i *= 2) {
		//比较其左右孩子
		if(i < m && (*L).r[i].key < (*L).r[i + 1].key)
			i++;

		if(elem.key >= (*L).r[i].key)
			break;
		//这里和最后面的一句起到了交换两个值的作用
		(*L).r[s] = (*L).r[i];
		s = i;
	}

	//插入
	(*L).r[s] = elem;
}



/*
* @description:堆排序
* @more:理解上有很大的困难,蛋疼的东西
*/
void HeapSort(SqList *L) {
	int i;
	/*
	建立大顶堆
	这里之所从(*L).length/2开始遍历是因为堆是一棵完全二叉树，
	由完全二叉树的性质可得
	逆序遍历是因为其是从下往上的建堆过程
	*/
	for(i = (*L).length / 2; i > 0 ; i--) 
		HeapAdjust(L,i,(*L).length);
	//下面才是真正的排序部分
	for(i = (*L).length ; i > 1; i--) {
		swap(L,1,i);
		HeapAdjust(L,1,i - 1);
	}

}


