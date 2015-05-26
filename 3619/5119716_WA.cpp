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
		if(s*t>=n)
		{
			ans=(int)ceil((double)n/s);
		}
		else
		{
			ans=(t+r)*(n/(s*t));
			ans+=(int)ceil(((n%(s*t))/(double)s));
			//ans+=int(((n%(s*t))/(double)s)+0.5);
		}
		printf("%d\n",ans);
	}
	return 0;
}
