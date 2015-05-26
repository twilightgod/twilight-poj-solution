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

int a[MAXL],ans[MAXN][MAXL];
int n,best;
bool hash[MAXN];

void DFS(int dep)
{
	if(dep>=ans[n][0])
	{
		return;
	}
	if(a[dep-1]==n)
	{
		ans[n][0]=dep;
		for(int i=0;i<ans[n][0];++i)
		{
			ans[n][i+1]=a[i];
		}
		return;
	}
	for(int i=0;i<dep;++i)
	{
		for(int j=i;j<dep;++j)
		{
			if(!hash[a[i]+a[j]]&&a[i]+a[j]>a[dep-1]&&a[i]+a[j]<=n&&
				(a[i]+a[j])*(1<<(ans[n][0]-dep))>=n)
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
		if(ans[n][0]==0)
		{
			memset(hash,false,sizeof(hash));
			memset(ans,0,sizeof(ans));
			a[0]=1;
			ans[n][0]=MAXL;
			DFS(1);
		}
		for(int i=1;i<=ans[n][0];++i)
		{
			printf("%d ",ans[n][i]);
		}
		printf("\n");
		//printf("%d\n",best);
	}
	return 0;
}

