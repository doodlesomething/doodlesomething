/*-----------------------------------------------------------------------------------
	* FileName:InsertSort.c
	* date:10-22-2014
	* author:doodlesomething@163.com
	* decription:插入排序(为了理解透彻这里加上大量的注释)
---------------------------------------------------------------------------------------*/


#include <stdlib.h>
#include "sort.h"


/*
* @description:直接插入排序
* @more:基本思想：将一个新的元素插入到已经排序好的有序表中
	从而得到一个新的/记录数增1的有序表
	因此可利用这种思想，把顺序表中的每个元素都当成是即将
	要插入的元素，而顺序表中原来就只要第一个元素，随着
	遍历的进行，顺序表增大，也就是完成了排序
	时间复杂度为O(n的平方)
*/
void InsertSort(SqList *L) {
	int i,j;
	//把i = 2第一个元素视为目前有序表中唯一的元素,之后依次增加
	for(i = 2; i <= (*L).length ; i++) {
		//当前要"插入"的元素，并顺序表中的“最后一个，即前一个”元素小，即表示要往前插，否则不动
		if((*L).r[i].key < (*L).r[i - 1].key) {
			//暂存于哨兵，哨兵这个技巧很好，这里起到了防止数组访问越界的作用
			(*L).r[0] = (*L).r[i];
			//由于有哨兵暂存了第i个元素，可直接进行赋值,这一行也可以合并到下面的循环中
			(*L).r[i] = (*L).r[i - 1];
			/*
			接下来判断在第i - 1个元素的前面是否还有比当前元素大的，
			如果存在则顺序往后移动，这样就会空出一个位置，这个位置
			就是当前欲插入的元素应该放置的位置
			*/
			for(j = i - 2; (*L).r[0].key < (*L).r[j].key ; --j)
				(*L).r[j + 1] = (*L).r[j];
			//上面的循环最后减了一，应该加回来
			(*L).r[j + 1] = (*L).r[0];
		}
	}

}



/*
* @description:折半插入排序
* @more:结合了折半查找和直接插入排序的思想，是比较次数有所减少
	但时间复杂度也是O(n的平方)
*/
void BInsertSort(SqList *L) {
	int i,j,low,high,m;

	for(i = 2; i <= (*L).length ; i++) {
		//哨兵暂存
		(*L).r[0] = (*L).r[i];
		low = 1;
		high = i - 1;
		//折半查找
		while(low <= high) {
			m = (low + high) / 2;
			if((*L).r[m].key < (*L).r[0].key )
				low = m + 1;
			else
				high = m - 1;
		}
		/*
		后移动元素
		注意这里如果当前要插入的元素必定为high + 1的位置(最后m减了一)
		注意这里的j 从i - 1开始，上面的插入排序也是可以这样的
		*/
		for(j = i - 1; j >= high + 1; j--)
			(*L).r[j + 1] = (*L).r[j];

		//插入
		(*L).r[high + 1] = (*L).r[0];
	}
}



/*
* @description:2-路插入排序
* @more:设置另一个空间d存储，并设置两个指针一个first指向d中最小的元素，final指向d中最大的元素
	 这里比较难以理解的是各种取模运算-->反正我是想不出来
*/
void P2_InsertSort(SqList *L) {
	int i,j,first,final;
	ElemType *d;
	d = (ElemType *) malloc((*L).length * sizeof(ElemType));
	if(!d)
		exit(OVERFLOW);
	
	d[0] = (*L).r[1];	//将L中第一个暂时作为d的最小元素
	first = final = 0;	//first和final分别指向d中最小和最大元素

	for(i = 2; i <= (*L).length ; i++) {
		//如果要插入的元素小于d中的最小元素，则插入，但是不用移动元素，注意first指针的修改
		if((*L).r[i].key < d[first].key) {
			first = (first - 1 + (*L).length ) % (*L).length;
			d[first] = (*L).r[i];
		}
		//如果当前要插入元素大于d中最大元素，则插入，但不用移动元素，注意final指针的修改
		else if((*L).r[i].key > d[final].key) {
			final++;
			d[final] = (*L).r[i];
		}
		//当前要插入的元素在最大值和最小值之间，则需要将相应的元素后移，这个注意理解
		else {
			j = final++;
			//后移元素
			while((*L).r[i].key < d[j].key) {
				d[(j + 1) % (*L).length] = d[j];
				j = (j - 1 + (*L).length) % (*L).length;
			}
			//插入
			d[j + 1] = (*L).r[i];
		}
	}


	//将d中元素复制到L中
	for(i = 1; i <= (*L).length; i++)
		(*L).r[i] = d[ (i + first - 1) % (*L).length] ;


}
