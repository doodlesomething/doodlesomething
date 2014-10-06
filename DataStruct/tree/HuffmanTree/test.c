/*------------------------------------------------------------
	* file:test.c -->test file fot HuffmanTree.c
	* date:10-6-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:赫夫曼树
--------------------------------------------------------------*/

#include <stdio.h>
#include "huffmantree.h"

int main(int argc,char *argv[]) {
	int *w;
	int i,n;
	HuffmanTree HT;
	HuffmanCode HC;

	printf("please enter the number of total weigth:");
	scanf("%d",&n);

	w = (int *) malloc(n * sizeof(int));

	printf("please enter the weights:");
	for(i = 0;i < n;i++)
		scanf("%d",w+i);

	HuffmanCoding(&HT,&HC,w,n);

	//相对puts来说fputs会更加安全
	for(i = 1;i <= n;i++) {
		fputs(HC[i],stdout);
		printf("\n");
	}

	return 0;


	/*
	测试结果：
	4
	7 5 2 4
	>>
	0
	10
	110
	111
	*/
}
