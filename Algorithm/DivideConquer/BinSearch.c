/*-----------------------------------------------------------------------------------
	* FileName:BinSearch.c
	* author:doodlesomething@163.com
	* version:1.0
	* date:10-30-2014
	* description:BinSearch solved by Divide and Conquer Algorithm
-------------------------------------------------------------------------------------*/


#include <stdio.h>


/*
* @description:使用分治思想实现二分查找
*/

int BinSearch(int arr[],int low,int high,int key) {
	int mid;

	if(low > high) {
		return -1;
	}
	else {
		mid = (low + high) / 2;
		if(arr[mid] == key) {
			return mid;
		}
		else if(arr[mid] > key) {
			return BinSearch(arr,low,mid - 1,key);
		}
		else {
			return BinSearch(arr,mid + 1,high,key);
		}
	}

}


int main() {
	int arr[] = {1,5,9,2,8};
	int index;

	index = BinSearch(arr,0,4,9);

	printf("%d\n",index);

	return 0;
}



