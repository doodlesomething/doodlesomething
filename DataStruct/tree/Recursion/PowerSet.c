/*--------------------------------------------------------------------
	* file:PowerSet.c 
	* date:10-7-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:利用回溯和递归思想求集合的幂集
-----------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

int k = 0;
int *num2,*num1;

int main(int argc,char *argv[]) {
	int i,n;
	void PowerSet(int i,int n);

	printf("please enter the n:");
	scanf("%d",&n);

	num1 = (int *) malloc( (n + 1) * sizeof(int));
	num2 = (int *) malloc( (n + 1) * sizeof(int));

	printf("please enter the numbers:");
	//0空间不使用，这里可以方便处理
	for(i = 1;i <= n; i++) 
		scanf("%d",num1 + i);
	
	printf("{");

	PowerSet(1,n);
	
	printf("}\n");

	return 0;
}


void PowerSet(int i,int n) {
	int j;
	

	if(i > n) {
		//输出
		printf("{");
		for(j = 0;j < k -1;j++)
			printf("%d,",num2[j]);
		if(k)
			printf("%d",num2[j]);
		printf("}");
		if(k)
			printf(",");
	}
	//进行取或者是舍
	else {
		//取
		num2[k] = num1[i];
		k++;
		PowerSet(i + 1,n);
		//舍
		k--;
		PowerSet(i + 1,n);
	}
}
