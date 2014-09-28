/*-------------------------------------------------------------------------
	* file:hstring.h -->head file for HString 
	* date:28-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:串的链式存储操作基本集
--------------------------------------------------------------------------*/


#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef struct {
	char *elem;
	int length;
}HString;


typedef int Status;

//创建串
Status StrAssign(HString *H,char *str);

//串长
int StrLength(HString H);

//判空
Status StrEmpty(HString H);

//清空串
Status ClearString(HString *H);

//连接两串
Status StrConcat(HString *H,HString S,HString V);


//返回某位置起的子串
Status SubString(HString *Sub,HString T,int pos,int len);


//打印串
void PrintStr(HString H);



