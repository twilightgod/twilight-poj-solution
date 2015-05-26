#include<iostream>
#include<vector>
using namespace std;

#define INF 0x7fffffff

#define MAXN 501

int F,P,C,M;
int dis[MAXN][MAXN];
int d[MAXN];
bool used[MAXN];

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d%d",&F,&P,&C,&M);
	for(int i=1;i<=F;++i)
	{
		for(int j=1;j<=F;++j)
		{
			if(i!=j)
			{
				dis[i][j]=INF;
			}
			else
			{
				dis[i][j]=0;
			}
		}
	}
	while(P--)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		if(d<dis[u][v])
		{
			dis[u][v]=dis[v][u]=d;
		}
	}
	/*
	for(int k=1;k<=F;++k)
	{
		for(int i=1;i<=F;++i)
		{
			for(int j=1;j<=F;++j)
			{
				if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	*/
	memset(used,false,sizeof(used));
	for(int i=1;i<=F;++i)
	{
		d[i]=INF;
	}
	d[1]=0;
	for(int i=0;i<F-1;++i)
	{
		int m=INF,u;
		for(int i=1;i<=F;++i)
		{
			if(!used[i]&&m>d[i])
			{
				m=d[i];
				u=i;
			}
		}
		used[u]=true;
		for(int v=1;v<=F;++v)
		{
			if(!used[v]&&dis[u][v]!=INF&&dis[u][v]+d[u]<d[v])
			{
				d[v]=dis[u][v]+d[u];
			}
		}
	}
	int ans=0;
	vector<int> cs;
	for(int i=1;i<=C;++i)
	{
		int u;
		scanf("%d",&u);
		if(d[u]<=M)
		{
			cs.push_back(i);
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<ans;++i)
	{
		printf("%d\n",cs[i]);
	}
	return 0;
}

