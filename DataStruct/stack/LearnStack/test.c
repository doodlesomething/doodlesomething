
/*--------------------------------------------------------------
	*file:ListStack.c
	*date:23-9-2014
	*author:doodlesomething@163.com
	*version:1.0
	*description:栈的应用-->进制转换/括号匹配/行编辑
----------------------------------------------------------------*/

#include "liststack.h"
#include <stdio.h>

int main(int argc,char *argv[]) {
	int n,N;
	char str[100];

	/*
	printf("Please enter N and n:");
	scanf("%d%d",&N,&n);
	DecToAny(n,N);
	printf("\n");
	*/

	/*
	printf("Please enter the string");
	gets(str);
	if(BracketsMatch(str))
		printf("Match\n");
	else 
		printf("UnMatch\n");
	
	*/
	LineEdit();
	
	/*
	请不要放在一块测，容易产生未知错误

	1.进制转换测试用例结果：
	100 8
	>>144

	16 16
	>>10

	16 2
	>>1000
	
	2.括号匹配测试用例结果：
	[]{}
	>>Match
	
	abajdkjeir[eirie]afdrei
	>>Match

	ahfidarieroerereo
	>>UnMatch


	3.行编辑测试用例：
	 whil#le
	 >>while

	 while#abcd@test
	>>test

	while@
	>>
	*/
	
}
