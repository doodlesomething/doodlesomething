/*---------------------------------------------------------------------------------
	* FileName:Painter.c
	* author:doodlesomething@163.com
	* date:10-29-2014
	* version:1.0
	* description:Painter POJ-2709 solved by Greedy Algorithm
	* more:使用贪心算法解决即可,这里是选择最大的优先处理
-----------------------------------------------------------------------------------*/


#include <stdio.h>


#define N 20




void QuickSort(int arr[],int low,int high) {
	int first,last,key;
	
	if(low > high) {
		return;
	}

	first = low;
	last = high;
	key = arr[first];

	while(first < last) {
		//从后往前找第一个比key大的
		while(first < last && arr[last] <= key)
			last--;
		//移到低端
		arr[first] = arr[last];
		
		//从前往后找第一个比key小的
		while(first < last && arr[first] >= key)
			first++;
		//移到高端
		arr[last] = arr[first];
	}

	//记录枢纽位置
	arr[first] = key;

	QuickSort(arr,low,first - 1);
	QuickSort(arr,first + 1,high);

}


void swap(int arr[],int i,int j) {
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


void BubbleSort(int arr[],int n) {
	int i,j,flag;
	
	flag = 1;
	for(i = 0; i < n && flag; i++) {
		flag = 0;
		for(j = n - 1; j >= i; j--) {
			if(arr[j] > arr[j - 1]) {
				swap(arr,j,j - 1);
				flag = 1;
			}
		}
	}
}





int main() {
	
	int n,i,max,total,grey;
	int colors[N];

	max = 0;
	total = 0;
	
	//i输入
	printf("please enter n:");
	scanf("%d",&n);
	printf("please enter amount of different colors:");
	for(i = 0; i < n; i++) {
		scanf("%d,",&colors[i]);
		if(max < colors[i])
			max = colors[i];

	}

	printf("please enter the ammout of grey:");
	scanf("%d",&grey);
	

	//先算出除了灰色以外所需要的数目
	if(max % 50) {
		total = max / 50 + 1;
	}
	else {
		total = max / 50;
	}

	//算出剩余用来配置灰色的量
	for(i = 0; i < n ; i++) {
		colors[i] = total * 50 - colors[i];
	}
	
	//配置灰色
	while(grey > 0) { 
		//进行降序排序
		QuickSort(colors,0,n - 1);

		/*
		理解这里是关键,由于colors数组的降序的，选取三种颜色来配色
		则在这三种颜色中最先没有的肯定是第三种，注意这里是刚排完序
		则第三种之后的颜色必定没有第三中多，则需要另外新开一个,并
		更新各种颜色的剩余量
		*/
		if(colors[2] <= 0) {
			total++;
			for(i = 0; i < n; i++) {
				colors[i] += 50;
			}
		}

		//一毫升配置,相应减一
		colors[0]--;
		colors[1]--;
		colors[2]--;
		grey--;
	}
	
	printf("total:%d\n",total);

	return 0;
}


