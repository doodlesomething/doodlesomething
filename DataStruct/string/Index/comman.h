/*
* author:doodlesomething@163.com
* file:comman.h
* description:define some comman value
*/

#ifndef COM
#define COM comman.h

#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


#define MaxBookNum  1000 //最大书籍量
#define MaxLineLen 400  //每个书目串的最大长度
#define MaxWordNum 20  //每个书目串对应的此表的最大长度
#define MaxWordLen 20 //每个单词最大长度
#define MaxKeyNum 1000  //索引表所能容纳的最大长度书目
#define DataLen 3 //书号的长度一定，不足则补零



typedef int Status;

typedef int ElemType;


typedef struct {
	char *elem;
	int length;
}HString;


typedef struct LNode  {  
	ElemType    data[DataLen];  
	struct LNode    *next;  
}LNode, *Link, *Position;;  

typedef struct {  
	Link    head, tail;  
	int     len;  
}LinkList;  

//存放每个书目串的所有单词的结构体
typedef struct {
	char *item[MaxWordNum];	//一维指针  二维数组
	int len;	//单词表的长度
}WordListType;

//索引项结构体
typedef struct {
	HString key;	//每个索引项的关键词
	LinkList bnolist;  //每个关键词所对应的书号
}IdxItemType;

typedef struct {
	IdxItemType item[MaxKeyNum + 1];
	int len;
}IdxListType;


#endif
