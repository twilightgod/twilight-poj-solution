/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sumsets
*       ID             : 2229
*       Date           : 5/15/2009
*       Time           : 16:30:53
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 1000001
#define M 1000000000

int n;
int f[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2229.txt","r",stdin);
#endif
	while(cin>>n)
	{
		f[1]=1;
		f[2]=2;
		for(int i=3;i<=n;++i)
		{
			if(i&1)
			{
				f[i]=f[i-1];
			}
			else
			{
				f[i]=f[i-2]+f[i>>1];
				if(f[i]>M)
				{
					f[i]-=M;
				}
			}
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
