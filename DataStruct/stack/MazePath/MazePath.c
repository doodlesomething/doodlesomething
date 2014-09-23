/*-------------------------------------------------------------------
	* file:MazePath.c
	* date:23-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:迷宫问题求解
--------------------------------------------------------------------*/




#include <stdlib.h>
#include "mazepath.h"


/*
* @description:初始化栈
*/

Status InitStack(SqStack *S) {
	
	(*S).base = (SElemType *) malloc(INTSIZE * sizeof(SElemType));
	if(!(*S).base)
		exit(OVERFLOW);
	(*S).top = (*S).base;
	(*S).stacksize = INTSIZE;

	return OK;
}

/*
* @description:判空
*/
Status StackEmpty(SqStack S) {
	return S.base == S.top ? TRUE : FALSE;
}


/*
* @description:栈长
*/
int StackLength(SqStack S) {
	return S.top - S.base;	
}

/*
* @description:进栈
*/
Status Push(SqStack *S,SElemType elem) {
	if((*S).top - (*S).base > (*S).stacksize ) {
		(*S).base =(SElemType *) realloc((*S).base,((*S).stacksize+INCREMENT_SIZE)*sizeof(SElemType));
		if(!(*S).base)
			exit(OVERFLOW);
		else {
			(*S).top = (*S).base + (*S).stacksize;
			(*S).stacksize += INCREMENT_SIZE;
		}
	}

	*(*S).top = elem;
	(*S).top++;

	return OK;
}

/*
* @description:出栈
*/
Status Pop(SqStack *S,SElemType *elem) {
	if((*S).base == (*S).top)
		return ERROR;

	(*S).top--;
	(*elem) = *(*S).top;

	return OK;
}

/*
* @description:获取栈顶元素（不弹出）
*/
Status GetTop(SqStack S,SElemType *elem) {
	if(S.base == S.top )
		return ERROR;
	
	(*elem) = * (S.top - 1);

	return OK;
}

/*
* @description:遍历所有栈元素
*/
void StackTraverse(SqStack S,void (*visit) (SElemType)) {
	while(S.base != S.top ) {
		S.top--;
		visit(*S.top);
	}
}

/*
* @description 打印栈元素
*/
void visit(SElemType elem) {
	printf("%d\t",elem);
}

/*
* @description 清空栈
*/
void ClearStack(SqStack *S) {
	while((*S).base != (*S).top ) 
		(*S).top--;

	(*S).stacksize = 0;
}

/*
* @description 销毁栈
*/
void DestoryStack(SqStack *S) {
	ClearStack(S);

	(*S).top = (*S).base = NULL;
}



/*
* @description:初始化迷宫
*/
Status InitMaze(MazeType *M) {
	int i,j;

	char mz[ROW][COLUMN] = {
		'#',' ','#','#','#','#','#','#','#','#',  
		'#',' ',' ','#',' ',' ',' ','#',' ','#',  
		'#',' ',' ','#',' ',' ',' ','#',' ','#',  
		'#',' ',' ',' ',' ','#','#',' ',' ','#',  
		'#',' ','#','#','#',' ',' ',' ',' ','#',  
		'#',' ',' ',' ','#',' ','#',' ','#','#',  
		'#',' ','#',' ',' ',' ','#',' ',' ','#',  
		'#',' ','#','#','#',' ','#','#',' ','#',  
		'#','#',' ',' ',' ',' ',' ',' ',' ',' ',  
		'#','#','#','#','#','#','#','#','#','#'  
	};

	M->maze = (char **) malloc(sizeof(char *) * ROW);
	M->footprints = (int **) malloc(sizeof(int *) * ROW);

	if(!M->maze || !M->footprints) 
		exit(OVERFLOW);
	
	for(i = 0; i < ROW ; i++ ) {
		M->maze[i] = (char *) malloc(sizeof(char) * COLUMN);
		M->footprints[i] = (int *) malloc(sizeof(int) * COLUMN);

		if(!M->maze[i] || !M->footprints[i])	
			exit(OVERFLOW);
	}

	for(i = 0; i < ROW;i++) {
		for(j = 0; j < COLUMN; j++){
			M->maze[i][j] = mz[i][j];
			M->footprints[i][j] = 0;
		}
	}

	M->row = ROW;
	M->column = COLUMN;

	return OK;
}


