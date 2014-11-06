/*-----------------------------------------------------------------------------------
	* FileName:Cut_Rod.c
	* author:doodlesomething@163.com
	* version:1.0
	* date:11-5-2014
	* description:钢条切割 -->《算法导论》动态规划算法
	* more:包括递归算法，自顶向下，自底向上和自底向上的扩展算法
------------------------------------------------------------------------------------*/


#include <stdio.h>


/*
* @description:获取最大值
*/

int max(int x,int y) {
	return x > y ? x : y;
}

/*
* @description:钢条切割-->递归实现
* @param int p[]  价格表
* @param int n
*/
int cut(int p[],int n) {
	if(n == 0)
		return 0;

	int q = -1;
	int i;

	for(i = 1; i <= n; i++ )
		q = max(q,p[i] + cut(p,n - i));

	return q;
}



/*
* @description:自顶向下的备忘录法
* @param int p[] 价格表
* @param int n 切割长度
*/
int memoizedCutRodAux(int p[],int n,int r[]) {
	int i,q;

	if(r[n] >= 0)
		return r[n];
	
	if(n == 0)
		q = 0;
	else {
		q = -1;
		for(i = 1; i <= n; i++) {
			q = max(q,p[i] + memoizedCutRodAux(p,n - i,r));
		}
	}

	r[n] = q;

	return q;
}


/*
* @description:自顶向下
* @param int p[] 价格表
* @param int n 切割长度
*/
int memoizedCutRod(int p[],int n) {
	int r[n];
	int i;

	for(i = 0; i <= n ; i++)
		r[i] = -1;

	return memoizedCutRodAux(p,n,r);
}


/*
* @description:自底向上的求解
* @param int p[] 价格表
* @param int n 切割长度
*/
int Bottom_Up(int p[],int n) {
	int r[n];
	int i,j,q;

	r[0] = 0;

	for(i = 1; i <= n ; i++  ) {
		q = -1;
		for(j = 1; j <= i; j++) {
			q = max(q,p[j] + p[i - j]);
		}
		r[i] = q;
	}
	
	return r[n];
}



int main(void) {
	int p[] = {0,1,5,8,9,10,17,17,20,24,30};
	int n;

	printf("please enter the n:");
	scanf("%d",&n);


	int result = Bottom_Up(p,n);
	printf("total:%d\n",result);


	return 0;
}



/*
测试案例

Input:
4

OutPut:
10





Input:
7

OutPut:
18

*/


