/*
 * B12.c
 * 
 * 
 * 
 * Организовать ввод натурального числа с клавиатуры. Программа должна определить наименьшую и наибольшую цифры, которые входят в состав данного натурального числа.
 */


#include <stdio.h>


int main()
{

	int x, max, min, x_prev;
    scanf("%d", &x);

	max = min = x%10;
    while(x/10>0)
    {
        x_prev = (x/10)%10;

		max = max > x_prev ? max : x_prev;
		min = min < x_prev ? min : x_prev;

        x=x/10;
    }


     
    printf("%d %d",min, max);

    return 0;
}

