/*------------------------------------------------------------------
	* file:test.c -->test file fot HuffmanTree.c
	* date:10-7-2014
	* author:doodlesomething@163.com
	* version:1.2
	* description:赫夫曼树的编码和解码
	* more:这里没有做输入检测，个数应该对应，有需要的自己增加检测
-----------------------------------------------------------------------*/

#include <stdio.h>
#include "huffmantree.h"

int main(int argc,char *argv[]) {
	int *w;
	char c;
	char *str,*arr;
	char code[100];
	int i,n,j;
	HuffmanTree HT;
	HuffmanCode HC;

	j = 0;

	//输入预定个数
	printf("please enter the number of total weigth:");
	scanf("%d",&n);

	w = (int *) malloc(n * sizeof(int));
	str = (char *) malloc(n * sizeof(char));
	arr = (char *) malloc(n * sizeof(char));

	//输入权
	printf("please enter the weights:\n");
	for(i = 0;i < n;i++)
		scanf("%d",w + i);

	//输入权值对应字符
	printf("please enter the str:\n");
	for(i = 0;i < n;) {
		if( (c = getchar()) != '\n') {
			*(str + i) = c;
			i++;
		}
	}

	//编码
	HuffmanCoding(&HT,&HC,w,str,n);
	
	//输出编码后的结果
	printf("\nthe result after coding:\n");
	//相对puts来说fputs会更加安全
	for(i = 1;i <= n;i++) {
		printf("%c:",*(str + i - 1));
		fputs(HC[i],stdout);
		printf("\n");
	}

	//输入需要解码的二进制数
	printf("\nplease enter the code to decode,enter # to end the input:");
	while( (c = getchar()) != '#') {
		code[j] = c;
		j++;
	}

	code[j] = '\0';

	//解码
	HuffmanDecode(HT,code,arr,n);

	//输出解码结果
	while(*arr != '\0')  {
		printf("%c",*arr);
		arr++;
	}

	printf("\n");

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
