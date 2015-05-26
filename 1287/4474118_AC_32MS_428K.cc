/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Networking
*       ID             : 1287
*       Date           : 12/10/2008
*       Time           : 21:58:12
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//MST Kruskal
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 1001
#define MAXE 15000

struct Edge
{
	int u,v,len;
};

int p[MAXN];
Edge e[MAXE];
int rank[MAXN];
int n,m,maxlen,start;

inline void MakeSet(int x)
{
	p[x]=x;
	rank[x]=0;
}

int FindSet(int x)
{
	int r=x,t;
	while (r!=p[r])
	{
		r=p[r];
	}
	while (r!=x)
	{
		t=p[x];
		p[x]=r;
		x=t;
	}
	return r;
}

inline void Link(int x,int y)
{
	if (rank[x]>rank[y])
	{
		p[y]=x;
	}
	else
	{
		p[x]=y;
		if (rank[x]==rank[y])
		{
			rank[y]++;
		}
	}
}

inline void Union(int x,int y)
{
	Link(FindSet(x),FindSet(y));
}

inline bool cmp(Edge a,Edge b)
{
	return a.len<b.len;
}

int main()
{
	//freopen("in_1287.txt","r",stdin);
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&m);
		for (int i=0;i<m;++i)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].len);
		}
		for (int i=1;i<=n;++i)
		{
			MakeSet(i);
		}
		sort(e,e+m,cmp);
		maxlen=0;
		start=0;
		for (int k=0;k<n-1;++k)
		{
			for (int i=start;i<m;++i)
			{
				if (FindSet(e[i].u)!=FindSet(e[i].v))
				{
					Union(e[i].u,e[i].v);
					maxlen+=e[i].len;
					start=i+1;
					break;
				}
			}
		}
		printf("%d\n",maxlen);
	}
	return 0;
}

