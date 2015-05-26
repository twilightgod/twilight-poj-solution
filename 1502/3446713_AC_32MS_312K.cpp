#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define MAXN 100
#define MAXINT 2147483647

int w[MAXN][MAXN];
int dis[MAXN];
bool use[MAXN];
int n,m,i,j,k;
string s;

int main()
{
	//freopen("d:/in.txt","r",stdin);
	for (i=0;i<MAXN;++i)
	{
		w[i][i]=0;
	}

	while (cin>>n)
	{
		for (i=0;i<n-1;++i)
		{
			for (j=0;j<i+1;++j)
			{
				cin>>s;
				if (s!="x")
				{
					stringstream ss(s);
					ss>>w[i+1][j];
					w[j][i+1]=w[i+1][j];
				}
				else
				{
					w[i+1][j]=w[j][i+1]=MAXINT;
				}
			}
		}
		for (i=0;i<n;++i)
		{
			dis[i]=MAXINT;
		}
		dis[0]=0;
		memset(use,false,sizeof(use));
		for (k=0;k<n;++k)
		{
			m=MAXINT;
			for (i=0;i<n;++i)
			{
				if (!use[i]&&dis[i]<m)
				{
					m=dis[i];
					j=i;
				}
			}
			use[j]=true;
			for (i=0;i<n;++i)
			{
				if (!use[i]&&w[j][i]!=MAXINT&&dis[j]+w[j][i]<dis[i])
				{
					dis[i]=dis[j]+w[j][i];
				}
			}
		}
		m=0;
		for (i=1;i<n;++i)
		{
			if (dis[i]>m)
			{
				m=dis[i];
			}
		}
		cout<<m<<endl;
	}
	return 0;
}