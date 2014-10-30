/*-------------------------------------------------------------------------------------
	* FileName:KMax.c
	* author:doodlesomething@163.com
	* date:10-31-2014
	* version:1.0
	* description:求第k最小值，要求时间复杂度接近O(n)
	* more:利用快排思想,利用分治思想
---------------------------------------------------------------------------------------*/

#include <stdio.h>

/*
*  description:分解
*/
int Paritation(int arr[],int low,int high) {
	int pivot;

	pivot = arr[low];

	while(low < high) {
		//从后往前找第一个比pivot小的值
		while(low < high && arr[high] >= pivot)
			high--;
		arr[low] = arr[high];

		//从前往后找到第一个比pivot大的值
		while(low < high && arr[low] <= pivot)
			low++;
		arr[high] = arr[low];
	}

	arr[low] = pivot;

	return low;
}




/*
* @description:找到第K小的值,这里进行非降序排序
* @more:
*/
int KMax(int arr[],int low,int high,int k) {
	int mid;

	if(low >= high) 
		return arr[low];
	else {
		mid = Paritation(arr,low,high);
		
		if(k < mid) 
			KMax(arr,low,mid - 1,k);
		else if(k > mid)
			KMax(arr,mid + 1,high,k);
		else
			return arr[mid];
	}
}



int main() {
	int arr[] = {1,3,6,2,5,8};
	
	printf("%d\n",KMax(arr,0,5,4));

	return 0;
}



