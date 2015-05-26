#include<iostream>
#include<math.h>
using namespace std;

#define MAXN 501
#define MAXE ((MAXN*(MAXN-1))/2)
#define Inf 1e20

struct Edge
{
	int u,v,len;
};

double w[MAXN][MAXN];
bool used[MAXN];
double d[MAXN];
Edge e[MAXE];

int m,n,ca,ans0,ans1;
bool anstype;
double ans;

int main()
{
	//freopen("in_1135.txt","r",stdin);
	ca=0;
	while(scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0)
		{
			break;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				w[i][j]=Inf;
			}
			d[i]=Inf;
		}
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].len);
			w[e[i].u][e[i].v]=w[e[i].v][e[i].u]=e[i].len;
		}
		d[1]=0;
		memset(used,false,sizeof(used));
		for(int k=0;k<n-1;++k)
		{
			double t=Inf;
			int u=0;
			for(int v=1;v<=n;++v)
			{
				if(!used[v]&&d[v]<t)
				{
					u=v;
					t=d[v];
				}
			}
			used[u]=true;
			for(int v=1;v<=n;++v)
			{
				if(!used[v]&&w[u][v]!=Inf&&d[v]>w[u][v]+d[u])
				{
					d[v]=w[u][v]+d[u];
				}
			}
		}

		anstype=true;
		double t=-Inf;
		for(int i=1;i<=n;++i)
		{
			if(t<d[i])
			{
				t=d[i];
				ans0=i;
			}
		}

		for(int i=0;i<m;++i)
		{
			int u=e[i].u,v=e[i].v,len=e[i].len;
			if(fabs(d[u]-d[v])!=len)
			{
				if(d[u]<d[v])
				{
					swap(u,v);
				}
				double temp=d[u]+(w[u][v]-(d[u]-d[v]))/2;
				if(temp>t)
				{
					anstype=false;
					if(u>v)
					{
						swap(u,v);
					}
					ans0=u;
					ans1=v;
					t=temp;
				}
			}
		}

		printf("System #%d\nThe last domino falls after %.1lf seconds, ",++ca,t);
		if(anstype)
		{
			printf("at key domino %d.\n",ans0);
		}
		else
		{
			printf("between key dominoes %d and %d.\n\n",ans0,ans1);
		}
	}
	return 0;
}
