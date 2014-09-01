	/*
	date:9-1-2014
	函数 strncpy(s, t, n)将 t 中最多前 n 个字符复制到 s中
	Here are four versions
	*/

	/*
	-----------------------------------------------------------------
	verson 1
	*/
	void strncpy(char *s,const char *t,int n) {  
	    char *tmp;  
	    tmp=t;  
	  
	    for(;t<(tmp+n);s++,t++)  
		*s=*t;  
	}

	/*
	--------------------------------------------------------------------
	version 2
	*/

	char *my_strncpy(char *dest, const char *src, int count)    
	{    
	    char *tmp = dest;    
	    while(count) {    
		if ((*tmp = *src) != 0)    
		    src++;    
		tmp++;    
		count--;    
	    }    
	    return dest;    
	}   


	/*
	--------------------------------------------------------------------
	version 3
	*/

	    char *liw_strncpy(char *s, const char *ct, size_t n) {  
	    	char *p;  
	    	p = s;  
	    	for (; n > 0 && *ct != '\0'; --n)  
	    		*p++ = *ct++;  
	    	for (; n > 0; --n)  
	    	*p++ = '\0';  
	    	return s;  
	    }  

	/*
	--------------------------------------------------------------------
	man strncpy 查看一下原型(这个应该和平台有关--Ubuntu)
	version 4
	*/
	    char *strncpy(char *dest, const char *src, size_t n)  
               {  
                   size_t i;  
      
                   for (i = 0; i < n && src[i] != '\0'; i++)  
                       dest[i] = src[i];  
                   for ( ; i < n; i++)  
                       dest[i] = '\0';  
      
                   return dest;  
               }

	/*
	总结：主要是简单的指针使用，函数的实现都采用相同的思路。自己的程序不足主要体现在程序的"附加值“不够，应该在程序的后面
	返回一个指针方便程序的使用和扩展。

	*/


