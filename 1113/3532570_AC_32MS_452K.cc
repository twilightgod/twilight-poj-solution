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
	//freopen("d:/in.txt","r",stdin);
	while(cin>>n>>l)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d %d",&p[i].x,&p[i].y);
		}
		j=0;
		for(i=1;i<n;++i)
		{
			if(p[i].y<p[j].y||p[i].y==p[j].y&&p[i].x<p[j].x)
			{
				j=i;
			}
		}
		_point pt=p[0];
		p[0]=p[j];
		p[j]=pt;
		sort(p+1,p+n,cmp);
		ch[0]=0;
		ch[1]=1;
		top=1;
		for(i=2;i<n;++i)
		{
			while(top>1&&IsLeft(p[ch[top-1]],p[ch[top]],p[i])<=0)
			{
				top--;
			}
			ch[++top]=i;
		}
		sum=GetDistance(p[ch[0]],p[ch[top]])+4*acos((double)0)*l;
		for(i=0;i<top;++i)
		{
			sum+=GetDistance(p[ch[i]],p[ch[i+1]]);
		}
		printf("%0.lf\n",sum);
	}
	return 0;
}
