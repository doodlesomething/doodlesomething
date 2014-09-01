

	/*
	date:2014/9/1
	author:doodlesomething
	这是在看K&R的<<The C Programming Language>>时的练习题strindex的不同版本
	strindex 函数返回字符串 t 在字符串 s 中出现的起始位置或索引。当 s 不包含 t 时,返回值为-1。
	*/

        /*
	-----------------------------------------------------
	version 1
	*/

	int strindex(char source[],char pattern[]) {
		int i,j,k;

		for(i=0;source[i] != '\0';i++) {
			for(j=i,k=0;pattern[k] != '\0' && pattern[k] == source[j];k++,j++) 
				;
			if(k>0 && pattern[k] == '\0')
				return i;
		}

		return -1;
	}
	

	/*
	----------------------------------------------------------
	version 2
	*/
	int strindex(char *s,char *p) {
		char *tmp;
		while(*s) {
			s++;
			for(tmp=s;*p !='\0' && *p==*tmp;p++,tmp++)
				;
			if(*p=='\0')
				return (int)(tmp-s);
		}
		return -1;
	}



	/*
	-----------------------------------------------------------------------
	version 3
	*/


	//find out a char match the fist char of pattern and then return the location
	static char *strchar(char *s,int c) {
		char ch=c;
		
		for(;ch!=*s;s++)
			if(*s=='\0')
				return NULL;
		return s;
	}
	
	int strindex(char *s,char *p) {
		char *u,*v,*w;
		//when the pattern string is NULL
		if(*s=='\0') 
			return 0;
		//一旦有在s中出现和p中的第一个字符相同的就进入继续匹配
		for(u=s;(u=strchar(u,*p))!=NULL;u++) {
			for(v=u,w=p; ;)
				//但到最后一个字符时即匹配成功
				if(*++w=='\0')
					return (int)(u-s);
				//当发现有下一个字符不匹配就跳出循环
				else if(*++v !=*w)
					break;
		}
		//when the source don't contain the pattern string
		return -1;
	}
