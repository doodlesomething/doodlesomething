/*--------------------------------------------------------------------------------------
	* FileName:Touc.c
	* author:doodlesomething@163.com
	* date:10-31-2014
	* version:1.0
	* description:循环赛
	* more:
	设有n=2k个选手参加比赛，要求设计一个满足一下要求的比赛日程表:

	（1）每个选手必须与其他的n-1个选手个比赛一次；

	（2）每个选手每天只能赛一次 。
---------------------------------------------------------------------------------------*/



#include <stdio.h>
#include <math.h>

#define N 100

int arr[N][N];

/*
* @description:对称复制
*/
void copy(int n) {
	int k,i,j;

	k = n / 2;

	for(i = 1; i <= k; i++) {
		for(j = 1; j <= k; j++) {
			arr[i][j + k] = arr[i][j] + k;
			arr[i + k][j] = arr[i][j] + k;
			arr[i + k][j + k] = arr[i][j];
		}
	}
}

/*
* @description:循环赛时间表，分治思想
*/
void Tour(int n) {
	if(n == 1) {
		arr[1][1] = 1;
		return;
	}
	else {
		Tour(n / 2);
		copy(n);
	}
}



int main(void) {
	int n,i,j,total;

	printf("please enter n:");
	scanf("%d",&n);
	total = pow(2,n);
	
	Tour(total);

	printf("TimeTable:\n");
	for(i = 1; i <= total; i++) {
		for(j = 1; j <= total; j++) {
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

