/*
 * B11.c
 * 
 *
 * 
 * Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.
 */


#include <stdio.h>

int main()
{
	int x, x_reverse=0;
    scanf("%d", &x);
    while (x>0)
    {
        x_reverse = x_reverse*10 + x%10;
        x/=10;
    }
    printf("%d", x_reverse);
    return 0;
}

