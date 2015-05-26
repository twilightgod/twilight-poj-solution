/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Space Ant
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1696
*       ID             : 1696
*       Date           : 10/10/2009
*       Time           : 13:9:58
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

#define MAXN 60

const double eps=1e-8;

struct _p{int x,y,idx;};

int sgn(double x)
{
	return (x>eps)-(x<-eps);
}

int dis2(_p a,_p b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int xmul(_p a,_p b,_p c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int dotmul(_p a,_p b,_p c)
{
	return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}

int t,n,low,cnt;
_p p[MAXN],ans[MAXN];
bool used[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1696.txt","r",stdin);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		low=200;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d",&p[i].idx,&p[i].x,&p[i].y);
			if(low>p[i].y)
			{
				low=p[i].y;
			}
		}
		ans[0].x=0;
		ans[0].y=low;
		low=-1;
		memset(used,false,sizeof(used));
		for(int i=0;i<n;++i)
		{
			if(ans[0].y==p[i].y)
			{
				if(low==-1||p[low].x>p[i].x)
				{
					low=i;
				}
			}
		}
		ans[1]=p[low];
		cnt=1;
		used[low]=true;
		while(1)
		{
			double at=1e10;
			low=-1;
			for(int i=0;i<n;++i)
			{
				if(!used[i]&&xmul(ans[cnt-1],ans[cnt],p[i])>=0)
				{
					double tmp=(double)dotmul(ans[cnt],ans[cnt-1],p[i])/sqrt((double)dis2(p[i],ans[cnt]))/sqrt((double)dis2(ans[cnt-1],ans[cnt]));
					if(low==-1||sgn(tmp-at)<0||sgn(tmp-at)==0&&(dis2(p[low],ans[cnt])>dis2(p[i],ans[cnt])))
					{
						low=i;
						at=tmp;
					}
				}
			}
			if(low==-1)
			{
				break;
			}
			used[low]=true;
			ans[++cnt]=p[low];
		}
		printf("%d",cnt);
		for(int i=1;i<=cnt;++i)
		{
			printf(" %d",ans[i].idx);
		}
		puts("");
	}
	return 0;
}
