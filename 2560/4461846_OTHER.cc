/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Freckles
*       ID             : 2560
*       Date           : 12/7/2008
*       Time           : 9:22:47
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//Prim
#include<iostream>
#include<math.h>
using namespace std;

#define MAXN 101
#define MAXD 1e20

struct Point
{
	double x,y;
};

double w[MAXN][MAXN];
double d[MAXN];
bool used[MAXN];
Point p[MAXN];
int n;
double sum;

int main()
{
	//freopen("in_2560.txt","r",stdin);
	while (cin>>n)
	{
		for (int i=0;i<n;++i)
		{
			cin>>p[i].x>>p[i].y;
			d[i]=MAXD;
		}
		memset(used,false,sizeof(used));
		for (int i=0;i<n;++i)
		{
			for (int j=0;j<n;++j)
			{
				w[i][j]=sqrt(double((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)));
			}
		}
		d[0]=0;
		sum=0;
		for (int k=0;k<n;++k)
		{
			int u;
			double m=MAXD;
			for (int i=0;i<n;++i)
			{
				if (!used[i]&&m>d[i])
				{
					m=d[i];
					u=i;
				}
			}
			used[u]=true;
			sum+=d[u];
			for (int i=0;i<n;++i)
			{
				if (!used[i]&&w[u][i]<d[i])
				{
					d[i]=w[u][i];
				}
			}
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}
