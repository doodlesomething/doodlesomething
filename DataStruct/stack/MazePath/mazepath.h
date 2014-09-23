/*-------------------------------------------------------------------
	* file:mazepath.h -->the head file for MazePath.c
	* date:23-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:迷宫问题求解
--------------------------------------------------------------------*/

#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
#define OVERFLOW -2

#define INTSIZE 50  //栈的初始化空间
#define INCREMENT_SIZE 10  //每次分配内存空间的增长量

#define ROW 10
#define COLUMN 10

typedef int Status;

typedef struct {
	char **maze; //相当指针数组，用于记录迷宫
	int **footprints; //用于记录足迹的
	int row;
	int column;
}MazeType;

typedef struct {
	int x;
	int y;
}PosType;

typedef struct {
	int ord;	//
	PosType seat;	//坐标位置
	int di;		//下一点的方向
}SElemType;


typedef struct {
	SElemType *top;  //栈顶指针	
	SElemType *base;  //栈底指针
	int stacksize;   //栈的大小
}SqStack;


//初始化栈
Status InitStack(SqStack *S);

//判断栈是否空
Status StackEmpty(SqStack S);

//获取栈长
int StackLength(SqStack S);

//进栈
Status Push(SqStack *S,SElemType elem);

//出栈
Status Pop(SqStack *S,SElemType *elem);

//获取栈顶元素(不弹出)
Status GetTop(SqStack S,SElemType *elem);

//遍历所有元素
void StackTraverse(SqStack S,void (*visit) (SElemType));

//打印栈元素
void visit(SElemType elem);

//清空栈
void ClearStack(SqStack *S);

//销毁栈
void DestoryStack(SqStack *S);

//初始化迷宫
Status InitMaze(MazeType *M);

//打印迷宫
void PrintMaze(MazeType *M);


//求迷宫路径,有解则返回TRUE，无解返回FALSE
Status MazePath(MazeType maze,SqStack *S,PosType start,PosType end);

//标记走不通的点
Status MarkPrint(MazeType *M,PosType pos);

//标记已经走过的点
Status FootPrint(MazeType *M,PosType pos);

//获取下一个探测点
PosType NextPos(PosType curpos,int di);

//组装一个节点方便入栈
SElemType SetElem(PosType curpos,int curstep,int di);

//判断该当前位置是否可通过
Status Pass(MazeType *M,PosType pos);

//打印结果
void PrintFoot(SqStack S,MazeType *M);
