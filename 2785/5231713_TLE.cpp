/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : 4 Values whose Sum is 0
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2785
*       ID             : 2785
*       Date           : 5/27/2009
*       Time           : 20:55:23
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

#define MAXN 4000
#define MAXR 499979

vector<long long> hash[MAXR];
int n;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
long long ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2785.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			long long s=a[i]+b[j];
			int pos=abs(s)%MAXR;
			hash[pos].push_back(s);
		}
	}
	ans=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			long long s=-(c[i]+d[j]);
			int pos=abs(s)%MAXR;
			for(int k=0;k<hash[pos].size();++k)
			{
				if(s==hash[pos][k])
				{
					ans++;
				}
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
