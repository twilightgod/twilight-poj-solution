/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Bridging signals
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1631
*       ID             : 1631_STL
*       Date           : 9/17/2009
*       Time           : 22:16:4
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 40001
#define INF 0x7fffffff

int n,t,ans;
int a[MAXN]/*,d[MAXN]*/,g[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1631_STL.txt","r",stdin);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		fill_n(g,n,INF);
		ans=1;
		for(int i=0;i<n;++i)
		{
			int j=lower_bound(g,g+n,a[i])-g;
			//d[i]=j+1;
			if(ans<j+1)
			{
				ans=j+1;
			}
			g[j]=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
