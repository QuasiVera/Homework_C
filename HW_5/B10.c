/*
 * B10.c
 * 
 *
 * 
 *Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания 
 */


#include <stdio.h>

int main()
{
	int x, x1, x2;
    scanf("%d", &x);
    int flag = 1;
	x1 = x%10;
    while(x>0)
    {
        x2 = (x/10)%10;
        if (x1<=x2) 
        {
            flag = 0;
            break;
        }
        //~ printf("x1 = %d, x2 = %d\n", x1, x2);
        x1 = x2;
        x=x/10;
    }
    if (flag) printf("YES");
    else printf("NO");
	return 0;
}

