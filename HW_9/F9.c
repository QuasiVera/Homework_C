/*
 * F9.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>
#include <limits.h>

#define SIZE 10

void GetArray(int arr[], int size)
{
	int i;
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	return;
}

void PrintArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ",*(arr+i));
	printf("\n");
}

void swap_negmax_last(int size, int a[])
{
	int max = INT_MIN;
	int pos_max = 0;
	for (int i = 0; i<size; i++)
	{
		if(a[i]<0)
		{
			if (a[i]>max)
			{
				max = a[i];
				pos_max = i;
			}
			//max = a[i]>max? a[i] : max;
		}
	}
	printf("max neg: %d\n", max);
	if(max!=INT_MIN)
		{
			int tmp = a[size - 1];
			a[size - 1] = max;
			a[pos_max] = tmp;
		}
	return;
}





int main()
{
	int arr[SIZE];
	GetArray(arr, SIZE);
	//PrintArray(arr,SIZE);
	swap_negmax_last(SIZE, arr);
	PrintArray(arr,SIZE);
	return 0;
}
