/*
 * sens_seminar.c
 * 
 * 
 */


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "sens_func.h"



int main(void)
{
	struct sensor info[SIZE];
	int number=AddInfo(info);
	//~ print(info,number);
	SortByDate(info,number);
	int maxt = MaxMonthT(info,number,9,2021);
	printf("max month t = %d\n", maxt);
	print(info,number);
	return 0;
}
