/*
 * D5.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>

int toBin(int n)
{
	if (n == 0) 
		return 0; 
	else
		return (n % 2 + 10 * toBin(n / 2));
}

int main()
{
	int num;
	scanf("%d", &num);
	printf("%d\n", toBin(num));
	return 0;
}

