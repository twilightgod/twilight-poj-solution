/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Agri-Net
*       ID             : 1258
*       Date           : 4/25/2009
*       Time           : 22:27:28
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 100
#define MAXINT 0x7fffffff

int n,ans;
int w[MAXN][MAXN];
int dis[MAXN];
bool used[MAXN];

int main()
{
	//freopen("in_1258.txt","r",stdin);
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				cin>>w[i][j];
			}
			dis[i]=MAXINT;
		}
		memset(used,false,sizeof(used));
		dis[0]=0;
		for(int i=0;i<n-1;++i)
		{
			int u;
			int m=MAXINT;
			for(int v=0;v<n;++v)
			{
				if(!used[v]&&dis[v]<m)
				{
					m=dis[v];
					u=v;
				}
			}
			used[u]=true;
			for(int v=0;v<n;++v)
			{
				if(!used[v]&&dis[v]>w[u][v])
				{
					dis[v]=w[u][v];
				}
			}
		}
		ans=0;
		for(int i=1;i<n;++i)
		{
			ans+=dis[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
