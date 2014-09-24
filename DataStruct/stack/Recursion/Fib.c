/*---------------------------------------------------------------------
	* file:Fib.c
	* date:24-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:斐波那契数列问题
----------------------------------------------------------------------*/


#include <stdio.h>


int main() {
	int Fib(int n);
	int i;

	for( i = 0; i < 40; i++) {
		printf("%d\t",Fib(i));
	}
}

//递归的力量-->..................
int Fib(int n) {
	if(n < 2)
		return n == 0 ? 0 : 1;
	return Fib(n-1) + Fib(n-2);
}
