/*
 * E7.c
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

void SwapArr(int arr[],int i,int j)
{
	int temp = arr[i];
	arr[i]   = arr[j];
	arr[j]   = temp;
}

void SemiInversion(int arr[], int size)
{
	int i;
	for(i=0;i<size;i++)
		if (i<=(size/4))
		{
		//printf("i = %d \n", i);
		SwapArr(arr, i, (size/2)-i-1);
		//printf("swap OK \n");
		}
		else if (i>=(size/2) && i<(size*3/4))
		{
			//printf("i = %d \n", i);
			int t = (size*3/2)-1;
			SwapArr(arr, i, t-i);
		//printf("swap2 OK \n");
		}

	PrintArray(arr, size);
}


int main() {

	int arr[SIZE];
	GetArray(arr, SIZE);
	//PrintArray(arr, SIZE);
	SemiInversion(arr, SIZE);
	return 0;
}
