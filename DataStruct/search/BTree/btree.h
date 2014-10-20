/*---------------------------------------------------------------------------------
	* FileName:btree.h
	* date:10-20-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:B树插入和查找
------------------------------------------------------------------------------------*/



#define TRUE 1
#define FALSE -1
#define OVERFLOW -2

#define m 3	//B树的阶数


typedef int Status;

//关键词类型
typedef int KeyType;


//B树节点结构
typedef struct BTNode {
	int keynum;	//树节点中关键词个数
	struct BTNode *parent;	//指向双亲节点
	//节点向量类型
	struct Node {
		KeyType key;	//关键词向量
		struct BTNode *ptr; //子树指向向量
		KeyType recptr;	//记录指针向量
	}node[m + 1];	//注意这里的0号单元中ptr有使用到，其他没有使用到
}*BTree;


//查找结果结构
typedef struct {
	struct BTNode *pt;	//指向找到的节点或是应该插入的位置
	int i;	//在节点中关键词的序号
	int tag;	//1代表成功，0代表查找失败
}Result;




//初始化树
Status InitBTree(BTree *T);


//在B树中查找
Result SearchBTree(BTree T,KeyType key);


//确定关键词在节点中位置或是应该插入的位置
int Search(BTree p,KeyType key);


//插入关键词
Status InsertBTree(BTree *T,KeyType key,BTree q,int i);

//生成新的根节点
void NewRoot(BTree *T,KeyType key,BTree ap);


//分裂节点做调整
void split(BTree *q,BTree *ap);


//插入关键词
void Insert(BTree *q,int i,KeyType key,BTree ap);

//遍历输出
void TraverseTree(BTree T,void (*Visit) (KeyType key));


//打印元素
void PrintElem(KeyType key);


