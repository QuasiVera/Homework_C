/*
 * B3.c
 * 
 * 
 * 
 */


#include <stdio.h>

int main()
{
	int a,b;
	int sum = 0;
	scanf("%d %d", &a, &b);
	for(; a <=b; a++)
	{   
        sum+=a*a;
        
    }
    printf("%d\n", sum);
	return 0;
}

