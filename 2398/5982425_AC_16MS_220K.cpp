/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Toy Storage
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2398
*       ID             : 2398
*       Date           : 10/10/2009
*       Time           : 11:55:14
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 1001

const double eps=1e-8;

struct _p{double x,y;};

int sgn(double x)
{
	return (x>eps)-(x<-eps);
}

double xmul(_p a,_p b,_p c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int n,m,l,r,mid;
_p p1[MAXN],p2[MAXN];
int cnt[MAXN],cnt2[MAXN];
_p tt;
int ord[MAXN];

bool Check(int mid)
{
	return sgn(xmul(p2[ord[mid]],tt,p1[ord[mid]]))<0;
}

bool cmp(int a,int b)
{
	if(p1[a].x==p1[b].x)
	{
		return p2[a].x<p2[b].x;
	}
	else
	{
		return p1[a].x<p1[b].x;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2398.txt","r",stdin);
#endif
	while(scanf("%d",&n)&&n)
	{
		puts("Box");
		_p t1,t2;
		scanf("%d%lf%lf%lf%lf\n",&m,&t1.x,&t1.y,&t2.x,&t2.y);
		for(int i=0;i<n;++i)
		{
			ord[i]=i;
			scanf("%lf%lf\n",&p1[i].x,&p2[i].x);
			p1[i].y=t1.y;
			p2[i].y=t2.y;
		}
		sort(ord,ord+n,cmp);
		ord[n]=n;
		p1[n].x=p2[n].x=t2.x;
		p1[n].y=t1.y;
		p2[n].y=t2.y;
		memset(cnt,0,sizeof(cnt));
		memset(cnt2,0,sizeof(cnt2));
		while(m--)
		{
			scanf("%lf%lf\n",&tt.x,&tt.y);
			l=0;
			r=n+1;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(Check(mid))
				{
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			cnt[l]++;
		}
		for(int i=0;i<=n;++i)
		{
			cnt2[cnt[i]]++;
		}
		for(int i=1;i<=n;++i)
		{
			if(cnt2[i])
			{
				printf("%d: %d\n",i,cnt2[i]);
			}
		}
	}
	return 0;
}