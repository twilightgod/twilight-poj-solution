/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Code
*       ID             : 1780
*       Date           : 4/8/2009
*       Time           : 17:34:35
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

#define MAXN 1000000
#define MAXD 10

bool link[MAXN][MAXD];
int n,m;

void DFS(int u)
{
	for(int i=0;i<MAXD;++i)
	{
		if(link[u][i])
		{
			link[u][i]=false;
			printf("%d",i);
			DFS((u*MAXD+i)%m);
		}
	}
}

int main()
{
//	freopen("in_1780.txt","r",stdin);
	while(scanf("%d",&n)&&n)
	{
		m=(int)pow((double)10,(double)(n-1));
		for(int i=0;i<m;++i)
		{
			fill_n(link[i],MAXD,true);
		}
		for(int i=0;i<n-1;++i)
		{
			printf("0");
		}
		DFS(0);
		printf("\n");
	}
	return 0;
}
