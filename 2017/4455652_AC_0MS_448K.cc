/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Speed Limit
*       ID             : 2017
*       Date           : 12/5/2008
*       Time           : 13:6:53
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int n,speed,hours,miles,t;

int main()
{
	//freopen("in_2017.txt","r",stdin);
	while(cin>>n&&n!=-1)
	{
		hours=0;
		miles=0;
		for (int i=0;i<n;++i)
		{
			cin>>speed>>t;
			miles+=speed*(t-hours);
			hours=t;
		}
		cout<<miles<<" miles\n";
	}
	return 0;
}
