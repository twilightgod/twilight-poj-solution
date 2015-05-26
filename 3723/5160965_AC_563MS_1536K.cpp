/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Conscription
*       ID             : 3723
*       Date           : 5/15/2009
*       Time           : 17:0:51
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 10000
#define MAXE 50000

struct Edge
{
	int u,v,d;
};

int p[MAXN*2];
int rank[MAXN*2];
Edge e[MAXE*2];
int t,n,m,r,ans;
bool done;

bool cmp(Edge a,Edge b)
{
	return a.d>b.d;
}

int Find(int x)
{
	int r=x;
	while(r!=p[r])
	{
		r=p[r];
	}
	while(r!=x)
	{
		int t=p[x];
		p[x]=r;
		x=t;
	}
	return r;
}

void Link(int x,int y)
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

void Union(int x,int y)
{
	Link(Find(x),Find(y));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3723.txt","r",stdin);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&r);
		for(int i=0;i<r;++i)
		{
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			e[i<<1].u=e[1+(i<<1)].v=u;
			e[i<<1].v=e[1+(i<<1)].u=v+n;
			e[i<<1].d=e[1+(i<<1)].d=d;
		}
		sort(e,e+(r<<1),cmp);
		for(int i=0;i<n+m;++i)
		{
			p[i]=i;
			rank[i]=0;
		}
		int pe=0;
		done=false;
		ans=0;
		for(int i=0;i<n+m-1;++i)
		{
			while(Find(e[pe].u)==Find(e[pe].v))
			{
				pe++;
				if(pe>=(r<<1))
				{
					done=true;
					break;
				}
			}
			if(done)
			{
				break;
			}
			Union(e[pe].u,e[pe].v);
			ans+=e[pe].d;
			pe++;
		}
		printf("%d\n",10000*(m+n)-ans);
	}
	return 0;
}
