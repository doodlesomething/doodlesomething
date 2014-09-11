/*
	date:9-4-2014
	author:doodlesomething

   编写一个具有加(+) 、减(-) 、乘(#).除(/) 取模（%）四则运算功能的计算器程序  用逆波兰表示法  

   由于在shell下*会被扩展为所在目录下的所有文件，所以就用#代替

   程序没有进行输入检测

  输入：./expr  1 2 +
  输入： 3

  输入：./expr  1 2 3 + -
  输入： -4
 */

#include <stdio.h>
#include <stdlib.h>	//提供库函数atoi()
#include <math.h>  //提供fmod()函数
#include <ctype.h>


#define NUMBER '0'

void push(int f);
int pop(void);


void panic(const char *msg) {
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]) {
	/*
	   由于涉及二元运算则，减数和被减数，除数和被除数位置不能颠倒，
	   pop()的先后顺序会有影响，故用中间变量op2来存储pop出来的值作为被减数或是被除数
	 */
	int  op2;
	int  getpar(char *s);
	int type;

	//所输入的计算公式没有结束
	while( --argc > 0 && ( type= getpar( *++argv )) ) {

			switch(type) {
				case NUMBER:
					push(atoi(*argv));
					break;
				case '+':
					push( pop()+pop() );
					break;

				case '#':
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
						printf("error:zero divsion\n");
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
				default:
					panic("Error:unkown operator");
					break;
			}
	}

	printf("the result is:%d\n",pop());

	return 0;
}


//判断类型
int  getpar(char *s) {
	char *tmp;

	tmp=s;

	while( ! isdigit(*tmp))
		return *tmp;
	
	return NUMBER;
}



#define MAXVAL 100
//栈顶指针
int sp=0;
//共享栈
int  val[MAXVAL];

//进栈
void push(int f) {
	if(sp<MAXVAL)
		val[sp++]=f;
}
//出栈并返回处在栈顶的元素
int  pop(void) {
	if(sp>0)
		//栈的特点是先进后出
		return val[--sp]; //这里为什么不是val[sp--]? 因为每次进栈后栈顶指针已经向后移动了一个，所以需要先减去1
	else {
		return 0;
	}
}

