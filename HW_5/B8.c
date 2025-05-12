/*
 * B8.c
 * 
 * 
 * 
 * Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9»
 */


#include <stdio.h>

int main()
{
	int x;
    scanf("%d", &x);
    int j = 0;
    while(x>0)
    {
        int i =0;
        i = x%10;
        if (i==9) j++;
        
        x=x/10;
    }
    if (j==1) printf("YES");
    else printf("NO");
	return 0;
}

