/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Alignment of the Planets
*       ID             : 3174
*       Date           : 12/20/2008
*       Time           : 21:58:46
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 770

int x[MAXN],y[MAXN];
int n,total;

int main()
{
	//freopen("in_3174.txt","r",stdin);
	while (scanf("%d",&n)!=-1)
	{
		for (int i=0;i<n;++i)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		total=0;
		for (int i=0;i<n;++i)
		{
			for (int j=i+1;j<n;++j)
			{
				for (int k=j+1;k<n;++k)
				{
					if ((x[k]-x[i])*(y[j]-y[i])-(x[j]-x[i])*(y[k]-y[i])==0)
					{
						total++;
					}
				}
			}
		}
		printf("%d\n",total);
	}
	return 0;
}
