	

	/*
	date:9-1-2014
	author:doodlesomething
	strncmp()
	首先说明一下这个函数的作用是将s,t字符串的前n个字符左比较，而不是将t的前n个字符和s字符串比较（我以为是后一种）
	*/


	/*
	version 1
	*/

    int strncmp(const char *s,const char *t,int n) {  
            while(n>0 && *s==*t && *s!='\0') {  
                s++;  
                t++;  
                n--;  
            }  
    //n==0的情况可能类似：abcef 1234567 5； *s==*t的情况则类似于：abcef 12345 5   
            if(n==0|| *s==*t)  
                return 0;  
            if( *(unsigned char *)s < *(unsigned char *)t )  
                return -1;  
            return 1;  
        }  

	/*
	man 3 strncmp没有看到有源码

	网上找到一个还不错

	*/

	    int strncmp ( char * s1, char * s2, size_t n)  
	    {  
	      while (--n && *s1 && *s1 == *s2)  
	      {  
	      <span style="white-space:pre">  </span>s1++;  
	      <span style="white-space:pre">  </span>s2++;  
	      }  
	      return (*s1-*s2);  
	    }  
