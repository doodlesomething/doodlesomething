/*--------------------------------------------------------------------------------------
	* FileName:HashTable.c
	* date:10-21-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:哈希表的建立/重建/查找
	* more:冲突处理采用开放地址法:Hi = (H(key) + di) mod m 
----------------------------------------------------------------------------------------*/


#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
#define OVERFLOW -2

//元素初始值
#define NULLKEY 655


typedef int Status;


//关键词类型
typedef int KeyType;

typedef struct {
	KeyType key;
}ElemType;


typedef struct {
	ElemType *elem;		//数据元素基址
	int count;	//当前元素个数
	int sizeindex;	//当前哈希表容量
}HashTable;




//初始化哈希表
Status InitHTable(HashTable *H);


//在哈希表中查找
Status SearchHash(HashTable H,KeyType key,int *p,int *c);


//求哈希值
unsigned Hash(KeyType key);


//冲突处理函数
void collision(int *p,int c);


//在哈希表中插入
Status InsertHash(HashTable *H,KeyType key);


//重建哈希表
void RecreateHash(HashTable *H);


//遍历输出
void TraverseHTable(HashTable H,void (*Visit) (KeyType));

//打印元素
void PrintElem(KeyType key);



