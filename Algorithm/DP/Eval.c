/*--------------------------------------------------------------------------------------------
	* FileName:Eval.c
	* author:doodlesomething@163.com
	* date:1.0
	* version:1.0
	* description:递归算法计算数列
----------------------------------------------------------------------------------------------*/



#include <stdio.h>

/*
* @description:<<数据结构与算法分析>>p289数列问题的递归实现
*/

double Eval(int n) {
	int i;
	double sum;

	if(n == 0) {
		return 1.0;
	}
	else {
		sum = 0.0;
		for(i = 0; i < n; i++) {
			sum += Eval(i);
		}
		return  (2.0 * sum ) / n + n;
	}
	
}



int main(void) {
	
	double result = Eval(28);
	printf("%lf\n",result);

	return 0;
}

/*
root@~/code/Algorithm/DP$ time ./Eval
172.775920

real	0m3.117s
user	0m3.112s
sys	0m0.000s

*/

