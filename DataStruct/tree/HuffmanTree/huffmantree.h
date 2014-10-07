/*------------------------------------------------------------
	* file:huffmantree.h -->head file for HuffmanTree.c
	* date:10-6-2014
	* author:doodlesomething@163.com
	* version:1.0
	* description:赫夫曼编码
--------------------------------------------------------------*/


typedef struct HTNode{
	unsigned int weight;
	unsigned int parent,lchild,rchild;

}*HuffmanTree;

typedef char **HuffmanCode;

#define LIMIT_MAX 256	//规定权值不能超过256(纯属个人喜好)




//在i个节点中找到权值最小的
int min(HuffmanTree *HT,int i);

//在i个节点中找到两个最小的
void Select(HuffmanTree *HT,int i,int *s1,int *s2);

//哈夫曼建树和编码
void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n);


//哈夫曼建树和编码
void HuffmanCoding_1(HuffmanTree *HT,HuffmanCode *HC,int *w,int n);
