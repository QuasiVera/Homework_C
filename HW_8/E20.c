/*
 * E20.c
 * 
 *
 * 
 * 
 */


#include <stdio.h>
#include <math.h>


void GetArray(int arr[], int size, int num)
{
	for(int i=size-1;i>=0;i--)
	{
		arr[i]= num%10;
		num/=10;
	}
	return;
}

void PrintArray(int arr[], int size)
{
	for(int i = 0; i < size; i++)
		printf("%d",arr[i]);
}

void SortSelection(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int pos = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] > array[pos]) pos = j;
		}
		int temp = array[i];
		array[i] = array[pos];
		array[pos] = temp;
	}
}

int ArrayToNum(int array[], int size)
{
	int num = 0;
	for (int i = 0; i < size; i++)
	
		num =num*10 + array[i];
	return num;
}

int main()
{
	int num;
	scanf("%d",&num);
	int size = log10(num)+1;
	int arr[size];
	GetArray(arr, size, num);
	SortSelection(arr, size);
	//PrintArray(arr, size);
	int res = ArrayToNum(arr, size);
	//printf("\n");
	printf("%d", res);
	return 0;
}

