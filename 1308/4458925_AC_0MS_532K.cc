/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Is It A Tree?
*       ID             : 1308
*       Date           : 12/5/2008
*       Time           : 23:24:40
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 100001

int p[MAXN];
int rank[MAXN];
bool used[MAXN];
int u,v,ca;
int maxn,minn;
bool tree;

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
	Link(FindSet(x),FindSet(y));
}

int main()
{
	//freopen("in_1308.txt","r",stdin);
	ca=0;
	while (1)
	{
		ca++;
		minn=MAXN+1;
		maxn=-1;
		tree=true;
		memset(used,false,sizeof(used));
		while (1)
		{
			int u,v;
			cin>>u>>v;
			if (u==0&&v==0)
			{
				break;
			}
			if (u==-1&&v==-1)
			{
				goto ret;
			}
			if (u<minn)
			{
				minn=u;
			}
			if (u>maxn)
			{
				maxn=u;
			}
			if (v<minn)
			{
				minn=v;
			}
			if (v>maxn)
			{
				maxn=v;
			}
			if (!used[u])
			{
				used[u]=true;
				MakeSet(u);
			}
			if (!used[v])
			{
				used[v]=true;
				MakeSet(v);
			}
			if (FindSet(u)==FindSet(v))
			{
				tree=false;
			}
			else
			{
				Union(u,v);
			}
		}
		int sum=0;
		for (int i=minn;i<=maxn;++i)
		{
			if (used[i]&&p[i]==i)
			{
				sum++;
			}
			if (sum>1)
			{
				tree=false;
				break;
			}
		}
		printf("Case %d is %sa tree.\n",ca,(tree?"":"not "));
	}
ret:return 0;
}
