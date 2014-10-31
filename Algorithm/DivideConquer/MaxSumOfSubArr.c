/*-----------------------------------------------------------------------------------
	* FileName:MaxSumOfSubArr.c
	* author:doodlesomething@163.com
	* date:10-31-2014
	* version:1.0
	* description:给一个有正有负的整数数组，求和最大的连续子数组
------------------------------------------------------------------------------------*/


#include <stdio.h>


#define N 8

int main(void) {
	int arr[N] = {-1,-2,3,10,-4,7,-2,-5};
	int currentSum,sum,i,start,end,pos;
	
	sum = -10000;	//实际上这个应该设置的足够小
	currentSum = 0;
	//用于记录开始结束位置
	start = end = pos = 0;
	
	for(i = 0; i < N; i++) {
		//如果当前的和为负则舍弃，currentSum设为下一个元素的值
		if(currentSum < 0) {
			currentSum = arr[i]; 
			pos = i;
		}
		else {
			currentSum += arr[i];
			
		}
		//更新最大值
		if(currentSum > sum) {
			sum = currentSum;
			start = pos;
			end = i;
		}
	}

	printf("sum:%d\t start:%d,end:%d\n",sum,start,end);

	return 0;
}



/*
output:
sum:16 start:2,end:5
*/


