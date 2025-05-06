/*
 * min+maxFrom5.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
    int a,b,c,d,e;
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    int max =a, min =a;
    if (b>a) max =b;
    else min = b;

    if (c>max) max=c;
    else if (c<min) min =c; // если верхнее условие истинно, тогда это действие делать не надо в отличие от:
										//   max = 
										
										//   min = min <c ? min :c;
										// хотя, числа могут быть заданы в порядке убывания и делать придется все
    
    if (d>max) max=d;
    else if (d<min) min =d;
    
    if (e>max) max=e;
    else if (e<min) min =e;

    printf("%d \n", max+min);
	return 0;
}

