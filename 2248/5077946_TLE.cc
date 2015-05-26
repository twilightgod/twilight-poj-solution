/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Addition Chains
*       ID             : 2248
*       Date           : 5/1/2009
*       Time           : 13:10:57
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXL 11
#define MAXN 101

int a[MAXL],ans[MAXL];
int n,best;
bool hash[MAXN];

void DFS(int dep)
{
	if(dep>=best)
	{
		return;
	}
	if(a[dep-1]==n)
	{
		best=dep;
		for(int i=0;i<best;++i)
		{
			ans[i]=a[i];
		}
		return;
	}
	for(int i=0;i<dep;++i)
	{
		for(int j=i;j<dep;++j)
		{
			if(!hash[a[i]+a[j]]&&a[i]+a[j]>a[dep-1]&&a[i]+a[j]<=n)
			{
				hash[a[i]+a[j]]=true;
				a[dep]=a[i]+a[j];
				DFS(dep+1);
				hash[a[i]+a[j]]=false;
			}
		}
	}
}

int main()
{
	//freopen("in_2248.txt","r",stdin);
	while(scanf("%d",&n)&&n)
	{
		memset(hash,false,sizeof(hash));
		memset(a,0,sizeof(a));
		a[0]=1;
		best=MAXL;
		DFS(1);
		for(int i=0;i<best;++i)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
		//printf("%d\n",best);
	}
	return 0;
}
