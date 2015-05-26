/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Accelerator
*       ID             : 3232
*       Date           : 5/13/2009
*       Time           : 12:43:32
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

#define MAXN 100000

int a[MAXN];
int n,mm,k,l,r,m,t;

bool Check(int t)
{
	long long cnt=0;
	long long ttl=t*mm;
	for(int i=0;i<n;++i)
	{
		if(a[i]-t>0)
		{
			int times=(int)ceil((a[i]-t)/(double)(k-1));
			if(times>t)
			{
				return false;
			}
			cnt+=times;
			if(cnt>ttl)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3232.txt","r",stdin);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		r=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
			if(r<a[i])
			{
				r=a[i];
			}
		}
		scanf("%d%d",&mm,&k);
		if(k==1)
		{
			printf("%d\n",r);
			continue;
		}
		l=0;
		while(l<=r)
		{
			m=(l+r)>>1;
			if(Check(m))
			{
				r=m-1;
			}
			else
			{
				l=m+1;
			}
		}
		printf("%d\n",l);
	}
	return 0;
}
