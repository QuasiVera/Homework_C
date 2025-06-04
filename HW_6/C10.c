/*
 * C10.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>
#include <math.h>


void print_simple(int n)
{
	for (int i = 2; i <= sqrt(n); i++) 
	{
		while (n%i == 0)
		{
			printf("%d ", i);
			n /= i;  
		}
	}
	if (n > 1) printf("%d", n);  
	printf("\n");  
}


int main()
{
	int n;
	scanf("%d", &n);
	print_simple(n);
	return 0;
}
