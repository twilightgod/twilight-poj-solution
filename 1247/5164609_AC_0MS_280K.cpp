/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Magnificent Meatballs
*       ID             : 1247
*       Date           : 5/16/2009
*       Time           : 9:1:18
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 31

int a[MAXN];
int n,ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1247.txt","r",stdin);
#endif
	while(cin>>n&&n)
	{
		int s=0;
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
			s+=a[i];
		}
		if(s&1)
		{
noa:		cout<<"No equal partitioning.\n";
			continue;
		}
		s>>=1;
		int c=0;
		ans=-1;
		for(int i=0;i<n;++i)
		{
			c+=a[i];
			if(c==s)
			{
				ans=i;
				break;
			}
		}
		if(ans==-1)
		{
			goto noa;
		}
		printf("Sam stops at position %d and Ella stops at position %d.\n",ans+1,ans+2);
	}
	return 0;
}
