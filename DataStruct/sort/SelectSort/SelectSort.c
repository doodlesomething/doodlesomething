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


/*
* @description:对左右两部分进行合并
*/
void Merge(ElemType *SR,ElemType *TR,int i,int m,int n) {
	int j,k;
	/*
	由于前后两部分都是有序的，故可以采用前后中一个元素比较的方法
	设置两个指针，k主要是起到了控制下标的作用，只有在两部分都是
	有序的情况下才可以用这种办法
	*/
	for(j = m + 1,k = i; i <= m && j <= n ; k++) {
		if(SR[i].key < SR[j].key)
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}

	//将前半部分剩余的移入TR
	if(i <= m)
		while(i <= m)
			TR[k++] = SR[i++];

	//将后半部分剩余的移入TR,注意这两种情况不会同时出现
	if(j <= n)
		while(j <= n)
			TR[k++] = SR[j++];

}


/*
* @description:具体的归并排序实现
*/
void MSort(ElemType *SR,ElemType *TR1,int s,int t) {
	int m;
	ElemType TR2[MAXSIZE + 1];

	if(s == t)
		TR1[s] = SR[s];
	else {
		//找到中间值
		m = (s + t) / 2;

		MSort(SR,TR2,s,m);	//对左半部分进行归并排序
		MSort(SR,TR2,m + 1,t);	//对右半部分进行归并排序
		Merge(TR2,TR1,s,m,t);	//将左右两部分进行归并
	}

}




/*
* @description:归并排序
*/
void MergeSort(SqList *L) {
	MSort((*L).r,(*L).r,1,(*L).length);
}



