  	
	/*	
	date:8-11-2014
	author:doodlsomething
	getline()--函数返回的是整行的长度
	注意c中包含有getline编译时应该加上 -fno-builtin参数
	文件包含三个不同时期写的版本
	*/
	
	/*
	--------------------------------------------------------------------------------
	version 1
	*/
	int getline(char s[],int lim) {
		int c,i;

		for(i = 0;i < lim -1 && (c = getchar()) != EOF && c != '\n';++i)
			s[i] = c;
		if(c == '\n') {
			s[i] = c;
			++i;
		}
		s[i] = '\0'; /*'\0'以标志字符串的结束。c规定该类型的字符串常量将以字符数组的形式存储*/
		return i;
	}



	/*
	--------------------------------------------------------------------------------
	version 2
	*/
	int getline(char s[], int lim)
	{
	    int c, i;
	    i = 0;
	    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	    if (c == '\n')
		 s[i++] = c;
	    s[i] = '\0';
	    return i;
	}


	/*
	--------------------------------------------------------------------------------
	version 3
	*/
	int getline(char *s,int lim) {
		char *tmp;
		int c;

		 tmp=s;

		while(--lim>0 && (c=getchar())!=EOF && c!='\n')
			*tmp++=c;
		if(c=='\n')
			*tmp++=c;
		*tmp='\0';

		return (int)(tmp-s);
	}



