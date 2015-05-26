/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Dice Stacking
*       ID             : 1972
*       Date           : 1/5/2009
*       Time           : 13:56:43
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 10000

const int opp[6]={5,3,4,1,2,0};
int best,n,test,tbest,bottom,tmax,last;
int d[MAXN][6];
int hash[MAXN][7];

int main()
{
	//freopen("in_1972.txt","r",stdin);
	scanf("%d",&test);
	while (test--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;++i)
		{
			for (int j=0;j<6;++j)
			{
				scanf("%d",&d[i][j]);
				hash[i][d[i][j]]=j;
			}
		}
		best=0;
		for (int k=1;k<=6;++k)
		{
			tbest=0;
			last=k;
			for (int i=0;i<n;++i)
			{
				bottom=hash[i][last];
				tmax=0;
				for (int j=0;j<6;++j)
				{
					if (j!=bottom&&j!=opp[bottom]&&tmax<d[i][j])
					{
						tmax=d[i][j];
					}
				}
				tbest+=tmax;
				last=d[i][opp[bottom]];
			}
			if (best<tbest)
			{
				best=tbest;
			}
		}
		printf("%d\n",best);
	}
	return 0;
}
