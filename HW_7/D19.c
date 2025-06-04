/*
 * D19.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>

int A_count()
{
	char c;
	int flag = 0;
	c=getchar();
	if (c=='.') return 0;
	if (c=='a') 
		flag = 1;
	return flag + A_count();
}

int main()
{
	int result = A_count();
	printf("%d", result);
}

