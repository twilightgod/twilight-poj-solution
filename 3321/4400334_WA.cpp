/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Apple Tree
*       ID             : 3321
*       Date           : 11/19/2008
*       Time           : 13:3:24
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 100001

struct Node
{
	int next;
	int v;
};

Node T[MAXN*2];
int Link[MAXN];
int low[MAXN];
int mapping[MAXN];
int c[MAXN];
bool used[MAXN];
bool apple[MAXN];
int m,n,i,u,v,ncount,ql,qr;
char ch;

inline int GetLoc(int l,int r)
{
	return (l+r)|(l!=r);
}

void Modify(int l,int r,int delta)
{
	if(l>u||r<u)
	{
		return;
	}
	int add=GetLoc(l,r);
	if(l<=u&&u<=r)
	{
		c[add]+=delta;
		if(l==r) return;
	}
	int m=(l+r)>>1;
	Modify(l,m,delta);
	Modify(m+1,r,delta);
}

int Sum(int l,int r)
{
	if(l>qr||r<ql)
	{
		return 0;
	}
	int add=GetLoc(l,r);
	if(ql<=l&&r<=qr)
	{
		return c[add];
	}
	int m=(l+r)>>1;
	return Sum(l,m)+Sum(m+1,r);
}

void DFS(int u)
{
	used[u]=true;
	low[u]=ncount;
	for(int i=Link[u];i!=-1;i=T[i].next)
	{
		int v=T[i].v;
		if(!used[v])
		{
			DFS(v);
		}
	}
	mapping[u]=ncount++;
}

int main()
{
	//freopen("in_3321.txt","r",stdin);
	while(scanf("%d",&n)!=-1)
	{
		memset(Link,-1,sizeof(int)*(n+1));
		memset(used,false,sizeof(bool)*(n+1));
		memset(apple,true,sizeof(bool)*(n+1));
		memset(c,0,sizeof(int)*(n+1));
		ncount=0;
		for(i=1;i<n;++i)
		{
			scanf("%d%d",&u,&v);
			T[ncount].v=v;
			T[ncount].next=Link[u];
			Link[u]=ncount;
			ncount++;
			T[ncount].v=u;
			T[ncount].next=Link[v];
			Link[v]=ncount;
			ncount++;
		}
		ncount=0;
		DFS(1);
		for(u=0;u<n;++u)
		{
			Modify(0,n-1,1);
		}
		scanf("%d",&m);
		for(i=0;i<m;++i)
		{
			getchar();
			scanf("%c%d",&ch,&u);
			if(ch=='Q')
			{
				ql=low[u],qr=mapping[u];
				printf("%d\n",Sum(0,n-1));
			}
			else
			{
				u=mapping[u];
				if(apple[u])
				{
					Modify(0,n-1,-1);
					apple[u]=false;
				}
				else
				{
					Modify(0,n-1,1);
					apple[u]=true;
				}
			}
		}
	}
	return 0;
}
