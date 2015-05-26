/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Mileage Bank
*       ID             : 1326
*       Date           : 4/26/2009
*       Time           : 9:22:44
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

int sum,m;
string f,t,c;

bool Work1()
{
	cin>>f;
	if(f=="0"||f=="#")
	{
		return false;
	}
	cin>>t>>m>>c;
	if(c=="F")
	{
		sum+=2*m;
	}
	if(c=="B")
	{
		sum+=int(m*1.5+0.5);
	}
	if(c=="Y")
	{
		if(m<500)
		{
			sum+=500;
		}
		else
		{
			sum+=m;
		}
	}
	return true;
}

bool Work()
{
	sum=0;
	while(Work1());
	if(f=="#")
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	//freopen("in_1326.txt","r",stdin);
	while(Work())
	{
		cout<<sum<<endl;
	}
	return 0;
}
