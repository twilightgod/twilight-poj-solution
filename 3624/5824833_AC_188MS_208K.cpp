/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Charm Bracelet
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3624
*       ID             : 3624
*       Date           : 9/7/2009
*       Time           : 18:6:9
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

#define MAXV 13000

int n,v;
int d,w;
int f[MAXV];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3624.txt","r",stdin);
#endif
	scanf("%d%d",&n,&v);
	memset(f,0,sizeof(f));
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&w,&d);
		for(int j=v;j>=w;--j)
		{
			if(f[j]<f[j-w]+d)
			{
				f[j]=f[j-w]+d;
			}
		}
	}
	printf("%d\n",f[v]);
	return 0;
}
