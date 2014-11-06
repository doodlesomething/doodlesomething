/*-----------------------------------------------------------------------------------------
	* FileName:LCS.c
	* author:doodlesomething@163.com
	* version:1.0
	* date:11-5-2014
	* description:最长公共子序列(注意不是子串)
----------------------------------------------------------------------------------------------*/

#include <stdio.h>


int count[20][20];
int b[20][20];

/*
* @description:求最长公共子序列的长度
* @param char x[] 串x
* @param char y[] 串y
* @param int xlen 串x的长度
* @param int ylen 串y的长度
*/

int LCS_Length(char x[],char y[],int xlen,int ylen) {
	int i,j;

	//init
	for(i = 1; i <= xlen ; i++) 
		count[i][0] = 0;
	
	for(j = 1; j <= ylen; j++)
		count[0][j] = 0;
	
	for(i = 1; i <= xlen; i++) {
		for(j = 1; j <= ylen; j++) {
			if(x[i] == y[j]) {
				count[i][j] = count[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if(count[i - 1][j] >= count[i][j - 1]) {
				count[i][j] = count[i - 1][j];
				b[i][j] = 2;
			}
			else {
				count[i][j] = count[i][j - 1];
				b[i][j] = 3;
			}
		}
	}

	return count[xlen][ylen];
}



/*
* @description:打印最长公共子序列
* @param char x[] 可传入任意一个串
* @param int xlen x长度
* @param int ylen y长度
*/

void Print_LCS(char x[],int xlen,int ylen) {

	if(xlen == 0 || ylen ==0)
		return ;
	
	if(b[xlen][ylen] == 1)  {
		Print_LCS(x,xlen - 1,ylen - 1);
		printf("%c\t",x[xlen]);
	}
	else if(b[xlen][ylen] == 2) 
		Print_LCS(x,xlen - 1,ylen);
	else
		Print_LCS(x,xlen,ylen - 1);

}



int main(void) {
	char x[8] = {' ','A','B','C','B','D','A','B'};
	char y[7] = {' ','B','D','C','A','B','A'};
	int i,j;

	int len = LCS_Length(x,y,7,6);

	printf("length:%d\n",len);
	
	//输出矩阵
	for(i = 0; i <= 7; i++) {
		for(j = 0; j <= 6; j++)
			printf(" %d",count[i][j]);
		printf("\n");
	}

	Print_LCS(x,7,6);
	printf("\n");

	return 0;
}




/*
Output:
length:4
 0 0 0 0 0 0 0
 0 0 0 0 1 1 1
 0 1 1 1 1 2 2
 0 1 1 2 2 2 2
 0 1 1 2 2 3 3
 0 1 2 2 2 3 3
 0 1 2 2 3 3 4
 0 1 2 2 3 4 4
B	C	B	A	
*/


