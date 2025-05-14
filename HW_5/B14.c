/*
 * B14.c
 * 
 * 
 * 
 * Дана последовательность ненулевых целых чисел, в конце последовательности число 0. Посчитать количество чисел.
 */


#include <stdio.h>

int main()
{
 	int x, num=0;

    while(1)
    {
    scanf("%d", &x);
	if(x==0) break;
    num++;
    }
    
    printf("%d",num);
	return 0;
}

