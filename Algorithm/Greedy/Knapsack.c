/*----------------------------------------------------------------------------------------
	* FileName:Knapsack.c
	* author:doodlesomething@163.com
	* date:10-29-2014
	* version:1.0
	* description:用贪心算法解决背包问题（非0-1背包问题）
	* more:问题为有一个能容纳重量大小为weight的背包，现有n件物品，第i件物品的重量
		为w[i],价值为p[i],现求背包可容下的最大价值，注意物品可拆分
------------------------------------------------------------------------------------------*/

#include <stdio.h>

typedef struct {
	int w;	//表示重量
	int p;	//表示价值
}Packet;


/*
* @description:交换
*/

void swap(Packet P[],int i,int j) {
	Packet temp;
	temp = P[i];
	P[i] = P[j];
	P[j] = temp;
}

/*
* @description:根据单位重量的价值来排序,非降序
*/
void BubbleSort(Packet P[],int n) {
	int i,j,flag;

	flag = 1;

	for(i = 1; i < n && flag; i++)  {
		flag = 0;
		for(j = n - 1; j >= i ; j--) {
			if( (P[j].p / P[j].w) > (P[j - 1].p / P[j - 1].w) ) {
				swap(P,j,j - 1);
				flag = 1;
			}
		}
	}
}




/*
* @description:该算法应保证P已经是非降序
*/
void Knapsack(int weight,int n,Packet P[],float flag[]) {
	int i,count;
	
	count = 0;

	//初始化
	for(i = 0; i < n ; i++) {
		flag[i] = 0;
	}

	//装包,flag[i] == 1表示整件装入
	for(i = 0; i < n ; i++) {
		if(weight - count >= P[i].w) {
			flag[i] = 1;
			count += P[i].w;
		}
	}

	//有部分没有装入
	if(count < weight)  {
		--i;
		flag[i] = (weight - count) / (float) P[i].w;
	}
}



int main() {
	Packet P[20];
	int n,i,weight;
	float flag[20];

	//input 
	printf("please enter the n:");
	scanf("%d",&n);
	printf("please enter the weight:");
	scanf("%d",&weight);

	printf("please enter the weight and price of each things:\n");
	for(i = 0; i < n; i++) {
		scanf("%d%d",&P[i].w,&P[i].p);
	}

	
	//BubblueSort
	BubbleSort(P,n);

	//Knapscak
	Knapsack(weight,n,P,flag);

	//output
	for(i = 0 ; i < n ; i++) {
			printf("%d:%f\n",i,flag[i]);
	}
	
	return 0;
}



