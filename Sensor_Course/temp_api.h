#ifndef temp_api_h
#define temp_api_h
#endif 

#define SIZE 1000000
#define MAXCHAR 25      // для функции GetData размер временной строки
#define M 6             // для функции GetData, столько чисел должно получиться из строки
#define FILENAME 104    // допустим, 100 символов хватит для имени файла .csv

struct sensor {
uint16_t year;
uint8_t month;
uint8_t day;
uint8_t hour;
uint8_t minute;
int8_t t;
};

void AddRecord(struct sensor *info, int number,
               uint16_t year, uint8_t month, uint8_t day,
               uint8_t hour, uint8_t minute, uint8_t t);

int AddInfo(struct sensor *info);

void changeIJ(struct sensor *info, int i, int j);

void SortByT(struct sensor *info, int n);

uint64_t DateToInt(struct sensor *info);

void SortByDate(struct sensor *info, int n);

void print(struct sensor *info, int number);

int StrToint(char *str_num);

int GetData(struct sensor *info, char *filename, int given_m);

void MonthStat1(struct sensor *info, int number, int month);

int ScanKeys(char *file, int argc, char *argv[], int *pm);
