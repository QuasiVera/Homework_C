/*
 *F1.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>
#include <math.h>


//~ void GetArray(int arr[], int size, int num)
//~ {
	//~ int i;
	//~ for(i=size-1;i>=0;i--)
	//~ {
		//~ arr[i]= num%10;
		//~ num/=10;
	//~ }
	//~ return;
//~ }

//~ void PrintArray(int arr[], int size)
//~ {
	//~ int i;
	//~ for (i = 0; i < size; i++)
		//~ printf("%d ",arr[i]);
	//~ printf("\n");
//~ }

void sort_array(int size, int a[])
{
	for (int i = 0; i < size - 1; i++)
	{
		int pos = i;
		for (int j = i + 1; j < size; j++)
		{
			if (*(a+j) < *(a+pos)) pos = j;
		}
		int temp = *(a+i);
		*(a+i) = *(a+pos);
		*(a+pos) = temp;
	}
}

//~ int main()
//~ {
	//~ int num;
	//~ scanf("%d",&num);
	//~ int size = log10(num)+1;
	//~ int arr[size];
	//~ GetArray(arr, size, num);
	//~ sort_array(size, arr);
	//~ PrintArray(arr, size);
//}
