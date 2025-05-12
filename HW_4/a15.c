/*
 * eqOfLine.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
    int x1,y1,x2,y2;
    double k, b;
    scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
//    if(x2!=x1)
    {
    k = (double)(y2-y1)/(x2-x1); 
    b = y1 - k*x1; // и можно вычислить, подставив в уравнение координаты любой из двух точек, взяла точку х1 у1
    printf("%.2f %.2f", k, b);
    }
//    else printf("x = %d", x1); 	// избегаем деления на 0, если х1 = х2, то это прямая, 
												//параллельная оси у, уравнение будет иметь вид х = х1
	return 0;
}

