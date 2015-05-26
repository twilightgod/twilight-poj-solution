/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Stars
*       ID             : 2352
*       Date           : 12/2/2008
*       Time           : 13:8:22
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//树状数组
#include<iostream>
using namespace std;

#define MAXC 32000
#define MAXN 15000

int C[MAXC+1];
int Level[MAXN];
int r[MAXN],x[MAXN];
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

int main()
{
	//freopen("in_2352.txt","r",stdin);
	while(scanf("%d",&n)!=-1)
	{
		for (int i=0;i<n;++i)
		{
			scanf("%d%d",&x[i],&m);
			x[i]++;
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
