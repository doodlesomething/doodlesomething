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
	SString S;

	StrAssign(&S,str);
	StrPrint(S);

}
