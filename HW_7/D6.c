/*
 * D6.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>

void reverse_string()
{
	char c;
	if ((c=getchar())=='.') return;
		reverse_string();
		printf("%c", c);
}

int main()
{
	reverse_string();
	return 0;
}
