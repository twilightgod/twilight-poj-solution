#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define MAXN 100
#define MAXINT 2147483647

int w[MAXN][MAXN];
int dis[MAXN][MAXN];
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
			for (j=0;j<n;++j)
			{
				dis[i][j]=w[i][j];
			}
		}
		for (k=0;k<n;++k)
		{
			for (i=0;i<n;++i)
			{
				for (j=0;j<n;++j)
				{
					if(dis[i][k]!=MAXINT&&dis[k][j]!=MAXINT&&dis[i][k]+dis[k][j]<dis[i][j])
					{
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		m=0;
		for (i=1;i<n;++i)
		{
			if (dis[0][i]>m)
			{
				m=dis[0][i];
			}
		}
		cout<<m<<endl;
	}
	return 0;
}