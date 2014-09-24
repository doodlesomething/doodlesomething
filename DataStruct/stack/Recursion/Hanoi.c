/*---------------------------------------------------------------------------
	* file:Hanoi.c
	* date:24-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:汉诺塔问题-->递归
------------------------------------------------------------------------------*/


#include <stdio.h>


int main() {
	int count,n;

	count = 0;



	void move(char x,char z,int n) {
		count++;
		printf("Move %d from %c to %c\n",n,x,z);
	}

	void Hanoi(int n,char x,char y,char z) {
		if(n == 1)
			move(x,z,1);
		else {
			Hanoi(n-1,x,z,y);
			move(x,z,n);
			Hanoi(n-1,y,x,z);
		}
	}


	printf("please enter the n:");
	scanf("%d",&n);
	Hanoi(n,'x','y','z');
	printf("\ntotal Move:%d\n",count);
}
