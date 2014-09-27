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
	char str[]="abcdefhijk";
	char str1[]="cdef";
	char str2[]="abcdefhijk";

	SString S,T,V;

	StrAssign(&S,str);
	StrAssign(&T,str1);
	StrPrint(T);
	printf("index:%d\n",StrIndex(S,T,1));
	printf("len:%d,empty:%d\n",StrLength(S),StrEmpty(S));
	StrPrint(S);
	DeleStr(&S,1,2);
	StrPrint(S);

}
