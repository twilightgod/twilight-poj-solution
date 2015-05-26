/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Jungle Roads
*       ID             : 1251
*       Date           : 5/12/2009
*       Time           : 17:4:0
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 26
#define INF 10000

int mat[MAXN][MAXN];
int dis[MAXN];
bool used[MAXN];
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1251.txt","r",stdin);
#endif
	while(cin>>n&&n)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				mat[i][j]=INF;
			}
		}
		for(int i=0;i<n-1;++i)
		{
			char ch;
			int cnt;
			cin>>ch>>cnt;
			for(int j=0;j<cnt;++j)
			{
				char ch1;
				int d;
				cin>>ch1>>d;
				mat[ch-'A'][ch1-'A']=mat[ch1-'A'][ch-'A']=d;
			}
		}
		fill_n(dis,n,INF);
		fill_n(used,n,false);
		dis[0]=0;
		for(int i=0;i<n-1;++i)
		{
			int u,m=INF;
			for(int j=0;j<n;++j)
			{
				if(!used[j]&&dis[j]<m)
				{
					u=j;
					m=dis[j];
				}
			}
			used[u]=true;
			for(int v=0;v<n;++v)
			{
				if(!used[v]&&mat[u][v]<dis[v])
				{
					dis[v]=mat[u][v];
				}
			}
		}
		int ans=0;
		for(int i=1;i<n;++i)
		{
			ans+=dis[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
