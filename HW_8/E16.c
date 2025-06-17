/*
 * E16.c
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

int MaxFreq(int arr[], int size)
{
	int num = arr[0];
	int maxCount = 1;
	for (int i=0; i < size-1; i++)
	{
		int count = 1;
		for (int j = i+1; j< size; j++)
			if (arr[i] == arr[j])
				count++;
		if (count > maxCount)
		{
			maxCount = count;
			num = arr[i];
		}
	}
	return num;
}

int main()
{
	int arr[SIZE];
	GetArray(arr, SIZE);
	int res = MaxFreq(arr, SIZE);
	printf("%d", res);
	return 0;
}

