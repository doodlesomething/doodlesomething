/*--------------------------------------------------------------------------------------
	* FileName:test.c
	* date:10-21-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:哈希表的建立/重建/查找
	* more:冲突处理采用开放地址法:Hi = (H(key) + di) mod m 
----------------------------------------------------------------------------------------*/


#include <stdio.h>
#include "hashtable.h"

int main() {
	HashTable H;
	int p,c,i,arr[100],n;

	//确定关键词个数
	printf("please enter the n:");
	scanf("%d",&n);
	
	//确定各个关键词
	printf("please enter %d numbers:",n);
	for(i = 0; i < n ; i++)
		scanf("%d,",&arr[i]);

	//插入哈希表
	InitHTable(&H);
	for(i = 0; i < n ; i++)
		InsertHash(&H,arr[i]);
	
	//遍历输出
	TraverseHTable(H,PrintElem);
	printf("\n");


	//查找
	printf("please enter the you want to look for:");
	scanf("%d",&n);
	//c在这里没有作用
	if(SearchHash(H,n,&p,&c))
		printf("There is the number:%d in %d\n",H.elem[p].key,p);
	else
		printf("Nothing you want\n");
	
	return 0;


	/*
	注意输入的数的选择合适才能体现哈希的散列性质
	测试用例:
	please enter the n:5
	please enter 5 numbers:11,3,17,90,50
	3	11	50	90	17	
	please enter the you want to look for:90
	There is the number:90 in 14

	*/

}
