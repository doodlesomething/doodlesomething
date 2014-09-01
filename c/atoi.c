


	/*
	date:8-10-2014
	author:doodlesomething
	atoi函数 将字符串转换为对应数值的函数 atoi,它可以处理可选的前导空白符以及一个可选的加 (+)或减(-)号.
	*/

	/*
	---------------------------------------------------------
	version 1
	*/
	int atoi(char s[])
	{
		int i,n,sign;
		
		for(i=0;isspace(s[i]);i++)
			;
		sign=(s[i]=='-') ? -1:1;
		
		if(s[i]=='+' || s[i]=='-')
			i++;
		
		for(n=0;isdigit(s[i]);i++)
			n=n*10 + (s[i]-'0');

		return sign*n;
	}

	/*
	---------------------------------------------------------
	version 2
	*/
	int atoi(char *s)
	{
	    int n, sign;
	    while (isspace(*s))
	       s++;
	    sign = (*s == '+' || *s == '-') ? ((*s++ == '+') ? 1 : -1) : 1; //这一句比较有意思，三木运算符的重叠
	    for (n = 0; isdigit(*s); s++)
		n = (n * 10) + (*s - '0'); 

	    return sign * n;
	}
