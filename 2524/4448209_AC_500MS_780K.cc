/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Ubiquitous Religions
*       ID             : 2524
*       Date           : 12/2/2008
*       Time           : 22:29:42
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//并查集
#include<iostream>
using namespace std;

#define MAXN 50000

int p[MAXN];
int rank[MAXN];
int n,m,sum,test;

inline void MakeSet(int x)
{
	p[x]=x;
	rank[x]=0;
}

inline void Link(int x,int y)
{
	if(rank[x]>rank[y])
		p[y]=x;
	else
	{
		p[x]=y;
		if (rank[x]==rank[y])
		{
			rank[y]++;
		}
	}
}

int FindSet(int x)
{
	int r=x,t;
	while(r!=p[r]) 
		r=p[r];
	while (r!=x)
	{
		t=p[x];
		p[x]=r;
		x=t;
	}
	return r;
}

inline void Union(int x,int y)
{
	Link(FindSet(x),FindSet(y));
}

int main()
{
	//freopen("in_2524.txt","r",stdin);
	test=0;
	while (scanf("%d%d",&n,&m))
	{
		if (n==0&&m==0)
		{
			break;
		}
		for (int i=0;i<n;++i)
		{
			MakeSet(i);
		}
		for (int i=0;i<m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			Union(x-1,y-1);
		}
		sum=0;
		for (int i=0;i<n;++i)
		{
			if (i==p[i])
			{
				sum++;
			}
		}
		printf("Case %d: %d\n",++test,sum);
	}
	return 0;
}
