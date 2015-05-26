/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Moving Tables
*       ID             : 1083
*       Date           : 5/21/2009
*       Time           : 17:29:56
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 200

int n,te;
int c[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1083.txt","r",stdin);
#endif
	cin>>te;
	while(te--)
	{
		cin>>n;
		memset(c,0,sizeof(c));
		while(n--)
		{
			int s,t;
			cin>>s>>t;
			s--;
			s>>=1;
			t--;
			t>>=1;
			if(s>t)
			{
				int k=s;
				s=t;
				t=k;
			}
			for(int i=s;i<=t;i++)
			{
				c[i]++;
			}
		}
		int ans=0;
		for(int i=0;i<MAXN;i++)
		{
			if(c[i]>ans)
			{
				ans=c[i];
			}
		}
		cout<<ans*10<<endl;
	}
	return 0;
}
