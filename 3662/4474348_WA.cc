/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Telephone Lines
*       ID             : 3662
*       Date           : 12/10/2008
*       Time           : 22:22:51
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//BinarySearch
#include<iostream>
using namespace std;

#define MAXN 1001
#define Inf 0x7fffffff

int w[MAXN][MAXN];
int n,m,k,maxlen;
int d[MAXN];
bool used[MAXN];
int arcs[MAXN][MAXN];

int Dijkstra(int ans)
{
	memset(used,false,sizeof(used));
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=n;++j)
		{
			if (w[i][j]<=ans)
			{
				arcs[i][j]=0;
			}
			else if (w[i][j]==Inf)
			{
				arcs[i][j]=Inf;
			}
			else
			{
				arcs[i][j]=1;
			}
		}
		d[i]=Inf;
	}
	d[1]=0;
	for (int i=0;i<n-1;++i)
	{
		int u,m=Inf;
		for (int i=1;i<=n;++i)
		{
			if (!used[i]&&m>d[i])
			{
				m=d[i];
				u=i;
			}
		}
		used[u]=true;
		if (u==n)
		{
			break;
		}
		for (int i=1;i<=n;++i)
		{
			if (!used[i]&&arcs[u][i]!=Inf&&arcs[u][i]+d[u]<d[i])
			{
				d[i]=arcs[u][i]+d[u];
			}
		}
	}
	return d[n];
}

int Solve()
{
	int l=0,r=maxlen;
	while (l<=r)
	{
		int m=(l+r)>>1;
		int t=Dijkstra(m);
		if (t==k)
		{
			return m;
		}
		else if (t>k)
		{
			l=m+1;
		}
		else
		{
			r=m-1;
		}
	}
}

int main()
{
	//freopen("in_3662.txt","r",stdin);
	while (scanf("%d%d%d",&n,&m,&k)!=-1)
	{
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=n;++j)
			{
				w[i][j]=Inf;
			}
		}
		maxlen=-Inf;
		for (int i=0;i<m;++i)
		{
			int u,v,len;
			scanf("%d%d%d",&u,&v,&len);
			w[u][v]=w[v][u]=len;
			if (maxlen<len)
			{
				maxlen=len;
			}
		}
		printf("%d\n",Solve());
	}
	return 0;
}