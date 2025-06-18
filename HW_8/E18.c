/*
 * E18.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>
#define SIZE 8

int get_number(void)
{
	int x;
	scanf("%d", &x);
	return x;
}

void PrintArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d %d \n", i+2, arr[i]);
	printf("\n");
}

void CountMultiple(int arrCount[], int n)
{
	int k = 0;
	for(int i=2; i<=9; i++)
	{
		for(int j=2; j<=n; j++)
		{
			if(j%i==0)
				arrCount[k]++;
		}
		//printf("arr [%d] = %d\n", k, arrCount[k]);
		k++;
	}
}

int main() 
{
	int n = get_number();
	int arrCount[SIZE] = {0};
	CountMultiple(arrCount, n);
	PrintArray(arrCount, SIZE);
}

