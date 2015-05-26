/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Coins
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1742
*       ID             : 1742
*       Date           : 9/7/2009
*       Time           : 17:41:20
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

#define MAXN 100001

int n,m; 
bool f[MAXN];
int used[MAXN],p[MAXN],q[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1742.txt","r",stdin);
#endif
	while(scanf("%d%d",&m,&n)&&m)   
	{   
		for(int i=0;i<m;i++)
		{
			scanf("%d",&p[i]);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&q[i]);
		}
		memset(f,false,sizeof(f));
		f[0]=true;   
		for(int i=0;i<m;i++)   
		{   
			memset(used,0,sizeof(used));
			for(int j=p[i];j<=n;j++) 
			{
				if(!f[j]&&f[j-p[i]]&&used[j-p[i]]<q[i])   
				{   
					f[j]=true;   
					used[j]=used[j-p[i]]+1;   
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			if(f[i])
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}   
	return 0;
}
