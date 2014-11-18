/*------------------------------------------------------------------------------------
*
* Filename: witness.c
*
* Author: doodlesomething@163.com
*
* Description: 素性测试,有明显的bug
*
* Last modified: 2014-11-18 21:06
*
* Verson: 1.0
*
---------------------------------------------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef long int HugeInt;


/**
* @description	获取指定范围内的随机数
*
* @param	long int min
* @param	long int max
*
* @return	long int result	
*/
HugeInt Random(HugeInt min,HugeInt max) {
	HugeInt pos,dis,result;
	

	pos = min;
	dis = max - min + 1;
	if(dis <= 0)
		return ;
	result = rand() % dis + pos;

	return result;
}



/**
* @description	素性测试
*
* @param	HugeInt A
* @param	HugeInt i
* @param	HugeInt N
*
* @return	
*/
HugeInt witness(HugeInt A,HugeInt i,HugeInt N) {
	HugeInt X,Y;
	
	if (i < 0 || N <= 0)
		return ;

	if (i == 0)
		return 1;
	
	X = witness(A, i / 2, N);
	if (X == 0)
		return 0;
	
	Y = (X * X) % N;
	if (Y == 1 && X != 1 && X != N -1) 
		return 0;

	if(i % 2 != 0)
		Y = (A * Y) % N;
	
	return Y;
}


//是否为素数,费马小定理
int isPrime(HugeInt N) {
	return witness(Random(2,N -2),N -1 , N) == 1;
}



int main(void) {
	HugeInt i;
	srand((int) time(0));
	
	for(i = 1; i < 1000 ; i++)
		if (isPrime(i))
			printf("%ld\t",i);

	printf("\n");

	return 0;
}

