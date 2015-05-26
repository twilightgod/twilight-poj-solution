/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : TOYS
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2318
*       ID             : 2318
*       Date           : 10/10/2009
*       Time           : 11:0:53
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

#define MAXN 5001

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
int cnt[MAXN];
bool first=true;
_p tt;

bool Check(int mid)
{
	return sgn(xmul(p2[mid],tt,p1[mid]))<0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2318.txt","r",stdin);
#endif
	while(scanf("%d",&n)&&n)
	{
		if(first)
		{
			first=false;
		}
		else
		{
			puts("");
		}
		_p t1,t2;
		scanf("%d%lf%lf%lf%lf\n",&m,&t1.x,&t1.y,&t2.x,&t2.y);
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf\n",&p1[i].x,&p2[i].x);
			p1[i].y=t1.y;
			p2[i].y=t2.y;
		}
		p1[n].x=p2[n].x=t2.x;
		p1[n].y=t1.y;
		p2[n].y=t2.y;
		memset(cnt,0,sizeof(cnt));
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
			printf("%d: %d\n",i,cnt[i]);
		}
	}
	return 0;
}
