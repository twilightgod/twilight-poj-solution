/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Stockbroker Grapevine
*       ID             : 1125
*       Date           : 1/7/2009
*       Time           : 17:36:23
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 101
#define MAXINT 0x7ffffff

int n,m,v,best,best_i;
int d[MAXN][MAXN];

int main()
{
//	freopen("in_1125.txt","r",stdin);
	while (cin>>n&&n)
	{
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=n;++j)
			{
				d[i][j]=MAXINT;
			}
		}
		for (int i=1;i<=n;++i)
		{
			cin>>m;
			for (int j=0;j<m;++j)
			{
				cin>>v;
				cin>>d[i][v];
			}
		}
		for (int k=1;k<=n;++k)
		{
			for (int i=1;i<=n;++i)
			{
				for (int j=1;j<=n;++j)
				{
					if (d[i][k]!=MAXINT&&d[k][j]!=MAXINT&&d[i][k]+d[k][j]<d[i][j])
					{
						d[i][j]=d[i][k]+d[k][j];
					}
				}
			}
		}
		best=MAXINT;
		for (int i=1;i<=n;++i)
		{
			v=-1;
			for (int j=1;j<=n;++j)
			{
				if (i!=j&&d[i][j]>v)
				{
					v=d[i][j];
				}
			}
			if (best>v)
			{
				best=v;
				best_i=i;
			}
		}
		if (best==MAXINT)
		{
			cout<<"disjoint\n";
		}
		else
		{
			cout<<best_i<<" "<<best<<endl;
		}
	}
	return 0;
}
