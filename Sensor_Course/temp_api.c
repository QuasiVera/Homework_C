/*
 * temp_api.c
 * 
 * 
 */


#include <stdio.h>
#include <unistd.h>
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

/*
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
} */

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
		for(int j=i+1; j<n; ++j)
			if(DateToInt(info+i)>= DateToInt(info+j))
				changeIJ(info,i,j);
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
        printf("Ошибка чтения значения ключа m\n");
}

//----------статистика за месяц

void MonthStat1(struct sensor *info, int number, int month)
{
	int min_m_t = 128;
	int max_m_t = -128;
	float avg_m_t = 0;
	int count = 0;
	for(int i=0; i<number; ++i)
		if(info[i].month == month)
		{
			max_m_t = info[i].t > max_m_t ? info[i].t : max_m_t;
			min_m_t = info[i].t < min_m_t ? info[i].t : min_m_t;
			avg_m_t += info[i].t;
			count++;
		}
    avg_m_t/=(float)count;
	printf("Месяц: %d\t макс. температура: %d\t мин. температура: %d\t сред. температура: %.2f \n", month, max_m_t, min_m_t, avg_m_t);
}


//---------- Отлов и чтение ключей из командной строки
int ScanKeys(char *file, int argc, char *argv[], int *pm)
{
	if(argc<2)
        printf("Это консольное приложение, которое осуществляет считывание текстового\
            \nфайла csv, и выводит статистику по температуре за год или указанный месяц\
            \nДля получения подробностей воспользуйтесь подсказкой -h");
    
	int rez;
	int flag = 0;
    while ((rez = getopt(argc, argv, "hm:f:")) != -1)
    {
        switch (rez)
        {
		case 'h':
			printf(" Это консольное приложение, которое осуществляет считывание текстового\
				\n файла csv, и выводит статистику по температуре за год или указанный месяц\
				\nПоддерживает следующиие ключи:\
				\n -h вызов подсказки; \
				\n -f <filename.csv> - входной файл csv для обработки\
				\n имя передаваемого файла должно быть не более 100 символов \
				\n -m <номер месяца> - если задан данный ключ, то выводится \
				\n только статистика за указанный месяц\n");
			break;
        case 'm':
            *pm = StrToint(optarg);
            if (*pm < 0 || *pm > 13)
            {
                printf("Ошибка при указании месяца\n Воспользуйтесь подсказкой -h \n");
                return 1;
            }
            break;
        case 'f':
            strncpy(file, optarg, strlen(optarg)+1);
            //printf("[%zu]\n", strlen(optarg));
            printf("принятый файл:[%s]\n", file);
			flag = 1;
            break;
        case '?':
            printf("Error found !\n");
            break;
        }
    }
	return flag;
}



//---------- Чтение данных из файла
// given_m определяет, будем читать все за год (given_m = 0) или за указанный месяц (0<given_m<13)
int GetData(struct sensor *info, char *filename, int given_m)
{

    int number = 0;
    int year, month, day, hour, minute, t, max_year_t = -128, min_year_t = 128;
    float avg_year = 0;

    FILE *f;
    char row[MAXCHAR];
    int count = 0;		//подсчет числа строк в файле
    f = fopen(filename, "r");
    if (f == NULL)		// проверка, что файл открылся
    {
		printf("Ошибка: не найден файл для обработки\
                \n Воспользуйтесь подсказкой -h \n");
        fclose(f);
        return -1;
    }
    else
    {
        while (fgets(row, MAXCHAR, f) != NULL) 
        {

            int r = sscanf(row, "%d;%d;%d;%d;%d;%d", &year, &month, &day, &hour, &minute, &t);
            if (r < M)		// Обработка ошибок в случае несоответсвия формата записей в файле
            {
                char s_err[MAXCHAR];
                r = sscanf(row, "%[^\n]", &s_err);
                printf("==========! Ошибка при считывании!  ======= ");
                printf("строка %d: %s\n", count, s_err);
            }
            else
            {
                if (given_m == 0)
                {
					AddRecord(info,number++,year,month,day,hour,minute,t); 
						//подсчет годовой статистики
                    max_year_t = t > max_year_t ? t : max_year_t;
                    min_year_t = t < min_year_t ? t : min_year_t;
                    avg_year += t;
                }
                else
                {
                    if (month == given_m)
                    {
                        AddRecord(info,number++,year,month,day,hour,minute,t);
                    }
                }
            }
            count++;
        }
        fclose(f);
        if (given_m==0)
        {
            avg_year/=(float)number;
            printf("----------------------------------------------------------------\n");
            printf("макс. t за год = %d\t мин. t за год = %d\t сред. t за год = %.2f \n", max_year_t, min_year_t, avg_year);
			printf("----------------------------------------------------------------\n");
		}
        return number;
    }
}





