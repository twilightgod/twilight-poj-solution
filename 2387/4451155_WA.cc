/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Til the Cows Come Home
*       ID             : 2387
*       Date           : 12/3/2008
*       Time           : 22:14:30
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 1000
#define MAXINT 0x7fffffff

int n,t;
int w[MAXN][MAXN];
int d[MAXN];
bool used[MAXN];

int main()
{
	//freopen("in_2387.txt","r",stdin);
	while (cin>>t>>n)
	{
		for (int i=0;i<n;++i)
		{
			for (int j=0;j<n;++j)
			{
				w[i][j]=MAXINT;
			}
			d[i]=MAXINT;
			used[i]=false;
		}
		for (int i=0;i<t;++i)
		{
			int u,v,len;
			cin>>u>>v>>len;
			u--;v--;
			if(len<w[u][v])
			{
				w[u][v]=len;
			}
		}
		d[0]=0;
		for (int k=0;k<n-1;++k)
		{
			int u,m=MAXINT;
			for (int i=0;i<n;++i)
			{
				if (!used[i]&&d[i]<m)
				{
					m=d[i];
					u=i;
				}
			}
			if (u==n-1)
			{
				break;
			}
			used[u]=true;
			for (int v=0;v<n;++v)
			{
				if (!used[v]&&w[u][v]!=MAXINT&&d[u]+w[u][v]<d[v])
				{
					d[v]=d[u]+w[u][v];
				}
			}
		}
		cout<<d[n-1]<<endl;
	}
	return 0;
}
