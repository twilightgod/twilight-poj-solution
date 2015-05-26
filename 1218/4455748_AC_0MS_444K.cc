/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : THE DRUNK JAILER
*       ID             : 1218
*       Date           : 12/5/2008
*       Time           : 13:28:31
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

#define MAXN 101

bool sq[MAXN];
int sum[MAXN];
int n,t;

int main()
{
	//freopen("in_1218.txt","r",stdin);
	for (int i=1;i<MAXN;++i)
	{
		int t=int(sqrt(double(i)));
		if (t*t==i)
		{
			sq[i]=true;
		}
		else
		{
			sq[i]=false;
		}
	}
	sum[0]=0;
	for (int i=1;i<MAXN;++i)
	{
		sum[i]=sum[i-1]+sq[i];
	}
	cin>>t;

	for (int i=0;i<t;++i)
	{
		cin>>n;
		cout<<sum[n]<<endl;
	}

	return 0;
}
