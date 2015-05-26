/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : The Perfect Symmetry
*       ID             : 1859
*       Date           : 1/7/2009
*       Time           : 22:47:5
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 20000

struct Point
{
	int x,y;
};

Point p[MAXN];
int n;
int cx,cy,xmin,xmax,ymin,ymax;

inline bool cmp(Point a,Point b)
{
	if (a.x==b.x)
	{
		return a.y<b.y;
	}
	else
	{
		return a.x<b.x;
	}
}

inline int max1(int a,int b)
{
	return a>b?a:b;
}

inline int min1(int a,int b)
{
	return a<b?a:b;
}

bool OK()
{
	for (int i=0,j=n-1;i<=n/2;++i,--j)
	{
		if (p[i].x+p[j].x!=cx||p[i].y+p[j].y!=cy)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	while (scanf("%d",&n)&&n)
	{
		xmin=ymin=1e20;
		xmax=ymax=-1e20;
		for (int i=0;i<n;++i)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			xmin=min1(xmin,p[i].x);
			ymin=min1(ymin,p[i].y);
			xmax=max1(xmax,p[i].x);
			ymax=max1(ymax,p[i].y);
		}
		cx=xmin+xmax;
		cy=ymin+ymax;
		sort(p,p+n,cmp);
		if (OK())
		{
			printf("V.I.P. should stay at (%.1lf,%.1lf).\n",cx/2.0,cy/2.0);
		}
		else
		{
			printf("This is a dangerous situation!\n");
		}
	}
	return 0;
}
