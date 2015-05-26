/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Nasty Hacks
*       ID             : 3030
*       Date           : 4/26/2009
*       Time           : 13:14:40
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int t,r,e,c;

int main()
{
	//freopen("in_3030.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>r>>e>>c;
		if(r-(e-c)==0)
		{
			cout<<"does not matter\n";
		}
		else if(r-(e-c)<0)
		{
			cout<<"advertise\n";
		}
		else
		{
			cout<<"do not advertise\n";
		}
	}
	return 0;
}
