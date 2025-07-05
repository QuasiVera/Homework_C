#ifndef temp_api_h
#define temp_api_h
#endif 

#define SIZE 500

struct sensor {
uint8_t minute;
uint8_t hour;
uint8_t day;
uint8_t month;
uint16_t year;
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

float AvgMonthT(struct sensor *info, int n, int month, int year);

int MinMonthT(struct sensor *info, int n, int month, int year);

int MaxMonthT(struct sensor *info, int n, int month, int year);

int MinYearT(struct sensor *info, int n, int year);

int MaxYearT(struct sensor *info, int n, int year);

float AvgYearT(struct sensor *info, int n, int year);

void print(struct sensor *info, int number);

int StrToint(char *str_num);

void MonthStat(struct sensor *info, int number, int month, int year);
