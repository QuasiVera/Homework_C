/*
 *F7.c
 * 
 * 
 * Функция принимает исходный массив a[] из единиц и нулей и сжимает в массив b[], N - число элементов в массиве a[].
 * массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1] преобразуется в [4,7,2,4] (т.к. начинается с нуля, 
 * то сразу записывается количество элементов первой серии)
 * массив [1,1,1,0,0,0,0,0,0,0] преобразуется в [0,3,7] (т.к. первая серия - это единицы, 
 * то первый элемент преобразованного массива 0)
 */
// из контеста 1 1 1 0 1 0 1 1 0 1 1 0 0 0 1 0 1 1 1 0 0 1 1 1 0 1 0 0 1 1 0 1 0 0 0 1 0 0 0 1 1 0 1 0 1 1 1 1 1 0 1 1 1 1 0 0 1 0 1 0 1 0 0 1 0 1 1 1 0 0 1 0 1 1 0 1 0 0 0 1 0 1 0 1 1 0 1 1 1 1 0 0 0 1 0 0 0 0 1 1

#include <stdio.h>
#define SIZE 100

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
}

int compression(int a[], int b[], int N)
{

	int j = 0;
	int count = 1;
	if (a[0] ==1)
	{
		*b=0;
		j++;
	}

	for (int i =1; i<N; i++)
	{
		if(a[i] == a [i-1])
		{
			count++;
		}
		else 
		{
			b[j] = count;
			count =1;
			//printf("else i = %d count = %d\n", i,count);
			j++;
		}
		if (i==N-1)
		{
			b[j] = count;
			//printf("j = %d last count = %d\n", j,count);
		}
	} 
	//printf("j = %d last count = %d\n", j,count);
	PrintArray(b, j+1);
		return j;
}



int main()
{
	int arr[SIZE];
	int b[SIZE];
	GetArray(arr, SIZE);
	int res = compression(arr, b, SIZE);
	return 0;
}



