#include<iostream>
using namespace std;

#define MAXL 10
#define MAXN 101

int a[MAXL];
int n,best;
bool hash[MAXL][MAXN];

void DFS(int dep)
{
	if(dep>=best)
	{
		return;
	}
	if(a[dep-1]==n)
	{
		best=dep;
		return;
	}
	for(int i=0;i<dep;++i)
	{
		for(int j=i;j<dep;++j)
		{
			if(!hash[dep][a[i]+a[j]]&&a[i]+a[j]>a[dep-1]&&a[i]+a[j]<=n)
			{
				hash[dep][a[i]+a[j]]=true;
				a[dep]=a[i]+a[j];
				DFS(dep+1);
			}
		}
	}
}

int main()
{
	//freopen("in_1045.txt","r",stdin);
	while(scanf("%d",&n)&&n)
	{
		memset(hash,false,sizeof(hash));
		a[0]=1;
		best=MAXL;
		DFS(1);
		for(int i=0;i<best;++i)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		//printf("%d\n",best);
	}
	return 0;
}

