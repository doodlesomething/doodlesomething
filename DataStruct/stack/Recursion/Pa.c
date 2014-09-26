/*-------------------------------------------------------------------------
	* file:Pa.c
	* date:26-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:回文字符串的判断-->使用递归实现
	* 另外的思路：可以采用栈的方式实现，将前一半的字符入栈（若字符个数为奇数）
	* 则忽略该中间字符，之后剩下的字符顺序和栈顶元素比较，如果不相等
	* 则说明不是回文字符串
---------------------------------------------------------------------------*/


#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]) {
	int Pa(int low,int high,int length,char *str);
	int iseven(int n);
	int isodd(int n);
	char str[]="aabaa";
	int len;

	len = strlen(str);

	if(Pa(0,len-1,len,str)) {
		printf("this string is a Pa string\n");
	}
	printf("3:%d 4:%d\n",iseven(0),iseven(4));
}

int Pa(int low,int high,int length,char *str) {
	if(length == 0 || length == 1)
		return 1;
	
	if(str[low] != str[high])
		return 0;
	
	Pa(low+1,high-1,length-2,str);
}





//交互递归实现判断奇数还是偶数
int iseven(int n) {
	if(n == 0)
		return 1;
	else {
		return isodd(n-1);
	}
}


int isodd(int n) {
	return !(iseven(n));
}


