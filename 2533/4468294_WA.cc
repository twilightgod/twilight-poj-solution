/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Longest Ordered Subsequence
*       ID             : 2533
*       Date           : 12/8/2008
*       Time           : 22:7:49
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 1000

int a[MAXN],f[MAXN];
int n,len;

int main()
{
	//freopen("in_2533.txt","r",stdin);
	while (cin>>n)
	{
		for (int i=0;i<n;++i)
		{
			cin>>a[i];
		}
		f[0]=0;
		len=1;
		for(int i=1;i<n;++i)
		{
			if (a[i]>f[len-1])
			{
				f[len++]=a[i];
			}
			else
			{
				int l=0,r=len-1;
				while (l<=r)
				{
					int m=(l+r)>>1;
					if (a[i]>f[m])
					{
						l=m+1;
					}
					else
					{
						r=m-1;
					}
				}
				f[l]=a[i];
			}
		}
		cout<<len<<endl;
	}
	return 0;
}
