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

inline bool IsLeft(_point& p0,_point& p1,_point& p2)
{
	return (p1.x-p0.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p1.y-p0.y)>=0;
}

bool cmp(_point x,_point y)
{
	return !IsLeft(p[0],y,x);
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while(cin>>n>>l)
	{
		for(i=0;i<n;++i)
		{
			cin>>p[i].x>>p[i].y;
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
		sort(p+1,p+n-1,cmp);
		ch[0]=0;
		ch[1]=1;
		top=1;
		for(i=2;i<n;++i)
		{
			while(!IsLeft(p[ch[top-1]],p[ch[top]],p[i]))
			{
				top--;
			}
			ch[++top]=i;
		}
		sum=GetDistance(p[ch[0]],p[ch[top]])+3.1415926*l*2;
		for(i=0;i<top;++i)
		{
			sum+=GetDistance(p[ch[i]],p[ch[i+1]]);
		}
		printf("%0.lf\n",sum);
	}
	return 0;
}
