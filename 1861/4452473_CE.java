/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Network
*       ID             : 1861
*       Date           : 12/4/2008
*       Time           : 13:45:23
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
	bool used;
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
	//freopen("in_1861.txt","r",stdin);
	while(scanf("%d%d",&n,&m)!=-1)
	{
		for (int i=0;i<m;++i)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].len);
			e[i].used=false;
		}
		for (int i=1;i<=n;++i)
		{
			MakeSet(i);
		}
		sort(e,e+m,cmp);
		maxlen=-1;
		start=0;
		for (int k=0;k<n-1;++k)
		{
			for (int i=start;i<m;++i)
			{
				if (FindSet(e[i].u)!=FindSet(e[i].v))
				{
					Union(e[i].u,e[i].v);
					if (maxlen<e[i].len)
					{
						maxlen=e[i].len;
					}
					e[i].used=true;
					start=i+1;
					break;
				}
			}
		}
		printf("%d\n%d\n",maxlen,n-1);
		for (int i=0;i<m;++i)
		{
			if (e[i].used)
			{
				printf("%d %d\n",e[i].u,e[i].v);
			}
		}
	}
	return 0;
}
