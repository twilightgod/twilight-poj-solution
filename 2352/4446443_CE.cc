/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Stars
*       ID             : 2352
*       Date           : 12/2/2008
*       Time           : 13:8:22
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//树状数组+离散化
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXC 15000
#define MAXN 15000

struct Point
{
	int index,x;
};

int C[MAXC+1];
int Level[MAXN];
int r[MAXN],x[MAXN];
Point p[MAXN];
int n,m;

inline int LowBit(int x)
{
	return x&(-x);
}

int Sum(int i)
{
	int s=0;
	while (i>0)
	{
		s+=C[i];
		i-=LowBit(i);
	}
	return s;
}

void Modify(int i,int delta,int len)
{
	while (i<=len)
	{
		C[i]+=delta;
		i+=LowBit(i);
	}
}

bool cmp(Point &a,Point &b)
{
	if (a.x==b.x)
	{
		return a.index<b.index;
	}
	else
	{
		return a.x<b.x;
	}
}

int main()
{
	//freopen("in_2352.txt","r",stdin);
	while(scanf("%d",&n)!=-1)
	{
		for (int i=0;i<n;++i)
		{
			scanf("%d%d",&x[i],&m);
			p[i].x=x[i];
			p[i].index=i;
		}
		sort(p,p+n,cmp);
		for (int i=0;i<n;++i)
		{
			x[p[i].index]=i+1;
		}
		r[n-1]=x[n-1];
		m=0;
		for (int i=n-2;i>=0;--i)
		{
			r[i]=x[i]>r[i+1]?x[i]:r[i+1];
			if (m<x[i])
			{
				m=x[i];
			}
		}
		memset(C,0,sizeof(int)*(m+1));
		memset(Level,0,sizeof(int)*n);
		for (int i=0;i<n;++i)
		{
			Level[Sum(x[i])]++;
			Modify(x[i],1,r[i]);
		}
		for (int i=0;i<n;++i)
		{
			printf("%d\n",Level[i]);
		}
	}
	return 0;
}
