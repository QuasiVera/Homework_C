/*
 * C11.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>

void greatest_div(int x, int y)
{
	while (x*y!=0)
	{
		if (x>y) x = x%y;
		else y = y%x;
	}
	printf("%d", x+y);

}

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	greatest_div(x,y);
	return 0;
}

