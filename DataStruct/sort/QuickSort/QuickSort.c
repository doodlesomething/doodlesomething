/*--------------------------------------------------------------------------------------
	* FileName:QuickSort.c
	* date:10-22-2014
	* author:doodlesomething@163.com
	* descrption:快速排序,这里由冒泡排序逐步优化算法
----------------------------------------------------------------------------------------*/


#include "sort.h"


/*
* @description:用于交换要节点元素位置
*/
void swap(SqList *L,int i,int j) {
	ElemType temp;
	
	temp = (*L).r[i];
	(*L).r[i] = (*L).r[j];
	(*L).r[j] = temp;
}




/*
* @description:类冒泡排序
*/
void BubbleSort_1(SqList *L) {
	int i,j;
	//注意这里没有等于
	for(i = 1; i < (*L).length ; i++) {
		for(j = i + 1; j <= (*L).length; j++)
			if((*L).r[i].key > (*L).r[j].key) 
				swap(L,i,j);
	}
}


/*
* @description:冒泡排序,相邻两元素比较
* @more:这个相对于上面的优化在于冒泡在
	冒泡的过程也把相关的元素的位置
	上升了
*/
void BubbleSort_2(SqList *L) {
	int i,j;

	for(i = 1; i < (*L).length ; i++) {
		for(j = (*L).length - 1; j >= i; j-- )
			//注意这里的不同
			if((*L).r[j].key > (*L).r[j + 1].key)
				swap(L,j + 1,j);
	}
}



/*
* @description:优化之后的冒泡排序
* @more:这是顺序比较的,在部分有序的情况下体现效果
	在最坏的情况下和上面的冒泡排序是一样的
*/
void BubbleSort_3(SqList *L) {
	int i,j,flag;
	
	flag = 1;
	for(i = 1; i < (*L).length && flag; i++) {
		flag = 0;
		for(j = (*L).length - 1; j >= i; j--)  {
			if((*L).r[j].key > (*L).r[j + 1].key) {
				swap(L,j + 1,j);
				flag = 1;
			}
		}
	}

}

/*
* @descrption:快速排序具体交换操作,函数最后返回最后的基准的位置
* @more:基本思想：设置一个基准，从high一直往前找，找到第一个比
	基准值小，交换他们两；接着从low一直往后找，找到第一个
	比基准大的，交换他们两
	这里的基准预设为的第一个元素
*/
int Partition(SqList *L,int low,int high) {
	KeyType pivkey;
	//使用第0个空位来暂存基准值
	(*L).r[0] = (*L).r[low];

	pivkey = (*L).r[low].key;	//用当前的顺序表的第一个元素关键词作为基准值

	while(low < high) {
		//一直往前找
		while(low < high && (*L).r[high].key >= pivkey) 
			high--;
		//找到直接复制
		(*L).r[low] = (*L).r[high];
		
		//一直往后找
		while(low < high && (*L).r[low].key < pivkey) 
			low++;
		(*L).r[high] = (*L).r[low];

	}
	
	(*L).r[low] = (*L).r[0];
	
	return low;
}




/*
* @description:递归排序
*/
void QSort(SqList *L,int low,int high) {
	int pivloc;

	if(low < high) {
		pivloc = Partition(L,low,high);
		QSort(L,low,pivloc - 1);
		QSort(L,pivloc + 1,high);
	}
}




/*
* @description:快速排序
*/
void QuickSort(SqList *L) {
	QSort(L,1,(*L).length);
}

