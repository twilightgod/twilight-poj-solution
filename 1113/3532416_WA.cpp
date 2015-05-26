#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define MAXN 1000

struct _point
{
	int x,y;
};

_point p[MAXN];
int d[MAXN*2];
int i,j,n,l,top,bot;
double sum;
bool tleft,bleft;

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

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while(cin>>n>>l)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d %d",&p[i].x,&p[i].y);
		}
		top=n+1;
		bot=n-2;
		d[n-1]=0;
		d[n]=1;
		for(i=2;i<n;++i)
		{
			if(IsLeft(p[0],p[1],p[i])!=0)
			{
				break;
			}
		}
		d[n-2]=d[n+1]=i;
		if(IsLeft(p[0],p[1],p[i])<=0)
		{
			swap(d[n],d[n-1]);
		}
		for(++i;i<n;++i)
		{
			if(IsLeft(p[d[bot]],p[d[bot+1]],p[i])>0&&IsLeft(p[d[top-1]],p[d[top]],p[i])>0)
			{
				continue;
			}
			while(IsLeft(p[d[top-1]],p[d[top]],p[i])<=0)
			{
				top--;
			}
			while(IsLeft(p[d[bot]],p[d[bot+1]],p[i])<=0)
			{
				bot++;
			}
			d[++top]=i;
			d[--bot]=i;
		}
		sum=4*acos((double)0)*l;
		for(i=bot;i<top;++i)
		{
			sum+=GetDistance(p[d[i]],p[d[i+1]]);
		}
		printf("%0.lf\n",sum);
	}
	return 0;
}
