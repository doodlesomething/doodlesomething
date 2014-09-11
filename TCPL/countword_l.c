/*
date:9-7-2014
author:doodlesomething
version:1.0

K&R 练习6.3

统计输入的单词中各个单词出现的次数 --->>>二叉树实现
并打印其所在行号 -->线性链表
每个二叉树节点中包含：左右子节点的指针，一个单词的存储指针，一个指向链表的指针
链表中包含所在节点单词出现的行号，一个节点的指针

bug:回车前不能带有空格；当有特殊字符时会出错（指行号出错） --->纠结了很久没有纠结出来 -->doodlesomething@163.com

 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLEN 100
#define BUFSIZE 1000



struct tnode {
	char *word;
	struct link *linkpoint;
	struct tnode *left;
	struct tnode *right;
};


struct link {
	int x;
	struct link *next;
};


int main(int argc,char *argv[]) {
	int getword(char *s,int lim,int *nlines);
	int exclude(char *s);

	struct tnode *addtree(struct tnode *p,char *w,int *nlines);
	void printtree(struct tnode *p);

	char word[MAXLEN];
	struct tnode *root;
	int nlines;
	int done;

	/*
	这一步不可少，否则编译器会随机分配一个不可知的地址 
	在后面判断就不为空了 -->感觉这也是个好习惯
	*/
	root = NULL;
	nlines = 0;
	done = 0;

	/*
	将返回是EOF的情况过滤
	这里getword返回两个值：1.字符 2.行号
	字符可直接返回，行号使用指针
	*/
	while(getword(word,MAXLEN,&done) != EOF) {
		//将返回时特殊字符和数字的情况过滤
		if(isalpha(word[0]) && !exclude(word) )
			root = addtree(root,word,&nlines);
		if(done)
			nlines++;

		done = 0;
	}
	//打印树
	printtree(root);
	
	printf("\n");
	printf("\n");

	return 0;
}


/*
   添加树

   每一步中,新单词与节点中存储的单词进行比较,随后,通过递归调用addtree 
   而转向左子树或右子树。该单词最终将与树中的某节点匹配(这种情况下计数
   值加 1) ,或遇到一个空指针(表明必须创建一个节点并加入到树中) 。若生成
   了新节点,则addtree 返回一个指向新节点的指针,该指针保存在父节点中
 */
struct tnode *addtree(struct tnode *p,char *w,int *nlines) {
	struct link *addlink(struct link *p,int *nlines);

	struct tnode *alloc(void);
	char *strup(char *w);
	int flag;
	/*
	   1.树还未建立，建树
	   2.比较新单词时，建树
	 */
	if(p == NULL ) {
		p = alloc();
		p->linkpoint = addlink(p->linkpoint,nlines);
		p->word = strup(w);
		p->left = p->right = NULL;
	}
	else if( (flag = strcmp(w,p->word)) == 0 ) {
		p->linkpoint= addlink(p->linkpoint,nlines);
	}
	//当小于当前节点时添加左子树
	else if(flag < 0 ) {
		p->left = addtree(p->left,w,nlines);
	}
	//当大于当前节点时添加右子树
	else {
		p->right = addtree(p->right,w,nlines);
	}

	return p;
}


struct link *addlink(struct link *p,int *nlines) {
	struct link *askMer(void);
	if(p == NULL) {
		p = askMer();
		p->x = *nlines;
		p->next = NULL;
	}
	else if(p->x != *nlines) {
		p->next = addlink(p->next,nlines);
	}

	return p;
}

/*
   打印树

   递归打印
   先打印左子树（比节点小的）  后打印右子树(比该节点大的)
   如 now is the time for all good men to come to the aid of their party
   >>
   aid all come for good is men now party of the their time to
 */
void printtree(struct tnode *p) {
	void printlink(struct link *p);
	if(p != NULL ) {
		printtree(p->left);
		printf("\n %s:",p->word);

		printlink(p->linkpoint);
		printtree(p->right);
	}
}


void printlink(struct link *p) {
	if(p != NULL) {
		printf("%d,",p->x);
		printlink(p->next);
	}
}

//动态分配内存，并进行类型强制转换--malloc返回为void类型
struct tnode *alloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
}

//为链表节点分配内存
struct link *askMer(void) {
	return (struct link *) malloc(sizeof(struct link));
}

/*
   将字符串放到安全的地方 ??? 我觉得不是

   我的理解是为字符串分配内存，并返回头指针
   p = (char *s) malloc(strlen(w)+1) 只是编译器向系统请求了那么大的内存而已
   字符串并没有复制过去，故最后需要复制保存
 */
char *strup(char *w) {
	char *p;
	//动态分配内存  +1是因为'\0'也占位置
	p = (char *) malloc(strlen(w)+1);

	if(p != NULL) {
		strcpy(p,w);
	}

	return p;
}


/*
   返回结果有可能是单个特殊字符，单个数字，单个字母，或是EOF

   输入如下字符串最后word所指向的字符串有可能是如下形式：
   const$static 12
   >>
   const 
   $（这里的$在const形成时会被送回缓冲区在下一轮被返回）
   static 
   1
   2


   const static
   >>
   const 
   static(空格会被过滤)

 */
int getword(char *word,int lim,int *done) {
	int c;
	int getch(void);
	void ungetch(int n);
	char *w = word;
	*done = 0;

	

	while( isspace(c=getch()) )
		;

	if( c != EOF )
		*(w++) = c;

	if( ! isalpha(c) ) {
		*w = '\0';
		return c;
	}

	for( ; --lim >0; w++) {
		if( (*w =getch()) == '\n') {
			*done = 1;
		}
		if ( ! isalnum(*w) ) {
			ungetch(*w);
			break;
		}
	}

	*w = '\0';

	return word[0];
}

//排除非实义单词
int exclude(char *s) {
	//注意这是一个指针数组 二分查找中必须保证升序或者是降序 这些好像是非实义单词？？？
	static char *list[] =
	{
		"a",
		"an",
		"and",
		"be",
		"but",
		"by",
		"he",
		"I",
		"is",
		"it",
		"off",
		"on",
		"she",
		"so",
		"the",
		"they",
		"you"
	};  
	int binsearch(char *s,char *list[],int length);
	int length;
	length = sizeof(list) / sizeof(char *);

	//二分查找
	return binsearch(s,list,length);

}


//二分查找
int binsearch(char *s,char *list[],int length) {
	int cond;
	int low,mid,high;

	//非实义单词的个数（长度）
	low = 0;
	high = length -1;

	while(low <= high) {
		mid = (low +high) / 2;

		if( (cond =strcmp(s,list[mid])) < 0) {
			high = mid -1;
		}
		else if(cond > 0) {
			low =mid +1;
		}
		else 
			return 1;
	}

	return 0;
}



//缓冲区
char buf[BUFSIZE];
//栈头指针
int bufp=0;

//获取一个字符：如果缓冲区有则在其中取，否则去键盘缓冲取
int getch(void) {
	return (bufp>0) ? buf[--bufp] : getchar();
}
//将非法字符送回缓冲区
void ungetch(int c) {
	if(bufp >= BUFSIZE)
		printf("Error:too many characters\n");
	else 
		buf[bufp++]=c;
}


/*
   测试用例：
   ./countword_l
   now is
   the time
   is 
   the 
   time

   >>
   now:0,
   time:1,4,
 */
