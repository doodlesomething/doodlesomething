
	/*	
	date:9-1-2014
	author:doodlesomething

	strncat 原型实现
	*/
	
	/*
	version 1
	*/

	void strncat(char *s,const char *t,int n) {  
		char *tmp;  
		tmp=t;  
		while(*s)  
		    s++;  
		for(;t<(tmp+n)&&*t;t++,s++)  
		    *s=*t;  
    	}  


	/*
	version 2
	*/

	char *liw_strncat(char *s, const char *ct, size_t n) {  
		char *p;  
		p = s;  
		while (*p != '\0')  
		++p;  
		for (; n > 0 && *ct != '\0'; --n)  
		*p = '\0';  
		return s;  
	}

	/*
	version 3
	*/

	    char *strncat(char *dest, const char *src, size_t n)  
               {  
                   size_t dest_len = strlen(dest);  
                   size_t i;  
      
                   for (i = 0 ; i < n && src[i] != '\0' ; i++)  
                       dest[dest_len + i] = src[i];  
                   dest[dest_len + i] = '\0';  
      
                   return dest;  
               }  

	/*
	总结：
	主要是简单的指针使用，函数的实现都采用相同的思路。自己的程序不足主要体现在程序的"附加值“不够，
	应该在程序的后面返回一个指针方便程序的使用和扩展。这个文件程序都是之前和strncpy strncmp一起完成的所以问题相同
	*/
