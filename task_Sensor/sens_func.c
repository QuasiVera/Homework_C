#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "sens_func.h"

struct sensor {
 uint8_t day;
 uint8_t month;
 uint16_t year;
 int8_t t;
};

//======меняет местами i- и j- элементы
void changeIJ(struct sensor* info,int i, int j){
struct sensor temp;
	temp=info[i];
	info[i]=info[j];
	info[j]=temp;
}

//============упорядочивающая по убыванию температуры
void SortByT(struct sensor* info,int n){
	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j)
			if(info[i].t>=info[j].t)
				changeIJ(info,i,j);
}

unsigned int DateToInt(struct sensor* info){
	return info->year << 16 | info->month << 8 | info->day;
}

//============упорядочивающая по дате
void SortByDate(struct sensor* info,int n){
	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j)
			if(DateToInt(info+i)>= DateToInt(info+j))
				changeIJ(info,i,j);
}


//===========добавляет запись (заполлняет поля структуры)
void AddRecord(struct sensor* info,int number,
uint16_t year,uint8_t month,uint8_t day,int8_t t){
	info[number].year = year;
	info[number].month = month;
	info[number].day = day;
	info[number].t = t;
}

//=========заполняет массив из структур
int AddInfo(struct sensor* info){
int counter=0;
	AddRecord(info,counter++,2021,9,16,9);
	AddRecord(info,counter++,2022,9,2,-9);
	AddRecord(info,counter++,2021,1,7,8);
	AddRecord(info,counter++,2021,9,5,1);
	AddRecord(info,counter++,2021,9,17,10);
	AddRecord(info,counter++,2022,9,3,-8);
	AddRecord(info,counter++,2021,1,8,7);
	AddRecord(info,counter++,2021,9,6,3);
	return counter;
}


void print(struct sensor* info,int number){
	printf("===================================\n");
	for(int i=0;i<number;i++)
		printf("%04d-%02d-%02d t=%3d\n",
		info[i].year,
		info[i].month,
		info[i].day,
		info[i].t);
}


int MaxMonthT(struct sensor* info, int n, int month, int year)
{
	int maxT = -128;		// минимально возможное значение температуры (int8_t)
	for(int i=0; i<n; ++i)
		if(info[i].year == year && info[i].month == month && info[i].t>maxT)
				maxT = info[i].t;
	return maxT;
}
