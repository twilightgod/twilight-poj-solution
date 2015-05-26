/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Electrical Outlets
*       ID             : 2636
*       Date           : 4/26/2009
*       Time           : 13:27:50
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 20

int t,n,sum;

int main()
{
	//freopen("in_2636.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=-n+1;
		for(int i=0;i<n;++i)
		{
			int k;
			cin>>k;
			sum+=k;
		}
		cout<<sum<<endl;
	}
	return 0;
}
