/*
 * E9.c
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



void MoveToRight(int arr[], int size)
{
	int temp = arr[size-1];
	for(int i=size-1; i>0; i--)
		{
			arr[i] = arr[i-1];
		}
	arr[0] = temp;
}

int main()
{
	int arr[SIZE];
	GetArray(arr, SIZE);
	//PrintArray(arr, SIZE);
	MoveToRight(arr, SIZE);
	PrintArray(arr, SIZE);
	return 0;
}