/*
* @description:打印迷宫
*/
void PrintMaze(MazeType *M) {
	int i,j;

	for(i = 0; i < M->row; i++) {
		for(j = 0; j < M->column; j++) {
			printf("%c",M->maze[i][j]);
		}
		printf("\n");
	}
}


/*
* @description:求解迷宫路径
*/
Status MazePath(MazeType maze,SqStack *S,PosType start,PosType end) {
	PosType curpos;
	int curstep;
	SElemType elem;

	InitStack(S);
	curpos = start;
	curstep = 1;
		
	do {
		if(Pass(&maze,curpos)) {
			FootPrint(&maze,curpos);
			elem = SetElem(curpos,curstep,1);
			Push(S,elem);
			if(curpos.x == end.x && curpos.y == end.y )
				return TRUE;
			curpos = NextPos(curpos,1);
			curstep++;
		}
		else {
			if(!StackEmpty(*S)) {
				Pop(S,&elem);
				//这种情况是：东南西已经
				while(elem.di == 4 && !StackEmpty(*S)) {
					MarkPrint(&maze,elem.seat);  //此路不通，做标记
					Pop(S,&elem);
				}

				if(elem.di < 4) {
					//按东南西北的方向调整探测
					elem.di++;
					Push(S,elem);
					curpos = NextPos(elem.seat,elem.di);
				}
			}
		}
	}while(!StackEmpty(*S));
	
	return FALSE;
}

//标记走不通的点
Status MarkPrint(MazeType *M,PosType pos) {
	if(pos.x > M->row || pos.y > M->column )
		return ERROR;

	M->footprints[pos.x][pos.y] = 1;

	return OK;
}

//标记已经走过的点
Status FootPrint(MazeType *M,PosType pos) {
	if(pos.x > M->row || pos.y > M->column )
		return ERROR;
	
	M->footprints[pos.x][pos.y] = 1;

	return OK;
}

//获取下一个探测点
PosType NextPos(PosType curpos,int di) {
	//1,2,3,4 分别代表东南西北

	switch(di) {
		case 1:
			curpos.x++;
			break;
		case 2:
			curpos.y++;
			break;
		case 3:
			curpos.x--;
			break;
		case 4:
			curpos.y--;
		default:
			break;
	}

	return curpos;
}

//组装一个栈元素以便进栈
SElemType SetElem(PosType curpos,int curstep,int di) {
	SElemType elem;
	
	elem.ord = curstep;
	elem.seat = curpos;
	elem.di = di;

	return elem;
}

/*
* @descrption:当前位置是否可以通过
*/
Status Pass(MazeType *M,PosType pos) {
	if(pos.x > M->row || pos.y > M->column)
		return ERROR;
	
	if(M->footprints[pos.x][pos.y] == 0 && M->maze[pos.x][pos.y] == ' ')
		return TRUE;
	else
		return FALSE;
}

//打印结果
void PrintFoot(SqStack S,MazeType *M) {
	int i,j;
	SElemType *p;

	for(i = 0; i < M->row ; i++) {
		for(j = 0; j < M->column ; j++) {
			M->footprints[i][j] = 0;
		}
	}

	p = S.top;

	while(p != S.base) {
		M->footprints[p->seat.x][p->seat.y] = 1;
		*p--;
	}

	for(i = 0; i < M->row ; i++) {
		for(j = 0; j < M->column; j++) {
			printf("%d",M->footprints[i][j]);
		}
		printf("\n");
	}
}
