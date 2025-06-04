/*
 * C19.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>

int digit_to_num(char c)
{
    int num=0;
    if(c>='0' && c<='9') 
        num=c-'0';
    return num;
}


int main()
{
    char c;
    int sum=0;
    while( (c=getchar())!='.')
    {
        sum+=digit_to_num(c);
    }
    printf("%d",sum);
    return 0;
}

