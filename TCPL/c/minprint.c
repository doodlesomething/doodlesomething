/*
	date:9-9-2014
	author:doodlesomething
	version:1.1

	实现简单版本的printf函数，主要问题在于不可知参数的个数处理-->stdarg.h

	以下摘自TCPL：
	va_list 类型用于声明一个变量,该变量将依次引用各参数。在函数 minprintf 中,
	我们将该变量称为 ap,意思是“参数指针”。宏 va_start 将 ap 初始化为指向第一个
	无名参数的指针。在使用 ap 之前,该宏必须被调用一次。参数表必须至少包括一个有
	名参数,	va_start 将最后一个有名参数作为起点。每次调用 va_arg,该函数都将返回
	一个参数,并将 ap 指向下一个参数。va_arg 使用一个类型名来决定返回的对象类型、
	指针移动的步长。最后,必须在函数返回之前调用va_end,以完成一些必要的清理工作。
*/

#include <stdarg.h>
#include <stdio.h>

int main(int argc,char *argv[]) {
	void minprint(char *fmt,...);
	int i=10;

	minprint("%d\n",i);
	minprint("%s\n","abcdefg");
	minprint("%u\n",i);
	minprint("%e\n",i);
	minprint("%g\n",i);
	minprint("%x\n",i);
	minprint("%o\n",i);
	minprint("%c\n",'a');
}


void minprint(char *fmt,...) {
	va_list ap;

	char *p,*sval;
	int ival;
	double dval;
	unsigned int oval;
	unsigned int uval;
	unsigned int xval;
	double eval;
	double gval;
	char *tmp;

	va_start(ap,fmt);

	for(p=fmt;*p;p++) {
		if(*p != '%') {
			putchar(*p);
			continue;
		}
		switch(*++p) {
			case 'i':
			case 'd':
				ival = va_arg(ap,int);
				printf("%d",ival);
				break;
			case 'o':
				oval  = va_arg(ap,unsigned int);
				printf("%o",oval);
				break;
			case 'u':
				uval = va_arg(ap,unsigned int);
				printf("%u",uval);
				break;
			case 'x':
			case 'X':
				xval = va_arg(ap,unsigned int);
				printf("%x",xval);
				break;
			case 'c':
				putchar(va_arg(ap,int));
				break;
			case 'f':
				dval = va_arg(ap,double);
				printf("%f",dval);
				break;
			case 's':
				for(sval=va_arg(ap,char *);*sval;sval++) 
					putchar(*sval);
				break;
			case 'e':
			case 'E':
				eval = va_arg(ap,double);
				printf("%e",eval);
				break;
			case 'g':
			case 'G':
				gval = va_arg(ap,double);
				printf("%g",gval);
				break;
			case 'p':
				tmp = va_arg(ap,void *);
				printf("%p",tmp);
				break;
			default:
				putchar(*p);
				break;
		}

		va_end(ap);
	}
}



