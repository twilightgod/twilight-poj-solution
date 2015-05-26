/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Calling Extraterrestrial Intelligence Again
*       ID             : 1411
*       Date           : 1/7/2009
*       Time           : 18:11:34
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

#define MAXN 100000

bool b[MAXN+1];
int prime[MAXN];
int n,m,aa,bb,p,q,best,best_p,best_q;

int BinaySearch(int x)
{
	int l=0,r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (prime[mid]==x)
		{
			return mid;
		}
		else if (x>prime[mid])
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return l;
}

int main()
{
//	freopen("in_1411.txt","r",stdin);
	memset(b,true,sizeof(b));
	int t=int(sqrt((double)MAXN));
	for (int i=2;i<=t;++i)
	{
		if (b[i])
		{
			for (int j=i*i;j<=MAXN;j+=i)
			{
				b[j]=false;
			}
		}
	}
	n=0;
	for (int i=2;i<=MAXN;++i)
	{
		if (b[i])
		{
			prime[n++]=i;
		}
	}
	while (cin>>m>>aa>>bb&&m)
	{
		best=0;
		for (int i=0;i<n&&prime[i]<=m>>1;++i)
		{
			q=prime[i];
			for(int j=BinaySearch(aa*q/bb);prime[j]<=q&&j<m&&q*prime[j]<=m;++j)
			{
				p=prime[j];
				if (p*q>best)
				{
					best=p*q;
					best_p=p;
					best_q=q;
				}
			}
		}
		cout<<best_p<<' '<<best_q<<endl;
	}
	return 0;
}
