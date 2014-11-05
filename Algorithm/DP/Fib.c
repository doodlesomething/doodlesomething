/*--------------------------------------------------------------------------------------
	* FileName:Fib.c
	* author:doodlesomething@163.com
	* date:11-5-2014
	* version:1.0
	* description:Fib函数的递归算法实现
----------------------------------------------------------------------------------------*/



#include <stdio.h>
#include <time.h>


int Fib(int n)  {
	if(n <= 1)
		return 1;
	
	return Fib(n - 1) + Fib(n - 2);
}


int main(void) {

	int result = Fib(40);
	printf("%d\n",result);

	return 0;
}



/*
test:

	$ time ./Fib
	165580141

	real 0m1.948s
	user 0m1.944s
	sys 0m0.000s
*/



