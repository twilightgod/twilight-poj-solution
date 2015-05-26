/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Paths on a Grid
*       ID             : 1942
*       Date           : 5/13/2009
*       Time           : 13:30:29
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

long long m,n,ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1942.txt","r",stdin);
#endif
	while(cin>>m>>n)
	{
		if(m==0&&n==0)
		{
			break;
		}
		ans=1;
		if(n>m)
		{
			long long t=n;
			n=m;
			m=t;
		}
		
		for(long long i=1;i<=n;++i)
		{
			ans*=i+m;
			ans/=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}
