/*
 * C4.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>


int function (int n)
{
	if (n>=-2 && n<2)
		return n*n;
	else if (n>=2)
		return n*n+4*n+5;
	else
		return 4;
}

int main()
{
	int x, max=0;

	while(1)
	{
		scanf("%d", &x);
		if(x==0) break;
		//printf("f(%d) = %d\n", x, function(x));
		int f = function(x);
		max = max > f ? max : f;
	}
	printf("%d", max);
	return 0;
}

