/*---------------------------------------------------------------------------
	* FileName:MergeSort.c
	* author:doodlesomething@163.com
	* version:1.0
	* date:10-30-2014
	* description:MergeSort solved by Divide and Conquer Algorithm
----------------------------------------------------------------------------*/

#include <stdio.h>


/*
* @description:归并
*/

void Merge(int arr[],int low,int mid,int high) {
	int i,j,k;
	int temp[100];
	
	for(j = mid + 1,i = low , k = 0; j <= high && i <= mid ; k++) {
		if(arr[i] < arr[j]) {
			temp[k] = arr[i++];
		}
		else {
			temp[k] = arr[j++];
		}
	}

	while(i <= mid) {
		temp[k++] = arr[i++];
	}

	while(j <= high) {
		temp[k++] = arr[j++];
	}

	for(i = low,j = 0; i <= high; j++,i++) {
		arr[i] = temp[j];
	}
}



/*
* @description:归并排序
*/
void MergeSort(int arr[],int low,int high) {
	int mid;

	if(low < high) {
		//分解
		mid = (low + high) / 2;
		//进行分解部分的排序
		MergeSort(arr,low,mid);
		MergeSort(arr,mid + 1,high);
		//合并
		Merge(arr,low,mid,high);
	}
}



int main() {
	int arr[] = {1,5,7,2,4,3,9};
	int i;

	MergeSort(arr,0,6);

	for(i = 0; i < 7; i++) {
		printf("%d\t",arr[i]);
	}
	printf("\n");

	return 0;
}

