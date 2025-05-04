/*
 * a8.c
 * 
 * 
 * Ввести три числа, найти наибольшее из них 
 */


#include <stdio.h>

int main()
{   
	 int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    int max =a;
    if (b>max)
    {
        max = b;
    }

    if (max>c)
    {
        printf("%d", max);
    }
    else 
    {
        printf("%d", c);
    }
	
	return 0;
}

