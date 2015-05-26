/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : World Cup
*       ID             : 3117
*       Date           : 11/19/2008
*       Time           : 10:50:25
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

int t,n,a,b,total,i,temp;
string s;

int main()
{
	//freopen("in_3117.txt","r",stdin);
	while(cin>>t>>n&&t)
	{
		total=0;
		for(i=0;i<t;++i)
		{
			cin>>s>>temp;
			total+=temp;
		}
		a=total-2*n;
		b=n-a;
		cout<<b<<endl;
	}
	return 0;
}
