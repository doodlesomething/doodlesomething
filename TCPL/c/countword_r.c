/*
	date:9-7-2014
	author:doodlesomething
	version:1.0

	K&R 6.4 编写一个程序根据单词出现的频率降序打印单词，并在单词前打印单词出现的次数

	统计输入的单词中各个单词出现的次数 --->>>二叉树实现
	由于涉及到降序所以需要进行排序，使用结构体数组存储--->>>快速排序

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLEN 100
#define BUFSIZE 1000
#define MAXSIZE 100




struct tnode {
	char *word;
	int count;
	//自引用结构
	struct tnode *left;
	struct tnode *right;
};

struct key {
	char *word;
	int count;
} keytab[MAXSIZE];


static int  n=0;
struct tnode *alloc(void);
char *strup(char *w);
struct key *askMer(void);


int main(int argc,char *argv[]) {
	int getword(char *s,int lim);
	struct tnode *addtree(struct tnode *p,char *w);
	void storetree(struct tnode *p);
	void printresult(struct key *keytab);
	void quicksort(struct key *keytab,int left,int right);

	char word[MAXLEN];
	struct tnode *root;

	//这一步不可少，否则编译器会随机分配一个不可知的地址  在后面判断就不为空了 -->感觉这也是个好习惯
	root = NULL;

	//将返回是EOF的情况过滤
	while( getword(word,MAXLEN) != EOF) { 
		//将返回时特殊字符和数字的情况过滤
		if(isalpha(word[0]))
		root = addtree(root,word);
	}

	//将树中的节点顺序拷贝到结构体数组中
	storetree(root);
	//排序
	quicksort(keytab,0,n-1);
	//打印结果
	printresult(keytab);

	return 0;
}


	/*
	添加树

	每一步中,新单词与节点中存储的单词进行比较,随后,通过递归调用addtree 
	而转向左子树或右子树。该单词最终将与树中的某节点匹配(这种情况下计数
	值加 1) ,或遇到一个空指针(表明必须创建一个节点并加入到树中) 。若生成
	了新节点,则addtree 返回一个指向新节点的指针,该指针保存在父节点中
	*/
	struct tnode *addtree(struct tnode *p,char *w) {
		int flag;
		/*
		1.树还未建立，建树
		2.比较新单词时，建树
		*/
		if(p == NULL ) {
			p = alloc();
			p->word = strup(w);
			p->count = 1;
			p->left = p->right = NULL;
		}
		else if( (flag = strcmp(w,p->word)) == 0 ) {
			p->count++;
		}
		//当小于当前节点时添加左子树
		else if(flag < 0 ) {
			p->left = addtree(p->left,w);
		}
		//当大于当前节点时添加右子树
		else {
			p->right = addtree(p->right,w);
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

	void storetree(struct tnode *p) {
		if(p != NULL ) {
			storetree(p->left);
			/*
			分配内存
			将树的每个节点的字符串地址和单词统计值
			赋值给结构体数组
			n++;
			*/
			keytab[n].word = p->word;
			keytab[n].count = p->count;
			n++;
			storetree(p->right);
		}
	}

	//快速排序
	void quicksort(struct key *keytab,int left,int right) {
		int i,last,tmp;
		void swap(struct key *keytab,int i,int j);

		if(left >= right)
			return;

		tmp=(left + right)/2;

		//防止两个count值相同的值还交换
		if(keytab[left].count != keytab[tmp].count)
			swap(keytab,left,tmp);

		last = left;
		for(i = left+1;i <= right;i++) {
			if(keytab[i].count > keytab[left].count)
				swap(keytab,++last,i);
		}
		swap(keytab,left,last);
		quicksort(keytab,left,last-1);
		quicksort(keytab,last+1,right);
	}

	//交换指针值和count值
	void swap(struct key *keytab,int i,int j) {
		char *temp;
		int tmp;
		//交换字符串指针
		temp = keytab[i].word;
		keytab[i].word = keytab[j].word;
		keytab[j].word = temp;
		//交换count值
		tmp = keytab[i].count;
		keytab[i].count = keytab[j].count;
		keytab[j].count = tmp;

	}

	//打印结果
	void printresult(struct key keytab[]) {
		int i;
		for(i = 0;i < n; i++) {
			printf("%4d %s\n",keytab[i].count,keytab[i].word);
		}
	}



	//动态分配内存，并进行类型强制转换--malloc返回为void类型
	struct tnode *alloc(void) {
		return (struct tnode *) malloc(sizeof(struct tnode));
	}

	//为keytab数组中每个元素分配内存
	struct key *askMer(void) {
		return (struct key *) malloc(sizeof(struct key));
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
	now is the time for hacker--> hacker is hacking
	>>
	1 for
	2 hacker 
	2 is 
	1 now 
	1 the 
	1 time
	*/
