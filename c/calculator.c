/*

编写一个具有加(+) 、减
(-)
、乘(*)
、除(/)四则运算功能的计算器程序  用逆波兰表示法

在逆波兰表示法中,所有运算符都跟在操作数的后面。比如,下列中缀表达式:(1 – 2) * (4 + 5)
采用逆波兰表示法表示为:
1 2 - 4 5 + *
逆波兰表示法中不需要圆括号,只要知道每个运算符需要几个操作数就不会引起歧义

算器程序的实现很简单。每个操作数都被依次压入到栈中;当一个运算符到达时,从
栈中弹出相应数目的操作数(对二元运算符来说是两个操作数)
,把该运算符作用于弹出的操
作数,并把运算结果再压入到栈中。例如,对上面的逆波兰表达式来说,首先把 1 和 2 压入
到栈中,再用两者之差-1 取代它们;然后,将 4 和 5 压入到栈中,再用两者之和 9 取代它们。
最后,从栈中取出栈顶的-1 和 9,并把它们的积-9 压入到栈顶。到达输入行的末尾时,把栈顶
的值弹出并打印。
这样,该程序的结构就构成一个循环,每次循环对一个运算符及相应的操作数执行一次
操作:
while (下一个运算符或操作数不是文件结束指示符)
	if (是数)
	将该数压入到栈中
	else if (是运算符)
	弹出所需数目的操作数
	执行运算
	将结果压入到栈中
	else if (是换行符)
	弹出并打印栈顶的值
	else
	出错
http://www.myexception.cn/program/1397438.html
*/

#include <stdio.h>
#include <stdlib.h>	//提供库函数atof()
#include <math.h>  //提供fmod()函数
#include <string.h>  //提供strcmp(); strcmp() 用来比较字符串（区分大小写），其原型为：

#include <ctype.h>


#define MAXOP 100 	//输入的最大长度
#define NUMBER '0'  //注意这里的NUMBER为一个boolean值，标示是否找到了一个数字，可以定义为其他的不一定是'0'
#define NAME 'n'  //表示找到了一字符串



int getop(char  []);
void push(double f);
double pop(void);
void  getTop();
void copy();
void exchange();
void clear();
double mathfunc(char s[]);

 int main() {
	 int type;
	 /*
	 由于涉及二元运算则，减数和被减数，除数和被除数位置不能颠倒，
	 pop()的先后顺序会有影响，故用中间变量op2来存储pop出来的值作为被减数或是被除数
	 */
	 double op2;
	 char s[MAXOP];
	//所输入的计算公式没有结束
	 while( (type =getop(s)) !=EOF ) {
		 switch(type) {
			 /*
			 这里的NUMBER是由getop返回的type,相当一个boolean
			 判断是type,是getop的返回值而不是获取的字符的值
			 */
			 case NUMBER:
			 	push(atof(s));
			 	break;
			case '+':
				push( pop()+pop() );
				break;

			case '*':
				push( pop() * pop() );
				break;

			//- / 是二元运算需要用到中间变量
			case '-':
				op2=pop();
				push( pop()-op2);
				break;

			case '/':
				op2=pop();
				//可能出现被除数为0的情况
				if(op2 != 0.0)
					push(pop()/op2);
				else
					printf("error:zero divisor\n");
				break;

			case '%':
				op2=pop();
				if(op2 != 0.0) 
					/*
					%两侧都应该为整型常量故不能使用，double fmod(double x,double y)
					返回 x/y 的余数
					*/
					push(fmod(pop(),op2));
				else 
					printf("error:zero modulo\n");
					break;
			//用符号来操作栈
			case '?':
				getTop();
				break;
			case '~':
				exchange();
				break;
			case '#':
				copy();
				break;
			case '!':
				clear();
				break;
			case NAME:
				mathfunc(s);
				break;
			case '\n':
				printf("\t%g\n",pop());		//取出最后的计算结果
				break;
			default:
				printf("error:unkown command %s\n",s);
				break;
		 }
	 }
	 return 0;
}


#define MAXVAL 100
//栈顶指针
int sp=0;
//共享栈
double val[MAXVAL];

//进栈
void push(double f) {
	if(sp<MAXVAL)
		val[sp++]=f;
	else
		printf("error:stack is full,can't push %g\n",f);
}
//出栈并返回处在栈顶的元素
double pop(void) {
	if(sp>0)
		//栈的特点是先进后出
		return val[--sp]; //这里为什么不是val[sp--]? 因为每次进栈后栈顶指针已经向后移动了一个，所以需要先减去1
	else {
		printf("error:stack empty\n");
		return 0.0;
	}
}

