/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Speed Reading
*       ID             : 3619
*       Date           : 5/8/2009
*       Time           : 22:26:16
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

int n,k,s,t,r,ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3619.txt","r",stdin);
#endif
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;++i)
	{
		scanf("%d%d%d",&s,&t,&r);
		int n0=n;
		int c=0;
		for(ans=1;;++ans)
		{
			if((n0-=s)<=0)
			{
				break;
			}
			if(++c==t)
			{
				ans+=r;
				c=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
