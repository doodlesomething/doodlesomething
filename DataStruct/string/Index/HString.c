/*-------------------------------------------------------------------------
	* file:HString.c 
	* date:28-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:串的链式存储操作基本集
--------------------------------------------------------------------------*/



#include <stdlib.h>
#include "hstring.h"

/*
* @param HString *H
* @return Status
* @description:初始化串
*/
Status InitStr(HString *H) {
	(*H).elem = NULL;
	(*H).length = 0;

	return OK;
}


/*
* @param HString *H
* @param char *str
* @return Status
* @description:由字符串str生成串S,当S原来非空时，先清空
	       当str空时则置elem为NULL
*/
Status StrAssign(HString *H,char *str) {
	int i,len;
	char *c;
	
	for(c = str,i = 0; *c ;i++,c++)
		;

	len = i;
	if(!len) {
		(*H).elem = NULL;
		(*H).length = 0;
	}

	(*H).elem = (char *) malloc(len * sizeof(char));

	if(!(*H).elem)
		exit( OVERFLOW);
	//字串复制
	for(i = 0; i < len && str; i++,str++) 
		(*H).elem[i] = *str;
	
	(*H).length = len;


	return OK;
}


/*
* @param HString H
* @return int
* @description:返回串的长度
*/
int StrLength(HString H) {
	return H.length;
}


/*
* @param HString H
* @return Status
* @description:判空
*/
Status StrEmpty(HString H) {
	return H.length == 0;
}


/*
* @param HString *H
* @return Status
* @description:清空串
*/
Status ClearString(HString *H) {
	if((*H).elem) {
		(*H).elem = NULL;
		(*H).length = 0;
	}

	return OK;
}


/*
* @description:连接两个串，到T中
*/
Status StrConcat(HString *H,HString S,HString V) {
	int i,j;

	
	(*H).elem = (char *) malloc( (S.length + V.length) * sizeof(char) );
	if(!(*H).elem)
		exit(OVERFLOW);
	
	(*H).length = S.length + V.length;

	for(i = 0;i < S.length;i++)
		(*H).elem[i] = S.elem[i];
	
	for(j=0;j < V.length;j++,i++)
		(*H).elem[i] = V.elem[j];

	return OK;
}


/*
* @param HString *Sub
* @param HString T
* @param int pos
* @param int len
* @description: 用Sub返回第pos的位置起后长度为len的子串
*/
Status SubString(HString *Sub,HString T,int pos,int len) {
	int i,j;
	
	(*Sub).elem = (char *) malloc(len * sizeof(char));
	if(!(*Sub).elem)
		exit(OVERFLOW);

	for(i = 0,j = pos; j < len + pos ;i++,j++)
		(*Sub).elem[i] = T.elem[j];

	(*Sub).length = len;
}


/*
* @param HString H
* @param HString T
* @return Status
*/
Status StrCompare(HString H,HString T) {
	int i,j;

	i = j = 0;

	for(i = 0; i < H.length && i < T.length;++i) {
		if(H.elem[i] != T.elem[i])
			return H.elem[i] - T.elem[i];
	}

	return H.length - T.length;
}


/*
* @param HString *T
* @param HString H
* @return void
* @description:复制
*/
Status StrCopy(HString *T,HString H) {
	if(!H.length)
		return ERROR;
	int i;

	(*T).elem = (char *) malloc(H.length * sizeof(char));

	if(!(*T).elem)
		exit(OVERFLOW);

	for(i = 0; i < H.length; i++)
		(*T).elem[i] = H.elem[i];

	(*T).length = H.length;
	return OK;
}


/*
* @param HString H
* @return void
* @description:打印串
*/
void PrintStr(HString H) {
	int i;

	for(i = 0;i < H.length;i++) 
		printf("%c",H.elem[i]);
}



