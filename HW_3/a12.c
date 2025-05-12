/*
 * a12.c
 * 
 * 
 * 
 */


#include <stdio.h>

int main()
{
	int x;
    scanf("%d", &x);
    int digit_sum = 0;
    while(x>0)  // условие х>0 годится только для положительных входных данных
    {
        digit_sum = digit_sum + x%10;
        x=x/10;
    }
    printf("%d", digit_sum);
    return 0;
	return 0;
}

