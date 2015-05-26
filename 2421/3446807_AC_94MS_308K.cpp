#include<iostream>
using namespace std;
#define MAXN 100
#define MAXINT 2147483647

int i,j,k,n,q,m;
int w[MAXN][MAXN];
int dis[MAXN];
bool use[MAXN];

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while (cin>>n)
	{
		for (i=0;i<n;++i)
		{
			for (j=0;j<n;++j)
			{
				cin>>w[i][j];
			}
		}
		for (i=0;i<n;++i)
		{
			dis[i]=MAXINT;
			use[i]=false;
		}
		cin>>q;
		for (i=0;i<q;++i)
		{
			cin>>j>>k;
			w[j-1][k-1]=w[k-1][j-1]=0;
		}
		dis[0]=0;
		while (1)
		{
			j=-1;
			m=MAXINT;
			for (i=0;i<n;++i)
			{
				if (!use[i]&&dis[i]<m)
				{
					m=dis[i];
					j=i;
				}
			}
			if (j==-1)
			{
				break;
			}
			use[j]=true;
			for (i=0;i<n;++i)
			{
				if (!use[i]&&w[j][i]<dis[i])
				{
					dis[i]=w[j][i];
				}
			}
		}
		m=0;
		for (i=0;i<n;++i)
		{
			m+=dis[i];
		}
		cout<<m<<endl;
	}
	return 0;
}