

	/*
	date:8-11-2014
	author:doodlesomething
	reverse()  将字符串的顺序翻转
	Here is two versions
	*/
	

	/*
	------------------------------------------------------------------------
	version 1
	*/

	void reverse(char s[]) {
		int i,j;
		char tmp;

		for(i=0,(j=strlen(s)-1);i<j;i++,j--) {
			tmp=s[i];
			s[i]=s[j];
			s[j]=tmp;
		}
	}


	/*	
	---------------------------------------------------------------------------
	version 2
	*/
	void reverse(char *s) {
		char *p;
		char tmp;
		for(p=(s+strlen(s)-1);s<p;s++,p--) {
			tmp=*s;
			*s=*p;
			*p=tmp;
		}
	}
