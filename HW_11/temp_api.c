/*
 * temp_api.c
 * 
 * 
 */


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <locale.h>
#include "temp_api.h"


//----------Добавление данных в массив структур

void AddRecord(struct sensor* info,int number,
uint16_t year,uint8_t month,uint8_t day,
uint8_t hour, uint8_t minute, uint8_t t )
{
	info[number].minute = minute;
	info[number].hour = hour;
	info[number].year = year;
	info[number].month = month;
	info[number].day = day;
	info[number].t = t;
}

int AddInfo(struct sensor* info)
{
int counter=0;
	AddRecord(info,counter++,2021,9,26,8,35,15);
	AddRecord(info,counter++,2021,9,26,8,51,16);
	AddRecord(info,counter++,2021,9,27,3,45,-2);
	AddRecord(info,counter++,2021,11,30,17,10,3);
	AddRecord(info,counter++,2021,3,11,12,30,-5);
	AddRecord(info,counter++,2022,8,15,12,40,17);
	AddRecord(info,counter++,2021,3,21,11,30,-3);
	AddRecord(info,counter++,2022,8,12,12,43,14);
	return counter;
}

void changeIJ(struct sensor* info,int i, int j)
{
struct sensor temp;
	temp=info[i];
	info[i]=info[j];
	info[j]=temp;
}
//----------сортировка по возрастанию температуры
void SortByT(struct sensor* info,int n)
{
	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j)
			if(info[i].t>=info[j].t)
			changeIJ(info,i,j);
}

//----------для сортировки по дате-времени
uint64_t DateToInt(struct sensor* info)
{
	return (uint64_t)info->year << 32 | (uint32_t)info->month << 24 | (uint32_t)info->day<<16 
	| (uint16_t)info->hour << 8 | info->minute;
}

//----------сортировка по дате-времени
void SortByDate(struct sensor* info,int n)
{
	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j)
			if(DateToInt(info+i)>= DateToInt(info+j))
				changeIJ(info,i,j);
}

//----------средняя температура за месяц
float AvgMonthT(struct sensor* info, int n, int month, int year)
{
	float avg = 0;
	int count = 0;
	for(int i=0; i<n; ++i)
	{
		if(info[i].year == year && info[i].month == month)
		{
			avg+=info[i].t;
			count++;
		}
	}
	avg/=(float)count;
	return avg;
}


//----------минимальная температура за месяц
int MinMonthT(struct sensor* info, int n, int month, int year)
{
	int minT = 128;				// максимально возможное значение температуры (int8_t)
		for(int i=0; i<n; ++i)
			if(info[i].year == year && info[i].month == month && info[i].t<minT)
				minT = info[i].t;
	return minT;
}

//----------максимальная температура за месяц
int MaxMonthT(struct sensor* info, int n, int month, int year)
{
	int maxT = -128;				// минимально возможное значение температуры (int8_t)
		for(int i=0; i<n; ++i)
			if(info[i].year == year && info[i].month == month && info[i].t>maxT)
				maxT = info[i].t;
	return maxT;
}

//----------минимальная температура за год
int MinYearT(struct sensor* info, int n, int year)
{
	int minT = 128;				
		for(int i=0; i<n; ++i)
			if(info[i].year == year && info[i].t<minT)
				minT = info[i].t;
	return minT;
}

//----------максимальная температура за год
int MaxYearT(struct sensor* info, int n, int year)
{
	int maxT = -128;				
		for(int i=0; i<n; ++i)
			if(info[i].year == year && info[i].t>maxT)
				maxT = info[i].t;
	return maxT;
}



//----------средняя температура за год
float AvgYearT(struct sensor *info, int n, int year)
{
	float avg = 0;
	int count = 0;
	for(int i=0; i<n; ++i)
	{
		if(info[i].year == year)
		{
			avg+=info[i].t;
			count++;
		}
	}
	avg/=(float)count;
	return avg;
}



//----------печать массива из структур
void print(struct sensor *info,int number)
{
	printf("================================= Данные с датчика\n");
	for(int i=0;i<number;i++)
		printf("%04d-%02d-%02d %02d:%02d t =%3d\n",
		info[i].year,
		info[i].month,
		info[i].day,
		info[i].hour,
		info[i].minute,
		info[i].t);
}

//----------преобразует число из строки
int StrToint(char *str_num)
{
    int num;
    if (sscanf(str_num, "%d", &num))
        return num;
    else
        printf("error! don't number\n");
}

//----------статистика за месяц

void MonthStat(struct sensor *info,int number, int month, int year)
{
	int min = MinMonthT(info, number, month, year);
	int max = MaxMonthT(info, number, month, year);
	float avg = AvgMonthT(info, number, month, year);
	printf("================================= Статистика за месяц \n");
	printf("средняя температура: %.2f\tминимальная температура: %d\t максимальная температура: %d \n", avg, min, max);
}



// int main(void)
// {
// 	struct sensor info[SIZE];
// 	int number=AddInfo(info);
// 	int te = MinMonthT(info, number, 9, 2021);
// 	//SortByT(info, number);
// 	SortByDate(info, number);
// 	//float avg9 = AvgYearT(info,number, 2021);
// 	print(info,number);
// 	printf("\n min temp = %d", te);
// 	return 0;
// }

