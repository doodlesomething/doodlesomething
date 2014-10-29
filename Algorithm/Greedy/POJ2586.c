/*-------------------------------------------------------------------------------------------
	* FileName:POJ2586.c
	* author:doodlesomething@163.com
	* date:10-29-2014
	* version:1.0
	* description:POJ-2586 solved by Greedy Algorithm
---------------------------------------------------------------------------------------------*/


#include <stdio.h>

int main() {
	int s,d,total;

	printf("please enter the s and d:");
	scanf("%d %d",&s,&d);


	if(4 *s < d)
		total = 10 * s - 2 * d;
	else if(3* s < 2 * d)
		total = 8 * s - 4 * d;
	else if( 2 * s < 3 * d)
		total = 6 * s - 6 * d;
	else if(s < 4 * d)
		total = 3 * s - 9 * d;
	else
		total = - 12 * d;

	if(total > 0)
		printf("total:%d\n",total);
	else
		printf("dir\n");
}
