
/*---------------------------------------------------------------------------
	* file:str.h -->head file for SString.c
	* date:28-9-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:串的基本操作 --->使用定长顺序实现
------------------------------------------------------------------------------*/



#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0

#define MAXSIZE 254

typedef unsigned char SString[MAXSIZE+1];
typedef int Status;



/*
* @description:产生一个字符串 注意数组的第一个元素为字符串长度
*/
Status StrAssign(SString *S,char *str);



/*
* @description:求串长
*/
int StrLength(SString S);



/*
* @description:判空
*/
Status StrEmpty(SString S);



/*
* @description:比较两字符串
*/
Status StrCompare(SString S,SString T);


/*
* @description:由串S复制得串T
*/
Status StrCopy(SString S,SString *T);



/*
* @description:用T返回S1,S2连接的串
*/
Status StrConcat(SString *T,SString S1,SString S2);



/*
* @description:用串Sub返回串S从第pos位置开始的长度为len的字串
*/
Status SubString(SString *Sub,SString S,int pos,int len);



/*
* @description:判断在串S在的pos的元素是否存在和串T相同的字符，如果存在则返回他的位置，否则返回0
*/

int StrIndex(SString S,SString T,int pos);



/*
* @description:在串S的第pos个元素之前,插入串T
*/
Status StrInsert(SString *S,int pos,SString T);




/*
* @description:删除第pos起长度为len的子串
*/
Status DeleStr(SString *S,int pos,int len);



/*
* @description:替换S中所有与T相等不重叠的子串为V
*/
Status StrReplace(SString *S,SString T,SString V);



/*
* @description:清除串S
*/
void ClearStr(SString *S);



/*
* @description:销毁串S
*/
void DestoryStr(SString *S);

/*
* @description:打印串
*/
void StrPrint(SString S);
