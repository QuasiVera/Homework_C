/*
 * a7.c
 * 
 * Ввести два числа и вывести их  в порядке возрастания
 */


#include <stdio.h>

int main()
{
	    int a,b;
    scanf("%d %d", &a,&b);
    if (a<b)
    {
        printf("%d %d", a,b);
    }
    else 
    {
    printf("%d %d", b,a);
    }
    return 0;
}

