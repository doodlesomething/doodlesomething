/*-------------------------------------------------------------------------------
	* file:Queens.c
	* date:10-7-2014
	* author:doodlesomething@163.com
	* vesion:1.0
	* description:皇后问题实现
	*more:
	显然，每一行可以而且必须放一个皇后，所以n皇后问题的解可以用一个n元向量X=
	（x1,x2,.....xn）表示，	其中，1≤ i≤ n且1≤ xi≤ n，即第n个皇后放在第i行第xi列上。
	由于两个皇后不能放在同一列上，所以，解向量X必须满足的约束条件为:xi≠ xj;

	若两个皇后的摆放位置分别是（i,xi）和（j,xj），在棋盘上斜率为-1的斜线上，
	满足条件i-j=xi-xj;在棋盘上斜率为1的斜线上，满足条件i+j=xi+xj;

	综合两种情况，由于两个皇后不能位于同一斜线上，所以，

	解向量X必须满足的约束条件为:|i-xi|≠ |j-xj|
--------------------------------------------------------------------------------*/


#include <stdio.h>
#include <math.h>

#define N 8	

int main(int argc,char *argv[]) {
	void Trial(int i,int n,int arr[],int *count);
	int isOk(int i,int arr[]);
	int count;
	count = 0;

	int ChessBoard[N] = {0};
	Trial(1,N,ChessBoard,&count);

	printf("\n一共有count:%d种解法\n",count);

	return 0;
}


/*
进入本函数时，在n*n棋盘前i-1行已经放置了合法的i-1哥棋子
现在从底i行起继续为后继棋子选择合适的位置
*/
void Trial(int i,int n,int arr[],int *count) {
	int j;
	void PrintBoard(int arr[],int n);

	//说明布局结束且合法，进行输出
	if(i > n) {
		PrintBoard(arr,n);
		(*count)++;
	}
	else {
		for(j = 1;j <= n; ++j) {
			//在第i行j列放置一个皇后
			arr[i] = j;
			//如果布局合法则进行一个棋子的布局
			if(isOk(i,arr))
				Trial(i + 1,n,arr,count);
			//否则进行回溯
			else
				arr[i] = 0;
		}
	}
}

void PrintBoard(int arr[],int n) {
	int j;
	//输出形式为：从第1行第一列起arr[j]，为之后的所在行的第arr[j]列
	for(j = 1;j <= n; j++ ) 
		printf("%d",arr[j]);
	printf("\n");
}

/*
* @description:判断当前棋子和前面的所有已经布局的棋子是否构成合法的棋局
*/
int isOk(int i,int arr[]) {
	int k;
	for( k = i - 1;k >= 1; k--) 
		if(arr[k] == arr[i] || abs(arr[k] - arr[i]) == abs(i - k))
			return 0;
	
	return 1;
}