//返回栈顶值，这里没有弹出栈
void getTop() {
	if(sp>0)
		printf("the top of stack is :%g\n",val[sp-1]);
	else 
		printf("error:the stack is empty!\n");
}

//复制栈顶元素，并添加
void copy() {
	double tmp;
	tmp=pop();
	push(tmp);
	push(tmp);
}

//交换栈最上面的两个元素
void exchange() {
	double tmp1=pop();
	double tmp2=pop();
	push(tmp1);
	push(tmp2);
}
//清空栈
void clear() {
	sp=0;
}

//
double mathfunc(char s[]) {

    	/*int strcmp(const char *s1, const char *s2);若参数s1 和s2 字符串相同则返回0。s1 若大于s2 则返回大于0 的值。s1 若小于s2 则返回小于0 的值。
	*/
	if(0==strcmp(s,"sin"))
		push( sin(pop()) );
	else if(0==strcmp(s,"cos"))
		push( cos(pop()) );
	else if(0==strcmp(s,"exp"))
		push( exp(pop()) );
	else if(0==strcmp(s,"pow") ) {
		double tmp=pop();
		push( pow(pop(),tmp) );
	}
	else 
		printf("sorry the calculator don't support this function\n");
}



#include <ctype.h> //提供isdigit()和isspace()两个库函数

int getch(void);
void ungetch(int);
/*
函数返回NUMBER或是char(NUMBER 为标示值)
函数获取下一个运算符或操作数。它需要跳过空格与制表符。如果下一个字符不是数字或小数点,则返回;
否则,把这些数字字符串收集起来(其中可能包含小数点),并返回 NUMBER,以标识数已经收集起来了
*/
int getop(char s[]) {
	int i=0;
	int c;
	int next;
	/*
	跳过空格和制表符，即为空格和制表符时，接着下个判断：
	注意此时s=' \0';
	*/
	while( (s[0]=c=getch()) == ' ' || c == '\t')
		;
	s[1]='\0';

	if(islower(c)) {
		i=0;
		while(islower(s[i++]=c))
			c=getch();
		s[i-1]='\0';
		if(c!=EOF)
			ungetch(c);
		return NAME;
	}

	//倘若既不是数字也不是小数点，则有可能是操作符也有可能是负号，直接返回
	if(!isdigit(c) && c != '.' && c !='-' )
		return c;

	//含有-：负数，操作符；不含有-：数字
	if(c=='-' ) {
		next=getch();

		if(!isdigit(next) && next != '.') {
			return c;
		}
		c=next;
	}
	else {
		c=getch();
	}
	while(isdigit(s[++i]=c))
			c=getch();
	//还带有小数点
	if(c=='.')
		while(isdigit(s[++i]=c=getch()))
			;
	s[i]='\0';	//这是字符数组的结束标志
	  /*
	   这里的s正常情况下为' \0'或者‘数字 \0'
	   返回NUMBER的同时已经为s赋值了形式'1\0'经过atof处理变为数字;
	   s=' \0' or s=' \t'时由于没有返回值type为空被跳过
	  */

	if(c!=EOF)
		ungetch(c);

	return NUMBER;
}

/*
如果没有getch和ungetch这两个函数，仅仅用那个默认的getchar，会出现这种情况：比如你输入123+，前面三个字符都没问题，输入+之后，那个循环停止，函数返回123，这时候c='+'，但问题出现了，getop这个函数已经结束了，‘+’这个符号何去何从呢？下一次再用getop函数的时候，就是从'+'后面的字符开始了，就等于这个加号凭空消失了。也就是原文的意思：判断数字是否结束，要通过下一个非数字（也就是加号）来判断
而getch、ungetch就是解决这个问题的，还用上面的例子，在c='+'的时候，那个while循环结束，但是后面的ungetch，就是把这个‘+’放到一个缓冲区里；而在执行getch的时候，先看缓冲区里有没有东西，如果有，就直接把缓冲区里的东西拿出来（也就是加号），如果缓冲区是空的，那么就直接使用那个默认的getchar函数
*/

/*

如何实现输入缓存我们需要一个栈（存取都发生在数组的同一端），当发生“误读”时，就将这个字符推进栈中，
下一次读取时，如果栈不是空，就读取栈顶元素，否则就从标准输入读取。
*/

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;

//所谓的缓存区或是栈这里指数组
int getch(void) {
	//如果缓存区不为空，则读取缓存区的栈顶数据；否则getchar()一个字符
	return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if(bufp>=BUFSIZE)
		printf("ungetch:too many characters\n");
	else 
		//将“误读”的字符存在缓存区中
		buf[bufp++]=c;
}
