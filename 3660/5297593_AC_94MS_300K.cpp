#include<iostream>
using namespace std;

#define MAXN 101

int n,m,ans;
bool dis[MAXN][MAXN];
int d1[MAXN],d2[MAXN];

int main()
{
	//freopen("in.txt","r",stdin);
	cin>>n>>m;
	//memset(mat,false,sizeof(mat));
	memset(dis,false,sizeof(dis));
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		dis[a][b]=true;
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(dis[i][k]&&dis[k][j])
				{
					dis[i][j]=true;
				}
			}
		}
	}
	memset(d1,0,sizeof(d1));
	memset(d2,0,sizeof(d2));
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(dis[i][j])
			{
				d1[i]++;
				d2[j]++;
			}
		}
	}
	ans=0;
	for(int i=1;i<=n;++i)
	{
		if(d1[i]+d2[i]==n-1)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

