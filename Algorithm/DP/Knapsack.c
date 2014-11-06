/*---------------------------------------------------------------------------------------
	* FileName:Knapsack.c
	* author:doodlesomething@163.com
	* date:1-5-2014
	* version:1.0
	* description:0-1背包问题
-------------------------------------------------------------------------------------------*/

#include <stdio.h>


int count[5][20];


int max(int a,int b) {
	return a > b ? a : b;
}


/*
* @description:0-1背包问题
* @param int weight[] 各个物品的重量
* @param int price[] 各个物品的价格
* @param int cap  背包容量 
* @param int n 总的物品数量
*/

int Knapsack(int weight[],int price[],int cap,int n) {
	int i,j;

	//01背包问题，初始化
	for(i = 0; i < 5; i++) 
		for(j = 0; j < 20; j++)
			count[i][j] = 0;
	
	for(i = 1; i <= n ; i++) {
		for(j = 1; j <= cap; j++) {
			if(weight[i] > j) 
				count[i][j] = count[i - 1][j];
			else 
				count[i][j] = max(count[i - 1][j], count[i - 1][j - weight[i]] + price[i]);
		}
	}

	return count[n][cap];
}



int main(void) {
	int i,j;
	int weight[] = {0,3,4,7,8,9};
	int price[] = {0,4,5,10,11,13};
	
	int result = Knapsack(weight,price,20,5);


	printf("total:%d\n",result);

	return 0;
}
