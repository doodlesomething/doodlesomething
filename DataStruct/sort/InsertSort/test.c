/*-----------------------------------------------------------------------------------
	* FileName:test.c
	* date:10-22-2014
	* author:doodlesomething@163.com
	* decription:插入排序(为了理解透彻这里加上大量的注释)
---------------------------------------------------------------------------------------*/


#include <stdio.h>
#include "sort.h"

int main() {
	SqList L;
	int i;
	void print(SqList L);
	
	ElemType arr[N] = {{49},{38},{65},{97},{76},{13},{27},{49}};
	//赋值
	for(i = 1; i <= N ; i++) 
		L.r[i] = arr[i - 1];
	L.length = N;
	
	printf("排序前:");
	print(L);
	//直接插入排序
	P2_InsertSort(&L);
	printf("排序后:");
	print(L);

	return 0;
}


void print(SqList L) {
	int i;
	for(i = 1; i <= L.length; i++)
		printf("%d\t",L.r[i].key);
	printf("\n");
}



