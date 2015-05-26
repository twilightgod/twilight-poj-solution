/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : The Cow Lineup
*       ID             : 1989
*       Date           : 5/8/2009
*       Time           : 21:19:54
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 10001

int n,k,c,ans,t;
bool a[MAXN];

void _clear()
{
	c=0;
	memset(a,false,sizeof(a));
	ans++;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1989.txt","r",stdin);
#endif
	scanf("%d%d",&n,&k);
	ans=1;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&t);
		if(!a[t])
		{
			if(++c==k)
			{
				_clear();
				continue;
			}
			a[t]=true;
		}
	}
	printf("%d\n",ans);
	return 0;
}
