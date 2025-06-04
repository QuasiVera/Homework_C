/*
 * D17.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>

int Ackermann(int n, int m)
{
	if(n==0) return m+1;
	if(m==0) return Ackermann(n-1, 1);
	return Ackermann(n-1, Ackermann(n, m-1));
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int result = Ackermann(n,m);
	printf("%d", result);
}

