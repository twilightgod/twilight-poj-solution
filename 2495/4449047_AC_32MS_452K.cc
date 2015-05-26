/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Incomplete chess boards
*       ID             : 2495
*       Date           : 12/3/2008
*       Time           : 13:1:0
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int main()
{
	int n,sum,t;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		sum=0;
		for(int j=0;j<4;++j)
		{
			cin>>t;
			sum+=t;
		}
		cout<<"Scenario #"<<i+1<<":\n";
		cout<<(sum%2?1:0)<<endl;
		cout<<endl;
	}
}
