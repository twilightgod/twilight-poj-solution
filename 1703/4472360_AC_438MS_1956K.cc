/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Find them, Catch them
*       ID             : 1703
*       Date           : 12/10/2008
*       Time           : 12:43:24
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 100001

int p[MAXN*2];
int rank[MAXN*2];
int n,m,test;

inline int op(int x)
{
	return x+n;
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

bool Request(int x,int y)
{
	return FindSet(x)==FindSet(y);
}

int main()
{
	//freopen("in_1703.txt","r",stdin);
	scanf("%d",&test);
	for(int t=1;t<=test;++t)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n*2;++i)
		{
			MakeSet(i);
		}
		for(int i=0;i<m;++i)
		{
			int u,v;
			char cmd;
			getchar();
			scanf("%c%d%d",&cmd,&u,&v);
			if (cmd=='D')
			{
				Union(u,op(v));
				Union(op(u),v);
			}
			else
			{
				if (Request(u,v))
				{
					printf("In the same gang.\n");
				}
				else if(Request(u,op(v)))
				{
					printf("In different gangs.\n");
				}
				else
				{
					printf("Not sure yet.\n");
				}
			}
		}
	}
	return 0;
}
