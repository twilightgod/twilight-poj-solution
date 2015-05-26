/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Binary codes
*		Problem URL    : http://poj.org/problem?id=1147
*       ID             : 1147
*       Date           : 5/11/2011
*       Time           : 23:38:46
*       Computer Name  : 4EVER-PC
*		Wizard Version : 20110511P10
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

#define MAXN 3000

int n,cnt,now;
int num[MAXN];
int mapping[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1147.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",num+i);
	}
	
	cnt=0;
	for(int i=0;i<n;++i)
	{
		if(num[i]==0)
		{
			mapping[cnt++]=i;
		}
	}
	for(int i=0;i<n;++i)
	{
		if(num[i]==1)
		{
			mapping[cnt++]=i;
		}
	}

	now=mapping[0];
	for(int i=0;i<n;++i)
	{
		if(i)
		{
			printf(" ");
		}
		printf("%d",num[now]);
		now=mapping[now];
	}
	puts("");
	return 0;
}
