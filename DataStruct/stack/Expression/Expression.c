/*----------------------------------------------------------------
	* file:Expression.c
	* date:24-9-2014
	* author:doodlesomething@163.com
	* version:.10
	* description:表达式求值
	* mention:该程序只能输入的数字不能大于9（可以写个字符处理
	函数来完成），否则出bug，且必须以#结尾
-----------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "liststack.h"
#include "sqstack.h"


int IsOperator(char c);
SElemType EvaluateExpression();
int Operate(int a,char c,int b);
char compare(char c,char elem);
int IsOperator(char c);

int main(int argc,char *argv[]) {
	printf("%d\n",EvaluateExpression());
}


/*
* @description:表达式求值
	1.使用两个工作栈，一个放运算符，另一个方操作数和结果
	2.当"(" = ")" 时表示左右括号相遇，括号内运算完成，#与#相遇表示表达式运算完成（在左边预设一个#）
	3.初始化两栈，#入运算符栈
	4.读入字符，判断是否为操作符，否则入操作数栈，为操作符则根据优先级进行操作
* @return ElemType elem
*/
SElemType EvaluateExpression() {
	LinkStack OPTR; //操作符栈
	SqStack OPND; //操作数栈
	char c,elem,tmp,operator;
	int a,b,d;

	InitStack(&OPTR);
	Push(&OPTR,'#');
	InitStack1(&OPND);
	c = getchar();
	GetTop(OPTR,&elem);

	while(c != '#' || elem != '#' ) {
		//不是操作符则进OPND栈
		if(isdigit(c)) {
			c = c - '0';
			Push1(&OPND,c);
			c = getchar();
		}
		else {
			switch(compare(c,elem)) {
				case '<':
					Push(&OPTR,c);
					c = getchar();
					break;
				case '=':
					Pop(&OPTR,&tmp);
					c = getchar();
					break;
				case '>':
					Pop(&OPTR,&operator);
					Pop1(&OPND,&a);
					Pop1(&OPND,&b);
					Push1(&OPND,Operate(a,operator,b));
					break;
				default:
					exit(OVERFLOW);	
					break;
			}
		}
	
		GetTop(OPTR,&elem);	
	}
	GetTop1(OPND,&d);

	return d; 
}


//求值
int Operate(int a,char c,int b) {
	int result;

	result = 0;

	switch(c) {
		case '+':
			result = a + b;
			break;
		case '-':
			result = b - a;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			if(a != 0)
				result = b / a;
			else
				exit(OVERFLOW);
			break;
		default:
			exit(OVERFLOW);
			break;

	}

	return result;
}


//获取操作符的位置，返回它的位置，如果不是其中的操作符则返回-1
int IsOperator(char c) {
	int i;

	char op[7] = {'+','-','*','/','(',')','#'};
	
	for(i = 0; i < 7; i++ ) {
		if(op[i] == c)
			return i;
	}

	return -1;
}


//比较返回两个操作符的优先等级,=  > < 等
char compare(char c,char elem) {
	char str[7][7] = {
	       //+   -   *   /   (   )   #
 		'>','>','<','<','<','>','>',
		'>','>','<','<','<','>','>',
		'>','>','>','>','<','>','>',
		'>','>','>','>','<','>','>',
		'<','<','<','<','<','=',' ',
		'>','>','>','>',' ','>','>',
		'<','<','<','<','<',' ','='
	};

	int i,j;

	i = IsOperator(c);
	j = IsOperator(elem);

	if(i >= 7 || j >= 7)
		return ERROR;

	return str[j][i];
}
