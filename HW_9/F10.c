/*
 * F10.c
 * 
 * 
 * 
 * 
 */


#include <stdio.h>
#define SIZE 1001

	struct pack
	{
		char sym;
		int count;
	};
	
int PackStr(struct pack *pack1)
{
	int n = 0;
	int k=1;
	char c,p;
	p = getchar(); 
	while ((c = getchar()) != '.')
	{
		if (c!='.' && c==p) 
			k++;
		else
		{
			pack1[n].sym = p;
			pack1[n].count = k;
			//printf("%c%d",p,k);
			p=c;
			k=1;
			n++;
		}
	}
	pack1[n].sym = p;
	pack1[n].count = k;
	return n;
}

void PrintAnswer(struct pack *pack1,  int number)
{
	for(int j = 0; j<=number; j++)
		printf("%c%d",pack1[j].sym,pack1[j].count);
}

int main()
{

	struct pack pack1[SIZE];
	int n = PackStr(pack1);
	PrintAnswer(pack1,n);
	//printf("%c%d\n",p,k);

	return 0;
}

