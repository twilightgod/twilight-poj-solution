#include<iostream>
using namespace std;
#define MAXN 101

int w[MAXN][MAXN];
int sum[MAXN][MAXN];
int i,j,k,best,n,f;

int main()
{
	//freopen("d:/in.txt","r",stdin);
	for (j=0;j<MAXN;++j)
	{
		sum[0][j]=0;
	}
	while (cin>>n)
	{
		for (i=1;i<=n;++i)
		{
			for (j=1;j<=n;++j)
			{
				cin>>w[i][j];
			}
		}
		for (j=1;j<=n;++j)
		{
			sum[1][j]=w[1][j];
			for (i=2;i<=n;++i)
			{
				sum[i][j]=sum[i-1][j]+w[i][j];
			}
		}
		best=0;
		for (i=1;i<=n;++i)
		{
			for (k=i;k<=n;++k)
			{
				f=0;
				for (j=1;j<=n;++j)
				{
					if (f+sum[k][j]-sum[i-1][j]<0)
					{
						f=0;
					}
					else
					{
						f+=sum[k][j]-sum[i-1][j];
						if (f>best)
						{
							best=f;
						}
					}
				}
			}
		}
		cout<<best<<endl;
	}
	return 0;
}