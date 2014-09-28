/*---------------------------------------------------------------------------
	* file:test.c -->test file for SSting.c
	* date:28-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:串的基本操作 --->使用定长顺序实现
---------------------------------------------------------------------------*/



#include <stdio.h>
#include "str.h"

int main(int argc,char *argv[]) {
	char str[]="aabcefabch";
	char str1[]="abc";
	char str2[]="efg";
	int arr[10];

	SString S,T,V;
	int i,num;

	StrAssign(&S,str);
	StrAssign(&T,str1);
	StrAssign(&V,str2);
	printf("len:%d,empty:%d\n",StrLength(S),StrEmpty(S));
	StrReplace(&S,T,V);
	printf("\n");
	StrPrint(S);
	printf("len:%d,empty:%d,index:%d\n",StrLength(S),StrEmpty(S),StrIndex(V,T,2));

}
