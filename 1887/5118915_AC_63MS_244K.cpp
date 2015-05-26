/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Testing the CATCHER
*       ID             : 1887
*       Date           : 5/8/2009
*       Time           : 20:53:36
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 5000

int a[MAXN];
int f[MAXN];
int ans,n,ca;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1887.txt","r",stdin);
#endif
	ca=0;
	while(1)
	{
		n=0;
		while(1)
		{
			scanf("%d",&a[n++]);
			if(a[n-1]==-1)
			{
				if(n==1)
				{
					return 0;
				}
				else
				{
					n--;
					break;
				}
			}
		}
		memset(f,0,sizeof(f));
		ans=1;
		for(int i=0;i<n;++i)
		{
			int m=0;
			for(int j=0;j<i;++j)
			{
				if(a[j]>a[i]&&f[j]>m)
				{
					m=f[j];
				}
			}
			f[i]=m+1;
			if(f[i]>ans)
			{
				ans=f[i];
			}
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n",++ca,ans);
	}
	return 0;
}
