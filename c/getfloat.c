	

	/*
	模仿函数 getint 的实现方法,编写一个读取浮点数的函数 getfloat。getfloat 函数的返回值应该是什么类型?

	getfloat 函数定义为int 型，但应该注意的是指针值应该定义double型，由于我没有正确定义类型会出现各种问题，
	float型还得不到精确值.故需要double ，数组的类型应该跟指针类型一致。
	*/

    #include <stdio.h>  
    #include <ctype.h>  
      
    #define BUFSIZE 100  
    #define MAXSIZE 4  
      
      
    int main() {  
        int getch(void);  
        void ungetch(int c);  
        int getfloat(double *pn);  
        double arr[MAXSIZE];  
        int i;  
        for(i=0;i<MAXSIZE && getfloat(&arr[i]) !=EOF;i++)  
            ;  
          
        for(i=0;i<MAXSIZE;i++)  
            printf("%f\t",arr[i]);  
        printf("\n");  
    }  

        static char buf[BUFSIZE];  
        static int bufp=0;  
      
        int getch(void) {  
            return (bufp>0)?buf[--bufp]:getchar();  
        }  
      
        void ungetch(int c) {  
            if(bufp>BUFSIZE)  
                printf("error:the buf is overflow\n");  
            else   
                buf[bufp++]=c;  
        }  
      
      

        int getfloat(double *pn) {  
            int c,sign;  
            float pow;  
      
            while(isspace(c=getch()))  
                ;  
            if(!isdigit(c) && c!=EOF && c!='+' && c!='-' && c!='.') {  
                ungetch(c);  
                return 0;  
            }  
      
            sign=(c=='-')? -1:1;  
            if(c=='+' || c=='-') {  
                c=getch();  
                if(!isdigit(c) && c!='.') {  
                    if(c==EOF) {  
                        return EOF;  
                    }  
                    else {  
                        ungetch(c);  
                        ungetch( (sign==-1)?'-':'+' );  
                        return 0;  
                    }  
                }  
            }  
      
            for(*pn=0.0;isdigit(c);c=getch()) {  
                *pn=*pn * 10.0 + (c-'0');  
            }  
            //处理有小数点的情况  
            if(c=='.') {  
                c=getch();  
                for(pow=1.0;isdigit(c);c=getch()) {  
                    *pn=*pn * 10.0 +(c-'0');  
                    pow=pow*10.0;  
                }  
                *pn=*pn * sign/pow;  
            }  
            else {  
                *pn *= sign;  
            }  
      
            if(c!=EOF)   
                ungetch(c);  
      
            return c;  
        }  
