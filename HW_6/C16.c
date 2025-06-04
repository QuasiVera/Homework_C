/*
 * C16.c
 * 
 * 
 * 
 */

#include <math.h>
#include <stdio.h>

int is_prime(int n)
{
	int flag = 1;
	if (n==1 || n==0) return 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i==0) 
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

int get_number(void)
{
	int x;
	scanf("%d", &x);
	return x;
}

int main()
{
	int num = get_number();
	char* str = is_prime(num)? "YES" : "NO";
	printf("%s\n", str);
	return 0;
}
