/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Lotto
*       ID             : 2245
*       Date           : 1/5/2009
*       Time           : 13:43:53
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 13

int a[MAXN];
int t[6];
int n;
bool first;

void DFS(int dep,int sum)
{
	if (sum==6)
	{
		for (int i=0;i<6;++i)
		{
			printf("%d",t[i]);
			if (i!=5)
			{
				printf(" ");
			}
		}
		printf("\n");
		return;
	}
	t[sum]=a[dep];
	DFS(dep+1,sum+1);
	if (n-dep+sum>6)
	{
		DFS(dep+1,sum);
	}
}

int main()
{
	//freopen("in_2245.txt","r",stdin);
	first=true;
	while (scanf("%d",&n)&&n)
	{
		if (first)
		{
			first=false;
		}
		else
		{
			printf("\n");
		}
		for (int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		DFS(0,0);
	}
	return 0;
}
