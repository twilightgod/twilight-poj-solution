#include<iostream>
using namespace std;

#define MAXN 2001

int p[MAXN];
int rank[MAXN];
int n,m,test;
bool god;

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

bool Request(int x,int y)
{
	return FindSet(x)==FindSet(y);
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
		god=false;
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(Request(u,v))
			{
				god=true;
			}
			Union(u,v);
		}
		printf("Scenario #%d:\n%s bugs found!\n\n",t,!god?"No suspicious":"Suspicious");
	}
	return 0;
}
