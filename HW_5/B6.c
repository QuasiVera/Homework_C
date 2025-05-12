/*
 * B6.c
 * 
 * 
 * 
 */


#include <stdio.h>

int main()
{
	int x;
    scanf("%d", &x);
    int flag = 1;
    while(x>0)
    {
        int i1, i2 = 0;
        i1 = x%10;
        i2 = (x/10)%10;
        if (i1==i2) 
        {
            flag = 0;
            break;
        }
        x=x/10;
    }
    if (flag) printf("NO");
    else printf("YES");
	return 0;
}

