/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Radar Installation
*       ID             : 1328
*       Date           : 4/25/2009
*       Time           : 21:17:48
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

#define MAXN 1000

struct Section
{
	double l,r;
};

Section s[MAXN];
int ttl,n,d,ca;

bool cmp(Section a,Section b)
{
	if(fabs(a.l-b.l)<1e-6)
	{
		return a.r-b.r>1e-6;
	}
	else
	{
		return a.l-b.l<1e-6;
	}
}

int Work()
{
	bool flag=false;
	for(int i=0;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(y>d)
		{
			flag=true;
		}
		s[i].l=x-sqrt((double)(d*d-y*y));
		s[i].r=x+sqrt((double)(d*d-y*y));
	}
	if(d<0||flag)
	{
		return -1;
	}
	sort(s,s+n,cmp);
	double R=s[0].r;
	ttl=1;
	for(int i=1;i<n;++i)
	{
		if(s[i].l-R>1e-6)
		{
			ttl++;
			R=s[i].r;
		}
		else if(fabs(s[i].l-R)<1e-6)
		{
			R=s[i].l;
		}
		else if(s[i].r-R<1e-6)
		{
			R=s[i].r;
		}
		//R=s[i].r;
	}
	return ttl;
}

int main()
{
	//freopen("in_1328.txt","r",stdin);
	ca=0;
	while(scanf("%d%d",&n,&d)&&n)
	{
		printf("Case %d: %d\n",++ca,Work());
	}
	return 0;
}

