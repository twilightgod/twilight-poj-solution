/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sumsets
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2549
*       ID             : 2549
*       Date           : 5/27/2009
*       Time           : 17:16:45
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<set>
using namespace std;

#define MAXN 1000
#define INF (-2147483648)

int n,ans;
set<int> s;
int a[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2549.txt","r",stdin);
#endif
	while(scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		s.clear();
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				s.insert(a[i]+a[j]);
				//cout<<a[i]+a[j]<<endl;
			}
		}
		ans=INF;
		//cout<<endl;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(i==j)
				{
					continue;
				}
				if(s.find(a[i]-a[j])!=s.end())
				{
					if(a[i]>ans)
					{
						ans=a[i];
					}
				}
			}
		}
		if(ans==INF)
		{
			printf("no solution\n");
		}
		else
		{
			printf("%d\n",ans);
		}
	}
	return 0;
}
