
/*
date:9-10-2014
author:doodlesomething
version:1.3

K&R 7.7练习 

程序执行可能性：
1.没传参-->错误提示
2.只传入了pattern却没有传入 文件名  -->用户输入，并最后打印结果
3.三者都传入了	->处理文件内容

使用结构体数组来存储符合条件的字符串和行号

strstr()---> <string.h>
exit()--->  <stdlib.h>
extern char *strstr(const char *str1,const char *str2);
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000 //max length of every line
#define MAXMATCH 100

//利用结构体可以减少元素的复制和移动
struct linenode {
	char *word;
	int linenum;
} linetab[MAXMATCH];

int main(int argc,char *argv[]) {
	char line[MAXLEN];
	FILE *fp;
	char *prog;
	int nlines,linenum;
	char *p;
	char *pattern;

	void getit(struct linenode *linetab,char *line,int lim,FILE *ifp,char *pattern,int *linenum,int *nlines);

	void print(struct linenode *linetab,int nlines);
	nlines = 0;
	linenum = 0;
	pattern = argv[1];
	prog = argv[0];

	//程序未传参时
	if(argc <= 1 ) {
		fprintf(stderr,"%s Usagae:%s pattern [filename]\n",prog,prog);
		exit(1);
	}
	/*
	程序以这样的形式执行  grep test时可以让用户输入
	*/
	else if(argc == 2) {
		getit(linetab,line,MAXLEN,stdin,pattern,&linenum,&nlines);
	}
	else {

		fp = fopen(argv[2],"r");
		if(fp == NULL) {
			fprintf(stderr,"%s:can't open file or directory %s\n",argv[0],argv[2]);
			exit(1);
		}
		else {
			getit(linetab,line,MAXLEN,fp,pattern,&linenum,&nlines);
		}

		fclose(fp);
	}
	/*
	检测输出错误即使这种可能很小
	*/
	if(ferror(stdout)) {
		fprintf(stderr,"%s:can't not writing out!\n",prog);
		exit(2);
	}

	print(linetab,nlines);

	exit(0);
}

//打印
void print(struct linenode *linetab,int nlines) {
	int i;
	for(i = 0; i < nlines;i++ ) {
		printf("%d:%s",linetab[i].linenum,linetab[i].word);
	}
}


//将符合的字符串的信息写入结构体数组中
void getit(struct linenode *linetab,char *line,int lim,FILE *ifp,char *pattern,int *linenum,int *nlines) {
	char *strup(char *line);
	int getLine(char *line,int lim,FILE *ifp);

	while( getLine(line,lim,ifp) > 0) {
		(*linenum)++;

		if( strstr(line,pattern) != NULL) {
			if( (linetab[*nlines].word = strup(line)) != NULL) {
				linetab[*nlines].linenum = *linenum;
				(*nlines) ++;
			}
		}
	}
}

/*
分配存储空间并存储字符串
*/
char *strup(char *line) {
	char *s;
	s = (char *) malloc (strlen(line)+1);

	if(s != NULL)
		strcpy(s,line);

	return s;
}

//获取一行
int getLine(char *line,int max,FILE *ifp) {

	if( fgets(line,max,ifp) == NULL)
		return 0;
	else
		return strlen(line);
}
