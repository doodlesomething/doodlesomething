/*-------------------------------------------------------------------------------
	* FileName:RadixSort.c
	* date:10-23-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:基数排序-->程序部分摘自维基百科，做了一些修改,注释是我加的
----------------------------------------------------------------------------------*/

#include <stdio.h>

#define MAX 20
#define BASE 10



/*
* @description:输出数组
*/
void print(int *a, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
}


/*
* @description:基数排序
* @more:这里采用最高位优先，并没有采用递归的思想
*/
void RadixSort(int *a, int n) {
	int i,m,exp;
	int b[MAX];

	m = a[0];
	exp = 1;

	//找到最大值
	for (i = 1; i < n; i++) {
		if (a[i] > m) {
			m = a[i];
		}
	}
	/*
	为什么要找到最大值呢？因为可能会出现 1 和 999这样的两个数字，必须以
	最大的数字为基准来进行基数的收集和分配结束条件
	*/
	while (m / exp > 0) {
		//初始化
		int bucket[BASE] = { 0 };
		//统计出当前相同字码的个数，比如21和31则现在有两个个位数为1的数
		for (i = 0; i < n; i++) {
			bucket[(a[i] / exp) % BASE]++;
		}
		
		/*
		统计出每个字码的数组边界，比如个位数为0有1，个位数为1的有两个
		则个位数为1的在数组中的存储边界为3即1-2
		*/
		for (i = 1; i < BASE; i++) {
			bucket[i] += bucket[i - 1];
		}
		
		//分配,注意这里从后面扫描仅仅是为了保证排序的稳定性
		for (i = n - 1; i >= 0; i--) {
			b[--bucket[(a[i] / exp) % BASE]] = a[i];
		}

		//收集
		for (i = 0; i < n; i++) {
			a[i] = b[i];
		}

		//进行下一位数的收集和分配
		exp *= BASE;

	}
}



int main() {
	int arr[] = {27,28,12,49,78,3,54};
	int i;

	printf("排序前: ");
	print(arr, 7);
	//排序
	RadixSort(arr, 7);

	printf("\n排序后: ");
	print(arr, 7);
	printf("\n");

	return 0;
}

