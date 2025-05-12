/*
 * maxDigit.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int x, max, digit;
    scanf("%d", &x);
    max = x%10;
    while(x>0)
    {
        x=x/10;
        digit = x%10;
        max = digit>max ? digit :max;
    }
    printf("%d", max);
	return 0;
}

