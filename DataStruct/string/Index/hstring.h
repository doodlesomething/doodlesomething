/*-------------------------------------------------------------------------
	* file:hstring.h -->head file for HString 
	* date:28-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:串的链式存储操作基本集
--------------------------------------------------------------------------*/

#include "comman.h"



//初始化串
Status InitStr(HString *H);

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

//比较两串
Status StrCompare(HString H,HString T);

//返回某位置起的子串
Status SubString(HString *Sub,HString T,int pos,int len);

//复制
Status StrCopy(HString *T,HString H);

//打印串
void PrintStr(HString H);


