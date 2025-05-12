/*
 * B9.c
 * 
 * 
 * 
 * Ввести целое число и определить, верно ли, что все его цифры четные
 * 
 */


#include <stdio.h>

int main()
{
	int x;
    scanf("%d", &x);
    int i = 0;
    int flag = 1;
    while(x>0)
    {
        i = x%10;
        if (i%2!=0)
        { 
		flag = 0;
        break;
		}
        x=x/10;
    }
    if (flag) printf("YES");
    else printf("NO");
	return 0;
}

