/*
 * D4.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>

void reverse(int n) 
{
	if (n<10) printf("%2d",n);
	else 
	{
		reverse(n/10);
		printf("%2d",n%10);
	}
	
}



int main()
{
	int num;
	scanf("%d", &num);
	reverse(num);
	//printf ("%2d", reverse(num));
	return 0;
}
