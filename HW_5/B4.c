/*
 * B4.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>
#include <math.h>

int main()
{
	int a;
	int i =0;
	scanf("%d", &a);
    while(a!=0)
    {
        a = a/10;
        i++;
    }
    if (i==3) printf("YES");
    else printf("NO");
    
    // Ради любопытства, другой вариант
    
    //~ int b = log10(a)+1;
    //~ if (b==3) printf("YES");
    //~ else printf("NO");
    
    
	return 0;
}

