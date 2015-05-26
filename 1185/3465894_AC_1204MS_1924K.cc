#include<iostream>
using namespace std;
#define MAXN 10
#define MAXM 101
#define MAXA 60

bool p[MAXM][MAXA][MAXN];
int f[MAXM][MAXA][MAXA];
bool plan[MAXN];
int pn[MAXM];
int countt[MAXM][MAXA];
bool map[MAXM][MAXN];

int i,j,k,t,m,n,ans;
char c;

inline int max1(int x,int y)
{
	return x>y?x:y;
}

inline bool legal(int i1,int j1,int i2,int j2)
{
	for (int k=0;k<n;++k)
	{
		if (p[i1][j1][k]&&p[i2][j2][k])
		{
			return false;
		}
	}
	return true;
}

void dfs(int i,int j)
{
	if (j>=n)
	{
		for (int k=0;k<n;++k)
		{
			p[i][pn[i]][k]=plan[k];
			countt[i][pn[i]]+=plan[k];
		}
		pn[i]++;
		return;
	}
	if (map[i][j])
	{
		plan[j]=true;
		dfs(i,j+3);
	}
	plan[j]=false;
	dfs(i,j+1);
}

int main()
{
	//freopen("d:/in.txt","r",stdin);
	pn[0]=1;
	for (i=0;i<MAXN;++i)
	{
		p[0][0][i]=0;
	}
	while (cin>>m>>n)
	{
		memset(map,false,sizeof(map));
		memset(countt,0,sizeof(countt));
		memset(f,0,sizeof(f));
		for (i=1;i<=m;++i)
		{
			for (j=0;j<n;++j)
			{
				cin>>c;
				if (c=='P')
				{
					map[i][j]=true;
				}
			}
		}
		for (i=1;i<=m;++i)
		{
			memset(plan,false,sizeof(plan));
			pn[i]=0;
			dfs(i,0);
		}
		for (j=0;j<pn[1];++j)
		{
			f[1][j][0]=countt[1][j];
		}
		for (i=2;i<=m;++i)
		{
			for (j=0;j<pn[i];++j)
			{
				for (k=0;k<pn[i-1];++k)
				{
					if (legal(i,j,i-1,k))
					{
						for (t=0;t<pn[i-2];++t)
						{
							if (legal(i-1,k,i-2,t)&&legal(i,j,i-2,t))
							{
								f[i][j][k]=max1(f[i][j][k],f[i-1][k][t]+countt[i][j]);
							}
						}
					}
				}
			}
		}
		ans=0;
		for (j=0;j<pn[m];++j)
		{
			for (k=0;k<pn[m-1];++k)
			{
				ans=max1(ans,f[m][j][k]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
