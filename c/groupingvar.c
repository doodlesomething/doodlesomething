/*
date:9-6-2014
author:doodlesomething
version:1.0

K&R 6.2 练习

编写一个程序,用以读入一个 C 语言程序, 并按字母表顺序分组打印变量名,
要求每一组内各变量名的前 6 个字符相同,其余字符不同。字符串和注释中的单词不予考虑。
请将 6 作为一个可在命令行中设定的参数


question:字符串和注释的单词不予考虑？？？

说明：这里只是输出了具有变量名的前n个字符相同的字符串

 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLEN 100
#define BUFSIZE 1000
#define YES        1
#define NO         0 

//自结构体
struct tnode {
	char *word;
	int  match;
	struct tnode *left;
	struct tnode *right;
};


int main(int argc,char *argv[]) {
	int getword(char *s,int lim);
	struct tnode *addtree(struct tnode *p,char *w,int num,int *found);
	void printtree(struct tnode *p);
	char word[MAXLEN];
	struct tnode *root;
	int found;
	int num;

	//这一步不可少，否则编译器会随机分配一个不可知的地址  在后面判断就不为空了 -->感觉这也是个好习惯
	root = NULL;
	found = NO;

	num = (--argc > 0 && (*++argv)[0] == '-') ? atoi(++argv[0]) : 6;

	//将返回是EOF的情况过滤
	while( getword(word,MAXLEN) != EOF) { 
		/*
		将返回时特殊字符和数字的情况过滤  
		这里将长度不满足的直接去掉，可以提高效率
		*/
		if(isalpha(word[0]) && (strlen(word)) > num )
			root = addtree(root,word,num,&found);

		//每个单词比较完了之后，置found为为匹配
		found = NO;
	}
	
	printf("\n");
	//打印树
	printtree(root);

	return 0;
}


/*
   添加树

   每一步中,新单词与节点中存储的单词进行比较,随后,通过递归调用addtree 
   而转向左子树或右子树。该单词最终将与树中的某节点匹配(这种情况下计数
   值加 1) ,或遇到一个空指针(表明必须创建一个节点并加入到树中) 。若生成
   了新节点,则addtree 返回一个指向新节点的指针,该指针保存在父节点中
 */
struct tnode *addtree(struct tnode *p,char *w,int num,int *found) {

	int compare(char *w,struct tnode *p,int num,int *found);
	struct tnode *alloc(void);
	char *strup(char *w);
	int flag;
	/*
	   1.树还未建立，建树
	   2.比较新单词时，建树
	   3.当返回值为0时说明两个字符串相等，不做处理
	 */
	if(p == NULL ) {
		p = alloc();
		p->word = strup(w);
		p->match = *found;
		p->left = p->right = NULL;
	}
	else if( (flag = compare(w,p,num,found)) < 0 ) {
		p->left = addtree(p->left,w,num,found);
	}
	else if(flag > 0)  {
		p->right = addtree(p->right,w,num,found);
	}

	return p;
}

/*
   打印树
   递归打印
 */
void printtree(struct tnode *p) {
	if(p != NULL ) {
		printtree(p->left);
		if(p->match)
			printf("%s\n",p->word);
		printtree(p->right);
	}
}


/*比较命令行参数指定的个数 */
int compare (char *s, struct tnode *p, int num, int *found)
{
	int i;

	char *t = p->word;
	for(i = 0; *s == *t; i++,s++,t++)
		if(*s == '\0') {
			p->match = YES;
			*found = YES;
			//当两个字符串相等时不做处理
			return 0;
		}

	if(i >= num) {         
		*found = YES;
		p->match = YES;
	}

	return *s - *t;
}



//动态分配内存，并进行类型强制转换--malloc返回为void类型
struct tnode *alloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
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
   这里是我自己的想法写出来的
   关于tmp变量也可以设置一个char *tmp来递增（tmp=word），这样最后放回word[0]即可-->>感觉这样有点多余

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
int getword(char *word,int lim) {
	char c;
	char tmp;	
	int getch(void);
	void ungetch(int n);

	while( isspace(c=getch()) )
		;

	if( c != EOF )
		*word++ = c;
	tmp=c;

	if( ! isalpha(c) ) {
		*word = '\0';
		return c;
	}

	for( ; --lim >0; word++) {
		if ( ! isalnum(*word = getch())) {
			ungetch(*word);
			break;
		}
	}

	*word = '\0';

	return tmp;
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
	./groupingvar -2
	now is now the thetime theo to do %%
	>>
	now 

	the 
	theto
	thetime

	./groupingvar -2
	now is now the thetime tank tan
	>>
	now 
	tan
	tank
	the
	thetime
 */
