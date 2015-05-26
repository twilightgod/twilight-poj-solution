/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Factorial
*       ID             : 1401
*       Date           : 11/18/2008
*       Time           : 17:11:19
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int five[13];
int n,i,sum,test;

int main()
{
	//freopen("in_1401.txt","r",stdin);
	five[0]=1;
	for(i=1;i<13;++i)
	{
		five[i]=five[i-1]*5;
	}
	cin>>test;
	while(test--)
	{
		cin>>n;
		for(i=1,sum=0;i<13;++i)
		{
			sum+=n/five[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
