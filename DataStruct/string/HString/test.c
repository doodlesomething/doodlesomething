/*-------------------------------------------------------------------------
	* file:test.c -->test file for HString 
	* date:28-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:串的链式存储操作基本集
--------------------------------------------------------------------------*/


#include <stdio.h>
#include "hstring.h"

int main(int argc,char *argv[]) {
	HString H,T,Sub,S;
	char str[]="123456";
	char arr[]="12345678";
	StrAssign(&H,str);
	StrAssign(&T,arr);
	PrintStr(H);
	printf("\n");
	PrintStr(T);
	printf("\n");
	printf("Length:%d,compare:%d\n",StrLength(H),StrCompare(H,T));
	SubString(&Sub,H,2,3);
	PrintStr(Sub);
	printf("\n");
	StrConcat(&S,H,T);
	printf("\n");
	PrintStr(S);
}
