/*
 * E13.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>
#define SIZE 10

void GetArray(int arr[], int size)
{
	int i;
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	return;
}

void PrintArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void ZeroTens(int arr[], int size)
{
	int i;
	int j=0;
	int arr2[size];
	for(i=0;i<size;i++)
		if (arr[i]%100<10)
		{
			arr2[j]=arr[i];
			j++;
		}
	PrintArray(arr2, j);
}


int main() {

	int arr[SIZE];
	GetArray(arr, SIZE);
	//PrintArray(arr, SIZE);
	ZeroTens(arr, SIZE);
	return 0;
}

