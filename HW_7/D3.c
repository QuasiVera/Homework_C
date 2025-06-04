/*
 * D3.c
 * 
 * 
 * 
 */


#include <stdio.h>

int reverse(int n) 
{
	if (n<10) return n;
	else 
	{
		printf("%2d",n%10);
		return reverse(n/10);
	}
	
}



int main()
{
	int num;
	scanf("%d", &num);
	printf ("%2d", reverse(num));
	return 0;
}
