/*-----------------------------------------------------------------------------------
	* FileName:sort.h
	* date:10-22-2014
	* author:doodlesomething@163.com
	* decription:排序
---------------------------------------------------------------------------------------*/



#define MAXSIZE 20
#define N 8
#define T 3
#define OVERFLOW -2

//关键词类型
typedef int KeyType;

typedef struct {
	KeyType key;
}ElemType;

typedef struct {
	ElemType r[MAXSIZE + 1];	//r[0]闲置或是用作哨兵
	int length;	//顺序表长度
}SqList;





