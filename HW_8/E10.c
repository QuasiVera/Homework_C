/*
 * E10.c
 * 
 *
 * 
 * 
 */


#include <stdio.h>
#define SIZE 12
#define SHIFT 4

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


void MoveToRight1(int arr[], int size)
{
	int temp = arr[size-1];
	for(int i=size-1; i>0; i--)
		{
			arr[i] = arr[i-1];
		}
	arr[0] = temp;
}

void MoveToRight(int arr[], int size, int shift)
{
	for (int i = 0; i < shift; i++)
	{
		MoveToRight1(arr, size);
	}
}

int main()
{
	int arr[SIZE];
	GetArray(arr, SIZE);
	//PrintArray(arr, SIZE);
	MoveToRight(arr, SIZE, SHIFT);
	PrintArray(arr, SIZE);
	return 0;
}
