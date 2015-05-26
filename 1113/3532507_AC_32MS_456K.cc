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
int ch[MAXN],h[MAXN];
int i,j,n,l,top,hn;
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
	return p1.y<p2.y||p1.y==p2.y&&p1.x<p2.x;
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
		sort(p,p+n,cmp);
		ch[0]=0;
		ch[1]=1;
		top=1;
		for(i=2;i<n;++i)
		{
			while(top>0&&IsLeft(p[ch[top-1]],p[ch[top]],p[i])<=0)
			{
				top--;
			}
			ch[++top]=i;
		}
		memcpy(h,ch,top*sizeof(int));
		hn=top;
		ch[0]=n-1;
		ch[1]=n-2;
		top=1;
		for(i=n-3;i>=0;--i)
		{
			while(top>0&&IsLeft(p[ch[top-1]],p[ch[top]],p[i])<=0)
			{
				top--;
			}
			ch[++top]=i;
		}
		for(i=0;i<top;++i)
		{
			h[hn+i]=ch[i];
		}
		hn+=top;
		sum=4*acos((double)0)*l;
		for(i=0;i<hn;++i)
		{
			sum+=GetDistance(p[h[i]],p[h[i+1]]);
		}
		printf("%0.lf\n",sum);
	}
	return 0;
}
