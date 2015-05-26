#include<iostream>
using namespace std;
#define MAXN 102

int move[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int f[MAXN][MAXN];
int h[MAXN][MAXN];
int r,c,i,j,ans;

void dp(int x0,int y0)
{
	int x1,y1,i,m;
	m=0;
	for (i=0;i<4;++i)
	{
		x1=x0+move[i][0];
		y1=y0+move[i][1];
		if (h[x1][y1]>h[x0][y0])
		{
			if (f[x1][y1]==0)
			{
				dp(x1,y1);
			}
			if (f[x1][y1]>m)
			{
				m=f[x1][y1];
			}
		}
	}
	f[x0][y0]=m+1;
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while (cin>>r>>c)
	{
		memset(h,-1,sizeof(h));
		memset(f,0,sizeof(f));
		for (i=1;i<=r;++i)
		{
			for (j=1;j<=c;++j)
			{
				cin>>h[i][j];
			}
		}
		for (i=1;i<=r;++i)
		{
			for (j=1;j<=c;++j)
			{
				if (f[i][j]==0)
				{
					dp(i,j);
				}
			}
		}
		ans=0;
		for (i=1;i<=r;++i)
		{
			for (j=1;j<=c;++j)
			{
				if (f[i][j]>ans)
				{
					ans=f[i][j];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}