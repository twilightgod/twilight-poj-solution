/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Post Office
*       ID             : 1160
*       Date           : 4/6/2009
*       Time           : 20:32:38
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

#define MAXV 301
#define MAXP 31
#define MAXINT 0x7fffffff

int v,p;
int x[MAXV];
int cost[MAXV][MAXV];
int f[MAXP][MAXV];

int main()
{
	//freopen("in_1160.txt","r",stdin);
	while(cin>>v>>p)
	{
		for(int i=0;i<v;++i)
		{
			cin>>x[i];
		}
		for(int i=0;i<v;++i)
		{
			for(int j=i;j<v;++j)
			{
				int m=(i+j)>>1;
				cost[i][j]=0;
				for(int k=i;k<=j;++k)
				{
					cost[i][j]+=abs(x[k]-x[m]);
				}
			}
		}
		for(int i=0;i<v;++i)
		{
			f[1][i]=cost[0][i];
		}
		for(int i=2;i<=p;++i)
		{
			for(int j=i;j<v;++j)
			{
				f[i][j]=MAXINT;
				for(int k=i-1;k<j;++k)
				{
					if(f[i][j]>f[i-1][k]+cost[k+1][j])
					{
						f[i][j]=f[i-1][k]+cost[k+1][j];
					}
				}
			}
		}
		cout<<f[p][v-1]<<endl;
	}
	return 0;
}
