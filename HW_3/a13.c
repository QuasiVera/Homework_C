/*
 * a13.c
 * 
 * 
 * 
 */


#include <stdio.h>

int main()
{
	int x;
    scanf("%d", &x);
    int res = 1;

    while(x!=0)
    {
        res = res * (x%10);
        x=x/10;
    }
    printf("%d", res);
    return 0;
}

