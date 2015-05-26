/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : 4 Values whose Sum is 0
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2785
*       ID             : 2785
*       Date           : 5/27/2009
*       Time           : 20:55:23
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

#define MAXN 4000
#define MAXR 10000007

struct Node
{
	int s;
	int c;
	int next;
	Node()
	{
		next=-1;
		c=0;
	}
};

int hash[MAXR];
Node ns[MAXR];
int n,m;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
long long ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2785.txt","r",stdin);
#endif
	scanf("%d",&n);
	memset(hash,-1,sizeof(hash));
	for(int i=0;i<n;++i)
	{
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	}
	m=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			int s=a[i]+b[j];
			int wh=abs(s)%MAXR;
			int pre=hash[wh];
			int pos=pre;
			while(pos!=-1)
			{
				if(ns[pos].s==s)
				{
					ns[pos].c++;
					goto next;
				}
				pos=ns[pos].next;
			}
			ns[m].c=1;
			ns[m].s=s;
			ns[m].next=pre;
			hash[wh]=m++;
next:		;
		}
	}
	ans=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			int s=-(c[i]+d[j]);
			int wh=abs(s)%MAXR;
			int pos=hash[wh];
			while(pos!=-1)
			{
				if(ns[pos].s==s)
				{
					ans+=ns[pos].c;
					break;
				}
				pos=ns[pos].next;
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
