/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Power Strings
*       ID             : 2406
*       Date           : 4/19/2009
*       Time           : 21:54:4
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

#define MAXN 1000001

char ch[MAXN];
int n,m;

bool OK(int i)
{
	for(int j=1;j<m;++j)
	{
		for(int k=0;k<i;++k)
		{
			if(ch[k]!=ch[j*i+k])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	//freopen("in_2406.txt","r",stdin);
	while(scanf("%s",&ch))
	{
		if(strcmp(ch,".")==0)
		{
			break;
		}
		n=strlen(ch);
		for(int i=1;i<=n;++i)
		{
			if(n%i==0)
			{
				m=n/i;
				if(OK(i))
				{
					printf("%d\n",m);
					break;
				}
			}
		}
	}
	return 0;
}
