	
	/*
	题目：函数 getint 接受自由格式的输入,并执行转换,将输入的字符流分解成整数,且每次调用得到一个整数。getint 需要返回转换后得到的整数,
	并且,在到达输入结尾时要返回文件结束标记。这些值必须通过不同的方式返回。EOF(文件结束标记)可以用任何值表示,当然也可用一个输入的整数表示。


    	这道题的关键是返回两个值。可以这样设计该函数:将标识是否到达文件结尾的状态作为 getint 函数的返回值,同
	时,使用一个指针参数存储转换后得到的整数并传回给主调函数。（指针的用处体现出来了，传进去的是指针，通过指针操作对象值）
	*/


    #include <stdio.h>  
    #include <ctype.h>  
      
    #define BUFSIZE 100  //缓冲区大小  
    #define MAXSIZE 4   //定义最大数组上限  
      
      
    int main() {  
        int getch(void);  
        void ungetch(int c);  
        int getint(int *pn);  
        int arr[MAXSIZE];  
        int i;  
        for(i=0;i<MAXSIZE && getint(&arr[i]) !=EOF;i++)  
            ;  
          
        for(i=0;i<MAXSIZE;i++)  
            printf("%d\t",arr[i]);  
        return 0;  
    }  


        //缓冲区数据和缓冲区指针定义为static  
        static char buf[BUFSIZE];  
        static int bufp=0;  
        //如果缓冲区中有字符则从其中取，否则获取一个  
        int getch(void) {  
            return (bufp>0)?buf[--bufp]:getchar();  
        }  
        //将字符送到缓冲区  
        void ungetch(int c) {  
            if(bufp>BUFSIZE)  
                printf("error:the buf is overflow\n");  
            else   
                buf[bufp++]=c;  
        }  


      
	int getint(int *pn) {  
            int c,sign;  
            //跳过空额  
            while(isspace(c=getch()))  
                ;  
            //将其他字符送回缓冲区  
            if(!isdigit(c) && c!=EOF && c!='+' && c!='-') {  
                ungetch(c);  
                return 0;  
            }  
      
            sign=(c=='-')? -1:1;  
            if(c=='+' || c=='-') {  
                //倘若+.-后面不是数字则将该字符送到缓冲区  注意顺序 如+b 应该在缓冲区为b+  
                if(!isdigit(c=getch())) {  
                    ungetch(c);  
                    ungetch( (sign==-1)?'-':'+' );  
                    return 0;  
                }  
                else  
                    c=getch();  
            }  
            //计算值  
            for(*pn=0;isdigit(c);c=getch()) {  
                *pn=*pn * 10 + (c-'0');  
            }  
            *pn *= sign;  
      
            if(c!=EOF)   
                ungetch(c);  
      
            return c;  
        }  
