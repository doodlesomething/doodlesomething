/*----------------------------------------------------------------------------------
	* FileName:Fibn.c
	* author:doodlesomething@163.com
	* date:1.0
	* version:1.0
	* description:Fib函数的非递归算法实现
----------------------------------------------------------------------------------------*/



#include <stdio.h>

/*
* @description:Fib函数的非递归算法的实现
*/

int Fibn(int n) {
	int total,i,last,NextToLast;

	if(n <= 1)
		return 1;
	
	last = NextToLast = 1;
	
	for(i = 2; i <= n ; i++) {
		total = last + NextToLast;
		NextToLast = last;
		last = total;
	}

	return total;
}


int main(void) {
	int result = Fibn(40);
	printf("%d\n",result);

	return 0;
}

/*
测试:
$ time ./Fibn
  165580141
  
  real 0m0.002s
  user 0m0.000s
  sys 0m0.004s
*/



