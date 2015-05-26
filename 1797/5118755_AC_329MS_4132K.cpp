/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Heavy Transportation
*       ID             : 1797
*       Date           : 5/8/2009
*       Time           : 20:28:47
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define INF -1000000
#define MAXN 1001

int n,m,t,ca;
int mat[MAXN][MAXN];
bool used[MAXN];
int dis[MAXN];

inline int max1(int a,int b)
{
	return a>b?a:b;
}

inline int min1(int a,int b)
{
	return a<b?a:b;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1797.txt","r",stdin);
#endif
	ca=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				mat[i][j]=INF;
			}
		}
		for(int i=0;i<m;++i)
		{
			int u,v,l;
			scanf("%d%d%d",&u,&v,&l);
			mat[u][v]=mat[v][u]=l;
		}
		fill_n(dis,n+1,INF);
		fill_n(used,n+1,false);
		dis[1]=-INF;
		for(int i=0;i<n-1;++i)
		{
			int m=INF,u;
			for(int i=1;i<=n;++i)
			{
				if(!used[i]&&dis[i]>m)
				{
					u=i;
					m=dis[i];
				}
			}
			if(u==n)
			{
				break;
			}
			used[u]=true;
			for(int v=1;v<=n;++v)
			{
				if(!used[v]&&/*mat[u][v]!=INF&&*/min1(dis[u],mat[u][v])>dis[v])
				{
					dis[v]=min1(dis[u],mat[u][v]);
				}
			}
		}
		printf("Scenario #%d:\n%d\n\n",++ca,dis[n]);
	}
	return 0;
}
