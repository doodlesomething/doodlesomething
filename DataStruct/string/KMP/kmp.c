/*-------------------------------------------------------------------------
	* file:kmp.c    
	* date:28-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:KMP模式匹配算法实现
	* @more:注意此算法不是KMP改进算法(该算法的改进主要在于next数组的改进)
--------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "hstring.h"


int main(int argc,char *argv[]) {
	HString H,T;
	char str[]="124563456";
	char str1[]="345";

	StrAssign(&H,str);
	StrAssign(&T,str1);
	PrintStr(H);
	printf("\n");
	PrintStr(T);
	printf("\n");

	printf("Index_KMP:%d\n",Index_KMP(H,T,2));

	/*
	测试用例结果:
	12456456
	345
	011
	Index_KMP:6
	*/
}


//生成匹配子串的next数组
void GetNext(HString H,int *next) {
	int i,j;

	i = 1;
	j = 0;

	next[1] = 0;

	while(i < H.length) {
		if(j == 0 || H.elem[i] == H.elem[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else 
			j = next[j];  //如果不相等则回溯
	}
}


int Index_KMP(HString H,HString T,int pos) {

	int i,j,k;
	int next[255];

	i = pos;
	j = 1;

	GetNext(T,next);
	//输出next数组
	for(k = 1; k <= T.length;k++) {
		printf("%d",next[k]);
	}
	printf("\n");
	
	while(i <= H.length  && j <= T.length) {
		if(j == 0 || H.elem[i-1] == T.elem[j-1]) {
			++i;
			++j;
		}
		else
			j = next[j];
	}

	if(j > T.length)
		return i - T.length;
	else 
		return 0;

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
* @return void
* @description:打印串
*/
void PrintStr(HString H) {
	int i;

	for(i = 0;i < H.length;i++) 
		printf("%c",H.elem[i]);
}



