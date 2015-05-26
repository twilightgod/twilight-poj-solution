/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Rope
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2365
*       ID             : 2365
*       Date           : 10/8/2009
*       Time           : 18:18:24
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

#define MAXN 100

struct point{double x,y;};

double r,ans;
int n;
point p[MAXN];

inline double dis(point& a,point& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2365.txt","r",stdin);
#endif
	scanf("%d%lf\n",&n,&r);
	for(int i=0;i<n;++i)
	{
		scanf("%lf%lf\n",&p[i].x,&p[i].y);
	}
	ans=2*acos(double(-1))*r;
	for(int i=0;i<n;++i)
	{
		ans+=dis(p[i],p[(i+1)%n]);
	}
	printf("%.2lf\n",ans);
	return 0;
}
