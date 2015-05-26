#include<iostream>
using namespace std;

#define MAXN 2001

int p[MAXN];
int rank[MAXN];
int n,m,sum,test;

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
	//freopen("in_2492.txt","r",stdin);
	scanf("%d",&test);
	for(int t=1;t<=test;++t)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			MakeSet(i);
		}
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			Union(u,v);
		}
		sum=0;
		for(int i=1;i<=n;++i)
		{
			if(FindSet(i)==i)
			{
				sum++;
			}
		}
		printf("Scenario #%d:\n%s bugs found!\n\n",t,sum>1?"No suspicious":"Suspicious");
	}
	return 0;
}
