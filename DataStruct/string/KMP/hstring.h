/*-------------------------------------------------------------------------
	* file:hstring.h -->head file for HString 
	* date:28-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:KMP模式匹配算法实现
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

//生成匹配子串的next数组
void GetNext(HString H,int *next);

//KMP模式匹配算法描述实现
int Index_KMP(HString H,HString T,int pos);

//创建串
Status StrAssign(HString *H,char *str);


//打印串
void PrintStr(HString H);

