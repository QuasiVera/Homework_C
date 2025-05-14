/*
 * B13.c
 * 
 * 
 * 
 * Посчитать количество четных и нечетных цифр числа.
 */


#include <stdio.h>

int main()
{
	int x, even, odd;
    scanf("%d", &x);
	even = odd =0;
    while(x>0)
    {
		int i = x%10;
        i%2==0 ? even++ : odd++;

        x=x/10;
    }

     
    printf("%d %d",even, odd);
	return 0;
}

