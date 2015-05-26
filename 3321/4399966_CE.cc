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

Node T[MAXN];
int Link[MAXN];
int mapping[MAXN];
int c[MAXN];
int low[MAXN];
bool used[MAXN];
bool apple[MAXN];
int m,n,i,u,v,count;
char ch;

inline int LowBit(int x)
{
	return x&(-x);
}

void Modify(int i,int delta)
{
	while(i<=n)
	{
		c[i]+=delta;
		i+=LowBit(i);
	}
}

int Sum(int i)
{
	int res=0;
	while(i>0)
	{
		res+=c[i];
		i-=LowBit(i);
	}
	return res;
}

void DFS(int u)
{
	used[u]=true;
	low[u]=count;
	for(int i=Link[u];i!=-1;i=T[i].next)
	{
		int v=T[i].v;
		if(!used[v])
		{
			DFS(v);
		}
	}
	mapping[u]=count++;
}

int main()
{
	//freopen("in_3321.txt","r",stdin);
	c[0]=0;
	while(scanf("%d",&n)!=-1)
	{
		memset(Link,-1,sizeof(int)*(n+1));
		memset(used,false,sizeof(bool)*(n+1));
		memset(apple,true,sizeof(bool)*(n+1));
		for(i=1;i<=n;++i)
		{
			c[i]=i-(i-LowBit(i)+1)+1;
		}
		count=0;
		for(i=1;i<n;++i)
		{
			scanf("%d%d",&u,&v);
			T[count].v=v;
			T[count].next=Link[u];
			Link[u]=count;
			count++;
		}
		count=1;
		DFS(1);
		scanf("%d",&m);
		for(i=0;i<m;++i)
		{
			getchar();
			scanf("%c%d",&ch,&u);
			if(ch=='Q')
			{
				printf("%d\n",Sum(mapping[u])-Sum(low[u]-1));
			}
			else
			{
				u=mapping[u];
				if(apple[u])
				{
					Modify(u,-1);
					apple[u]=false;
				}
				else
				{
					Modify(u,1);
					apple[u]=true;
				}
			}
		}
	}
	return 0;
}
