/*
	date:9-6-2014
	author:doodlesomething
	version:1.1

	K&R 6.3 题例

	统计输入中结构体中单词出现次数
	使用指针实现

	question:数组的越界问题

*/

#include <stdio.h>
#include <ctype.h>

#define MAXLEN 100
#define NKEYS (sizeof keytab /sizeof(keytab[0]) )
#define BUFSIZE 1000


struct key {
	char *word;
	int count;
} keytab[]={
	//由于下面用的二分查找法，故需要提前排序
	{"case",0},
	{"char",0},
	{"const",0},
	{"for",0},
	{"if",0},
	{"int",0},
	{"main",0},
	{"return",0},
	{"static",0},
	{"struct",0},
	{"while",0}
};

int main(int argc,char argv[]) {
	int getword(char *s,int lim);
	struct key  *binsearch(char *word,struct key *,int n);
	char word[MAXLEN];
	struct key *p;

	//将返回是EOF的情况过滤
	while( getword(word,MAXLEN) != EOF) { 
		//将返回时特殊字符和数字的情况过滤
		if(isalpha(word[0]))
			if( (p = binsearch(word,keytab,NKEYS)) != NULL)
				p->count++;
	}

	//输出
	for(p = keytab ; p <keytab + NKEYS ;p++) {
		if(p->count > 0) {
			printf("%4d %s\n",p->count,p->word);
		}
	}

	return 0;
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

	//二分查找
	struct key *binsearch(char *word,struct key *keytab,int n) {
		int cond;
		struct key *low = &keytab[0];
		/*
		c语言中取数组末尾之后的第一个元素的指针进行运算是合法的 这样才能找到中间元素
		但数组开头之前的元素则是非法的
		<<c陷阱和缺陷>>中有解释
		*/
		struct key *high = &keytab[n];
		struct key *mid;

		while(low <high ) {
			//注意这里的运算
			mid = low + (high-low)/2;
			if( (cond = strcmp(word,mid->word)) < 0)
				//这里同样是取正常思路中之后一个元素的指针
				high = mid;
			else if(cond > 0)
				low = mid -1;
			else 
				return mid;
		}
		return NULL;
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
