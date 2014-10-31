/*-------------------------------------------------------------------------------------
	* FileName:ChessBoard.c
	* author:doodlesomething@163.com
	* date:10-31-2014
	* version:1.0
	* description:棋盘覆盖问题
--------------------------------------------------------------------------------------*/


#include <stdio.h>

#define N 20

int board[N][N];



/*
* @description 棋盘覆盖
* @param int x 棋盘起始位置行
* @param int y 棋盘起始列
* @param int posx 特殊格子行
* @param int posy 特殊格子列
* @param int size 棋盘大小
*/


int pos = 1;

void ChessBoard(int x,int y,int posx,int posy,int size) {
	int s,t;

	if(size == 1)
		return ;
	s = size / 2;
	t = pos++;

	//特殊格子在左上角区域
	if(posx < x + s && posy < y + s) {
		ChessBoard(x,y,posx,posy,s);
	}
	//不在
	else {
		board[x + s - 1][y + s - 1] = t;
		ChessBoard(x,y,x + s - 1,y + s - 1,s);
	}

	//右上角
	if( posx < x + s && posy >= y + s) {
		ChessBoard(x,y + s,posx,posy,s);
	}
	else {
		board[x + s - 1][y + s] = t;
		ChessBoard(x,y + s,x + s - 1,y + s,s);
	}

	//左下角
	if( posx >= x + s && posy < y + s) {
		ChessBoard(x + s,y,posx,posy,s);
	}
	else {
		board[x + s][y + s - 1] = t;
		ChessBoard(x + s,y,x + s,y + s -1,s);
	}

	//右下角
	if(posx >= x + s && posy >= y + s) {
		ChessBoard(x + s,y + s,posx,posy,s);
	}
	else {
		board[x + s][y + s] = t;
		ChessBoard(x + s, y + s, x + s, y + s, s);
	}

}



int main(void) {
	int size,posx,posy,i,j;

	printf("please enter size,posx and posy:");
	scanf("%d,%d,%d",&size,&posx,&posy);
	ChessBoard(1,1,posx,posy,size);

	for(i = 1 ; i <= size; i++) {
		for(j = 1; j <= size; j++) {
			printf("%d\t",board[i][j]);
		}
		printf("\n");
	}

	return 0;
}



