/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Wireless Network
*       ID             : 2236
*       Date           : 12/2/2008
*       Time           : 22:58:10
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//并查集
#include<iostream>
using namespace std;

#define MAXN 1001

struct Point
{
	int x,y;
};

Point po[MAXN];
int n,d,u,v;
int p[MAXN];
int rank[MAXN];
char cmd;
bool work[MAXN];

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

inline void Union(int x,int y)
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

inline void Link(int x,int y)
{
	Union(FindSet(x),FindSet(y));
}

int main()
{
	//freopen("in_2236.txt","r",stdin);
	scanf("%d%d",&n,&d);
	d*=d;
	for (int i=0;i<n;++i)
	{
		scanf("%d%d",&po[i].x,&po[i].y);
	}
	for (int i=0;i<n;++i)
	{
		p[i]=i;
		rank[i]=0;
		work[i]=false;
	}
	getchar();
	while (scanf("%c",&cmd)!=-1)
	{
		if (cmd=='O')
		{
			scanf("%d",&u);
			u--;
			for (int i=0;i<n;++i)
			{
				if (work[i]&&((po[i].x-po[u].x)*(po[i].x-po[u].x)+(po[i].y-po[u].y)*(po[i].y-po[u].y)<=d))
				{
					Link(u,i);
				}
			}
			work[u]=true;
		}
		else
		{
			scanf("%d%d",&u,&v);
			u--;v--;
			if (FindSet(u)==FindSet(v))
			{
				printf("SUCCESS\n");
			}
			else
			{
				printf("FAIL\n");
			}
		}
		getchar();
	}
	return 0;
}
