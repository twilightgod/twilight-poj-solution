/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Monkeys' Pride
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1828
*       ID             : 1828
*       Date           : 10/7/2009
*       Time           : 9:53:44
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

#define MAXN 50000

struct POINT
{
	int x,y;
}p[MAXN];

inline bool cmp(POINT& a,POINT& b)
{
	if(a.x==b.x)
	{
		return a.y>b.y;
	}
	else
	{
		return a.x>b.x;
	}
}

int n,ans,lim;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1828.txt","r",stdin);
#endif
	while(scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		sort(p,p+n,cmp);
		lim=p[0].y;
		ans=1;
		for(int i=1;i<n;++i)
		{
			if(p[i].y>lim)
			{
				ans++;
				lim=p[i].y;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
