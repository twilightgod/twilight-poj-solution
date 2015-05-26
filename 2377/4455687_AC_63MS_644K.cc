/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Bad Cowtractors
*       ID             : 2377
*       Date           : 12/5/2008
*       Time           : 13:11:41
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 1001
#define MAXE 20000

struct Edge
{
	int u,v,len;
};

Edge e[MAXE];
int p[MAXN];
int rank[MAXN];
int n,m,ans,total;

bool cmp(Edge a,Edge b)
{
	return a.len>b.len;
}

inline void MakeSet(int x)
{
	p[x]=x;
	rank[x]=0;
}

int FindSet(int x)
{
	int r=x,t;
	while(r!=p[r])
	{
		r=p[r];
	}
	while(r!=x)
	{
		t=p[x];
		p[x]=r;
		x=t;
	}
	return r;
}

void Link(int x,int y)
{
	if(rank[x]>rank[y])
	{
		p[y]=x;
	}
	else
	{
		p[x]=y;
		if(rank[x]==rank[y])
		{
			rank[y]++;
		}
	}
}

void Union(int x,int y)
{
	Link(FindSet(x),FindSet(y));
}

int main()
{
	//freopen("in_2377.txt","r",stdin);
	while(scanf("%d%d",&n,&m)!=-1)
	{
		for (int i=1;i<=n;++i)
		{
			MakeSet(i);
		}
		for (int i=0;i<m;++i)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].len);
		}
		sort(e,e+m,cmp);
		ans=0;
		total=0;
		for (int i=0;i<m;++i)
		{
			if (FindSet(e[i].u)!=FindSet(e[i].v))
			{
				total++;
				ans+=e[i].len;
				Union(e[i].u,e[i].v);
				if (total==n-1)
				{
					break;
				}
			}
		}
		if (total!=n-1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",ans);
		}
	}
	return 0;
}
