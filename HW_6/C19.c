/*
 * C19.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>

int digit_to_num()
{
	char c;
	int num=0;
	while( (c=getchar())!='.')
	{
		if(c>='0' && c<='9') 
			num+=c-'0';
	}
	return num;
}


int main()
{
	int sum = digit_to_num();
	printf("%d",sum);
	return 0;
}

