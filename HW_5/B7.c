/*
 * B7.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>
#include <math.h>


int main()
{
	int x, x2, n, x_backup;
	scanf("%d", &x);
	x_backup=x;
	n = log10(x); // определяем число цифр, без +1 потому что циклы считаем от 0
	int flag = 1;
	for(int i =0; i<=n; i++)
	{
		int x_digit= x%10;
		// printf("x_digit = %d\n", x_digit);
		x/=10;
		x2=x_backup;
		for(int j=0; j<=n; j++)
		{
			int y_digit = x2%10;
			// printf("y_digit = %d\n", y_digit);
			x2 /=10;
			if (i==j) continue;
			else
			{
				if(y_digit==x_digit) flag = 0;
			}
		}
	}

	if(flag) printf("NO");
	else printf("YES");
	return 0;
}



