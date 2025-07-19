/*
 * main Sensor
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include "temp_api.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "en_US.UTF-8");
    // struct sensor info[SIZE];
    struct sensor *info = malloc(SIZE * sizeof(struct sensor));
    if (!info)
        return -1;

    //free(info);
    char file[FILENAME];
    int m = 0;
    int in_file = ScanKeys(file, argc, argv, &m);

    if(in_file==1)
    {
        int number = GetData(info, file, m);
        if (m == 0)
        {
            for (int i = 1; i < 13; i++)
            {
                MonthStat1(info, number, i);
            }
        }
        else
            MonthStat1(info, number, m);
        printf("\n число записей в массиве %d", number);
    }
    free(info);
    return 0;
}
