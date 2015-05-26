/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Alignment
*       ID             : 1836
*       Date           : 5/7/2009
*       Time           : 18:11:28
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 1000

double h0[MAXN],h1[MAXN];
int f0[MAXN],f1[MAXN];
int n,ans;

int main()
{
//	freopen("in_1836.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>h0[i];
		h1[n-i-1]=h0[i];
	}
	memset(f0,0,sizeof(f0));
	for(int i=0;i<n;++i)
	{
		int m=0;
		for(int j=0;j<i;++j)
		{
			if(f0[j]>m&&h0[j]<h0[i])
			{
				m=f0[j];
			}
		}
		f0[i]=m+1;
	}
	memset(f1,0,sizeof(f1));
	for(int i=0;i<n;++i)
	{
		int m=0;
		for(int j=0;j<i;++j)
		{
			if(f1[j]>m&&h1[j]<h1[i])
			{
				m=f1[j];
			}
		}
		f1[i]=m+1;
	}
	ans=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n-i-1;++j)
		{
			if(f0[i]+f1[j]>ans)
			{
				ans=f0[i]+f1[j];
			}
		}
	}
	cout<<n-ans<<endl;
	return 0;
}
