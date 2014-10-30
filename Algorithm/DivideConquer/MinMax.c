/*----------------------------------------------------------------------------------
	* FileName:MinMax.c
	* author:doodlesomething@163.com
	* date:10-30-2014
	* version:1.0
	* description:在n个数中找到同时找到最小最大值
-----------------------------------------------------------------------------------*/


#include <stdio.h>


/*
* @description:返回最小值
*/
int GetMin(int i,int j) {
	return i > j ? j : i;
}

/*
* @description:返回最大值
*/
int GetMax(int i,int j) {
	return i > j ? i : j;
}


/*
* @description:分治算法实现在2的n次幂个数中查找最大最小值
*/
void MinMax(int arr[],int low,int high,int *min,int *max) {
	int mid,min1,max1,min2,max2;

	if(high - low == 1)  {
		*min = arr[low] > arr[high] ? arr[high] : arr[low];
		*max = arr[low] > arr[high] ? arr[low] : arr[high];
	}
	else {
		mid = (low + high) / 2;
		MinMax(arr,low,mid,&min1,&max1);
		MinMax(arr,mid + 1,high,&min2,&max2);
		
		*min = GetMin(min1,min2);
		*max = GetMax(max1,max2);
	}
}


int main() {
	int arr[] = {2,34,1,6,9,7,3,56};
	int min,max;
	
	MinMax(arr,0,7,&min,&max);

	printf("%d %d\n",min,max);

}



