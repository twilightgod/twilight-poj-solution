#include"stdio.h"
#define IN
#define UINT unsigned

unsigned n;

//Your code start

char *CD_AMultiplicationGmae(IN UINT uiN)
{
	while(uiN>=18)
	{
		uiN/=18;
	}
	if(uiN<=9)
	{
		return "Ming wins";
	}
	else
	{
		return "Jing wins";
	}
}

//Your code end

int main()
{
	//freopen("in.txt", "r", stdin);
	while(scanf("%lld", &n)==1)
	{
		if (CD_AMultiplicationGmae(n)[0]=='M')
		{
			puts("Stan wins.");
		}
		else
		{
			puts("Ollie wins.");
		}
	}
	return 0;
}