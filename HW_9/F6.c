/*
 *F6.c
 * 
 * 
 * верно ли, что среди элементов массива есть два одинаковых. 
 * Если ответ «да», функция возвращает 1; если ответ «нет», то 0
 * 
 */


#include <stdio.h>
//~ #define SIZE 6

//~ void GetArray(int arr[], int size)
//~ {
	//~ int i;
	//~ for(i=0;i<size;i++)
		//~ scanf("%d",&arr[i]);
	//~ return;
//~ }

//~ void PrintArray(int *arr, int size)
//~ {
	//~ for (int i = 0; i < size; i++)
		//~ printf("%d ",*(arr+i));
//~ }


int is_two_same(int size, int a[])
{
	for(int i=0;i<size-1;i++)
	{
		for(int j = i+1; j<size; j++)
			{
				if (*(a+i)==*(a+j))
					return 1;
			}
	}
	return 0;
}

//~ int main()
//~ {
	//~ int arr[SIZE];
	//~ GetArray(arr, SIZE);
	//~ char* str = is_two_same(SIZE, arr)? "YES" : "NO";
	//~ printf("%s\n", str);
	//~ //PrintArray(arr, SIZE);
	//~ return 0;
//~ }

