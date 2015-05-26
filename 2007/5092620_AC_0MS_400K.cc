/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Scrambled Polygon
*       ID             : 2007
*       Date           : 5/4/2009
*       Time           : 14:13:59
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define MAXN 60

struct _point
{
	int x,y;
};

_point p[MAXN];
int ch[MAXN];
int i,j,n,l,top;
double sum;

inline double GetDistance(_point& p0,_point& p1)
{
	return sqrt((double)((p1.x-p0.x)*(p1.x-p0.x)+(p1.y-p0.y)*(p1.y-p0.y)));
}

inline int vp(int x1,int y1,int x2,int y2)
{
	return x1*y2-x2*y1;
}

inline int IsLeft(_point& p0,_point& p1,_point& p2)
{
	return vp(p1.x-p0.x,p1.y-p0.y,p2.x-p1.x,p2.y-p1.y);
}

bool cmp(_point p1,_point p2)
{
	int t=IsLeft(p[0],p1,p2);
	return t>0||t==0&&GetDistance(p[0],p1)<GetDistance(p[0],p2);
}

int main()
{
	//freopen("in_2007.txt","r",stdin);
	n=0;
	while(scanf("%d%d",&p[n].x,&p[n].y)!=EOF)
	{
		n++;
	}
	sort(p+1,p+n,cmp);
	for(i=0;i<n;++i)
	{
		printf("(%d,%d)\n",p[i].x,p[i].y);
	}
	return 0;
}
