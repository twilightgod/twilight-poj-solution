/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Optimal Parking
*       ID             : 3632
*       Date           : 5/16/2009
*       Time           : 9:22:52
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

int t,n,mi,ma;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3632.txt","r",stdin);
#endif
	cin>>t;
	while(t--)
	{
		cin>>n;
		mi=10000;
		ma=-1;
		while(n--)
		{
			int k;
			cin>>k;
			if(mi>k)
			{
				mi=k;
			}
			if(ma<k)
			{
				ma=k;
			}
		}
		cout<<(ma-mi)*2<<endl;
	}
	return 0;
}
