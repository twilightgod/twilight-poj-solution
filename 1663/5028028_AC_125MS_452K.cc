/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Number Steps
*       ID             : 1663
*       Date           : 4/22/2009
*       Time           : 20:34:57
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int x,y,t;

int SNumber()
{
	if(x==y)
	{
		if(x%2)
		{
			return 2*x-1;
		}
		else
		{
			return 2*x;
		}
	}
	else if(x==y+2)
	{
		if(x%2)
		{
			return 2*y+1;
		}
		else
		{
			return 2*x-2;
		}
	}
	return -1;
}

int main()
{
	//freopen("in_1663.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		int ans=SNumber();
		if(ans==-1)
		{
			cout<<"No Number\n";
		}
		else
		{
			cout<<ans<<endl;
		}
	}
	return 0;
}
