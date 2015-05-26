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
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
using namespace std;

#define MAXN 1000
#define MAXR 10007

struct Node
{
	int a,b,s;
};

int n,ans;
vector<Node> hash[MAXR];
int num[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2549.txt","r",stdin);
#endif
	while(scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&num[i]);
		}
		sort(num,num+n,greater<int>());
		for(int i=0;i<MAXR;++i)
		{
			hash[i].clear();
		}
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				Node temp;
				temp.a=i;
				temp.b=j;
				temp.s=num[i]+num[j];
				int pos=abs(temp.s)%MAXR;
				hash[pos].push_back(temp);
			}
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(i!=j)
				{
					int s=num[i]-num[j];
					int pos=abs(s)%MAXR;
					for(int k=0;k<hash[pos].size();++k)
					{
						Node temp=hash[pos][k];
						if(i!=temp.a&&i!=temp.b&&j!=temp.a&&j!=temp.b&&temp.s==s)
						{
							ans=num[i];
							goto got;
						}
					}
				}
			}
		}
		printf("no solution\n");
		continue;
got:	printf("%d\n",ans);
	}
	return 0;
}
