#define SIZE 30


void changeIJ(struct sensor *, int, int)

void SortByT(struct sensor *, int)

//============упорядочивает по убыванию температуры
unsigned int DateToInt(struct sensor *)

//============упорядочивает по дате
void SortByDate(struct sensor *,int)

//===========добавляет запись (заполлняет поля структуры)
void AddRecord(struct sensor *, int,
uint16_t, uint8_t, uint8_t, int8_t)

//=========заполняет массив из структур
int AddInfo(struct sensor *)

void print(struct sensor *, int)

int MaxMonthT(struct sensor *, int, int, int)