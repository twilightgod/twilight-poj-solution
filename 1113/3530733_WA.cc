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
int chl[MAXN],chr[MAXN];
int i,j,n,l,topl,topr;
bool used[MAXN];
double sum;

inline double GetDistance(_point& p0,_point& p1)
{
	return sqrt((double)((p1.x-p0.x)*(p1.x-p0.x)+(p1.y-p0.y)*(p1.y-p0.y)));
}

inline int vp(int x1,int y1,int x2,int y2)
{
	return x1*y2-x2*y1;
}

inline bool IsLeft(_point& p0,_point& p1,_point& p2)
{
	return vp(p1.x-p0.x,p1.y-p0.y,p2.x-p1.x,p2.y-p1.y)>=0;
}

bool cmp(_point p1,_point p2)
{
	if(p1.y==p2.y)
	{
		return p1.x<p2.x;
	}
	else
	{
		return p1.y<p2.y;
	}
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
		sort(p,p+n,cmp);
		chr[0]=0;
		chr[1]=1;
		topr=1;
		used[1]=true;
		for(i=2;i<n;++i)
		{
			while(!IsLeft(p[chr[topr-1]],p[chr[topr]],p[i]))
			{
				used[chr[topr]]=false;
				topr--;
			}
			used[i]=true;
			chr[++topr]=i;
		}
		chl[0]=n-1;
		chl[1]=n-2;
		topl=1;
		for(i=n-3;i>=0;--i)
		{
			if(used[i])
			{
				continue;
			}
			while(!IsLeft(p[chl[topl-1]],p[chl[topl]],p[i]))
			{
				topl--;
			}
			chl[++topl]=i;
		}
		sum=3.1415926*l*2;
		for(i=0;i<topr;++i)
		{
			sum+=GetDistance(p[chr[i]],p[chr[i+1]]);
		}
		for(i=0;i<topl;++i)
		{
			sum+=GetDistance(p[chl[i]],p[chl[i+1]]);
		}
		printf("%0.lf\n",sum);
	}
	return 0;
}
