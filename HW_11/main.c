/*
 * main Sensor 
 * 
 * 
 */


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include "temp_api.h"



int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "en_US.UTF-8");
	struct sensor info[SIZE];
	int number=AddInfo(info);
    
    int rez = 0;
    // opterr=0; //чтобы отключить вывод сообщений об ошибках
    while ((rez = getopt(argc, argv, "hm:f:y:")) != -1)
    {
        switch (rez)
        {
        case 'h':
            printf(" This is help text \n ");
            break;
        case 'm':
            int m = StrToint(optarg);
            if (m > 0 && m < 13)
                printf(" month = %d \n", m);
            else
                printf(" %d don't month \n", m);
            //int te = 0;
            MonthStat(info, number, m, 2021);
            break;
        case 'f':
            printf(" file = %s\n", optarg);
            break;
        case 'y':
            int y = StrToint(optarg);
            //te = MaxYearT(info, number, y);
            printf("\n year = %d", y);
            break;    
        case '?':
            printf("Error found !\n");
            break;
        }
    }


	
	//SortByT(info, number);
	//SortByDate(info, number);
	//float avg9 = AvgYearT(info,number, 2021);
	//print(info,number);
	//printf("\n min temp = %d", te);
	return 0;
}
