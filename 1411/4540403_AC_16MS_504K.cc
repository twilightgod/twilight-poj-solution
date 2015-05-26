/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Calling Extraterrestrial Intelligence Again
*       ID             : 1411
*       Date           : 1/7/2009
*       Time           : 18:11:34
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
/*
O(sqrt(m)*log(n))
n : the number of primes in [1,100000]

con1:a/b<=p/q<=1
con2:p*q<=m
con3:p<=sqrt(m)

=>
p<=q

consider all the availble vaule of p,then
q<=m/p
q<=p*b/a
=>
q<=Min{m/p,p*b/a}
we can use binarysearch to find a prime 
which is closest to the limit
*/

#include<iostream>
#include<math.h>
using namespace std;

#define MAXN 100000
#define MAXP 10000

bool b[MAXN+1];
int prime[MAXP];
int n,m,aa,bb,p,q,best,best_p,best_q;

inline int min1(int x,int y)
{
	return x<y?x:y;
}

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
	return r;
}

int main()
{
	memset(b,true,sizeof(b));
	int sqrtmaxn=int(sqrt((double)MAXN));
	for (int i=2;i<=sqrtmaxn;++i)
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
	while (scanf("%d%d%d",&m,&aa,&bb)&&m)
	{
		best=0;
		int sqrtm=int(sqrt((double)m));
		for (int i=0;i<n&&prime[i]<=sqrtm;++i)
		{
			p=prime[i];
			q=prime[BinaySearch(min1(int((double)p*bb/aa),(double)m/p))];
			if (p*q>best)
			{
				best=p*q;
				best_p=p;
				best_q=q;
			}
		}
		printf("%d %d\n",best_p,best_q);
	}
	return 0;
}
