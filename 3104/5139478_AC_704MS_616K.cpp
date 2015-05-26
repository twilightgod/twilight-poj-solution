/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Drying
*       ID             : 3104
*       Date           : 5/12/2009
*       Time           : 13:48:53
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

#define MAXN 100000

int a[MAXN];
int n,k,l,r,m;

bool Check(int t)
{
	int cnt=0;
	for(int i=0;i<n;++i)
	{
		if(a[i]-t>0)
		{
			cnt+=(int)ceil((a[i]-t)/(double)(k-1));
			if(cnt>t)
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
	freopen("in_3104.txt","r",stdin);
#endif
	while(scanf("%d",&n)!=EOF)
	{
		r=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
			if(r<a[i])
			{
				r=a[i];
			}
		}
		scanf("%d",&k);
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
		//3 2
		printf("%d\n",l);
	}
	return 0;
}
