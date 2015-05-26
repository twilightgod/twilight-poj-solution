/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : ISBN
*       ID             : 2190
*       Date           : 5/8/2009
*       Time           : 21:37:39
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

string str;
int sum,p;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2190.txt","r",stdin);
#endif
con:	while(cin>>str)
	{
		sum=0;
		for(int i=0;i<10;++i)
		{
			if(str[i]=='?')
			{
				p=i;
				continue;
			}
			int d=str[i]-'0';
			if(str[i]=='X')
			{
				d=10;
			}
			sum+=(10-i)*d;
		}
		int m=p==9?10:9;
		for(int i=1;i<=m;++i)
		{
			if(((10-p)*i+sum)%11==0)
			{
				if(i!=10)
				{
					cout<<i<<endl;
				}
				else
				{
					cout<<'X'<<endl;
				}
				goto con;
			}
		}
		cout<<-1<<endl;
	}
	return 0;
}
