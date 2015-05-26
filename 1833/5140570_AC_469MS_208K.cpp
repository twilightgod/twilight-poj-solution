/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : 排列
*       ID             : 1833
*       Date           : 5/12/2009
*       Time           : 17:45:35
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 1024

int a[MAXN];
int n,k,t;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1833.txt","r",stdin);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<k;++i)
		{
			next_permutation(a,a+n);
		}
		for(int j=0;j<n;++j)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
	}
	return 0;
}
