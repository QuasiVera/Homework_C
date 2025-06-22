/*
 * F2.c
 * 
 * 
 * 
 * 
 */


//~ #include <stdio.h>
//~ #define SIZE 20


//~ void GetArray(int arr[], int size)
//~ {
	//~ int i;
	//~ for(i=0;i<size;i++)
		//~ scanf("%d",&arr[i]);
	//~ return;
//~ }

//~ void PrintArray(int arr[], int size)
//~ {
	//~ for(int i = 0; i < size; i++)
		//~ printf("%d ",arr[i]);
//}


void sort_even_odd(int n, int a[]) 
{
	for (int i =1; i<n; i++)
	{
		if (a[i]%2==0)
		{
			for (int j = i-1; j>=0 && a[j]% 2 != 0; j--)
			{
			int temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
			}
		}
	}
}


//~ int main()
//~ {
	//~ int arr[SIZE];
	//~ GetArray(arr, SIZE);
	//~ sort_even_odd(SIZE, arr);
	//~ PrintArray(arr, SIZE);
	//~ return 0;
//}


