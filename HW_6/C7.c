/*
 * C7.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>

int power(int a, int x)
{
	int result = 1;
	for (int i = 0; i < x; i++)
	{
		result *= a;
	}
	return result;
}

int conversion(int n, int p)
{
	int i=0, res =0;
	while (n>0)
	{
		res = res + n%p*power(10,i);
		//printf("%d\n", res);
		n = n/p;
		i++;
	}
	return res;
}

int main()
{
	int n, p;
	scanf("%d %d", &n, &p);
	printf("%d\n", conversion(n,p));
	return 0;
}


