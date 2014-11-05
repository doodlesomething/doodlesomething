/*----------------------------------------------------------------------------------------
	* FileName:EvalD.c
	* author:doodlesomething@163.com
	* date:11-5-2014
	* version:1.0
	* description:<<数据结构与算法分析>>p289数列问题 -->修改EvalD.c使时间复杂度为O(N)
------------------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>


double EvalD(int n) {
	int i;
	double sum,result;
	double *p;
	//存储N个故需要申请n + 1个数组空间
	p =  malloc(sizeof(double) * (n + 1));
	if(p == NULL)
		exit(-2);

	p[0] = 1.0;

	sum = 0.0;
	for(i = 1; i <= n; i++) {
		sum += p[i - 1];
		p[i] = (2.0 * sum) / i + i;
	}
	
	result = p[n];
	free(p);

	return result;
}


int main(void) {
	double result = EvalD(1000000);
	printf("%lf\n",result);
	return 0;
}

/*
test:
root@~/code/Algorithm/DP$ time ./EvalD 
172.775920

real	0m0.002s
user	0m0.000s
sys	0m0.000s

*/
