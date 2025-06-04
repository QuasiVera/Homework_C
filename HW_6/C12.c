/*
 * C12.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>
#include <math.h>
#define ACCURACY 0.0001


int factorial(int x)
{
	int res =1;
	for (int i = 1; i<=x; i++)
	{
		res*=i;
	}
	return res;
}

float module(float x)
{
	if (x<0) return -x;
	return x;
}

float sinus(float a, float accuracy)
{
	float term = a;
	float res = 0.0;
	int i = 1;
	while(module(term) > accuracy)
	{
		res+=term;
		term *= -1.0*(a*a)/((2*i+1)*(2*i)); // factorial(2*i+1)
		i++;
		//printf("term = %f \n", term);
	}
	return res;
}

int main()
{
	float angle;
	scanf("%f", &angle);
	angle = (M_PI*angle)/180;
	float res = sinus(angle, ACCURACY);
	
	printf("%.3f\n", res);
	//printf("%f\n", sin(angle)); 
	return 0;
}





