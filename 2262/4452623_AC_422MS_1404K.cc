/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Goldbach's Conjecture
*       ID             : 2262
*       Date           : 12/4/2008
*       Time           : 14:49:40
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 1000000

bool p[MAXN+1];
int n;

int main()
{
	//freopen("in_2262.txt","r",stdin);
	memset(p,true,sizeof(p));
	for (int i=2;i<=1000;++i)
	{
		if (p[i])
		{
			for (int j=i*i;j<=MAXN;j+=i)
			{
				p[j]=false;
			}
		}
	}
	while (cin>>n&&n)
	{
		for (int j=3;j<=MAXN;j+=2)
		{
			if (p[j]&&p[n-j])
			{
				printf("%d = %d + %d\n",n,j,n-j);
				break;
			}
		}
	}
	return 0;
}
