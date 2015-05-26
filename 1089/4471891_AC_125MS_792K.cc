/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Intervals
*       ID             : 1089
*       Date           : 12/10/2008
*       Time           : 7:47:11
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 50000

struct Interval
{
	int s,e;
};

bool cmp(Interval a,Interval b)
{
	return a.s<b.s;
}

Interval a[MAXN];
int n,ss,ee;

int main()
{
	//freopen("in_1089.txt","r",stdin);
	while (scanf("%d",&n)!=-1)
	{
		for (int i=0;i<n;++i)
		{
			scanf("%d%d",&a[i].s,&a[i].e);
		}
		sort(a,a+n,cmp);
		ss=a[0].s;
		ee=a[0].e;
		for (int i=1;i<n;++i)
		{
			if (a[i].s<=ee&&ee<a[i].e)
			{
				ee=a[i].e;
			}
			else if(ee<a[i].s)
			{
				printf("%d %d\n",ss,ee);
				ss=a[i].s;
				ee=a[i].e;
			}
		}
		printf("%d %d\n",ss,ee);
	}
	return 0;
}
