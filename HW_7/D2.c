/*
 * D2.c
 * 
 * 
 * Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N
 */


#include <stdio.h>

int summa(int n) 
{
	if(n<=0) 
		return 0;
	int res = n + summa(n-1);
	//printf("summa = %d\n",res);
	return res; 
}


int main()
{
	int x;
	scanf("%d", &x);
	int sum = summa(x);
	printf("%d",sum);
	return 0;
}

