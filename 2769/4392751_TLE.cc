/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Reduced ID Numbers
*       ID             : 2769
*       Date           : 11/19/2008
*       Time           : 11:3:20
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 300
#define MAXS 1000000

int sin[MAXN];
bool hash[MAXS];
int g,m,i,test;

bool OK(int m)
{
	memset(hash,false,sizeof(hash));
	for(i=0;i<g;++i)
	{
		if(hash[sin[i]%m])
		{
			return false;
		}
		else
		{
			hash[sin[i]%m]=true;
		}
	}
}

int main()
{
	//freopen("in_2769.txt","r",stdin);
	cin>>test;
	while(test--)
	{
		cin>>g;
		for(i=0;i<g;++i)
		{
			cin>>sin[i];
		}
		for(m=1;m<=MAXS;++m)
		{
			if(OK(m))
			{
				cout<<m<<endl;
				break;
			}
		}
	}
	return 0;
}
