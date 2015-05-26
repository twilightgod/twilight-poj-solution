/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Fast Food
*       ID             : 1485
*       Date           : 4/6/2009
*       Time           : 22:4:6
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

#define MAXV 201
#define MAXP 31
#define MAXINT 0x7fffffff

int v,p,test,d;
int x[MAXV];
int cost[MAXV][MAXV];
int f[MAXP][MAXV];
int plan[MAXP][MAXV];

void PrintPlan(int i,int j)
{
	if(i==0)
	{
		return;
	}
	int k=plan[i][j];
	PrintPlan(i-1,k);
	printf("Depot %d at restaurant %d serves ",++d,(k+1+j)>>1);
	if(k+1==j)
	{
		printf("restaurant %d\n",k+1);
	}
	else
	{
		printf("restaurants %d to %d\n",k+1,j);
	}
}

int main()
{
	//freopen("in_1485.txt","r",stdin);
	//freopen("out_1019.txt","w",stdout);
	test=0;
	while(scanf("%d%d",&v,&p)&&v)
	{
		for(int i=1;i<=v;++i)
		{
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=v;++i)
		{
			for(int j=i;j<=v;++j)
			{
				int m=(i+j)>>1;
				cost[i][j]=0;
				for(int k=i;k<=j;++k)
				{
					cost[i][j]+=abs(x[k]-x[m]);
				}
			}
		}
		for(int i=1;i<=v;++i)
		{
			f[1][i]=cost[1][i];
		}
		for(int i=2;i<=p;++i)
		{
			for(int j=i;j<=v;++j)
			{
				f[i][j]=MAXINT;
				for(int k=i-1;k<j;++k)
				{
					if(f[i][j]>f[i-1][k]+cost[k+1][j])
					{
						f[i][j]=f[i-1][k]+cost[k+1][j];
						plan[i][j]=k;
					}
				}
			}
		}
		printf("Chain %d\n",++test);
		d=0;
		PrintPlan(p,v);
		printf("Total distance sum = %d\n\n",f[p][v]);
	}
	return 0;
}
