#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

#define MAXN 1299710

bool p[MAXN];
int num[MAXN];
int n,np,lower;

bool BinarySearch(int x,int& lower)
{
	int l=0,r=np-1,m;
	while(l<=r)
	{
		m=(l+r)>>1;
		if(num[m]==x)
		{
			return true;
		}
		if(x>num[m])
		{
			l=m+1;
		}
		else
		{
			r=m-1;
		}
	}
	lower=r;
	return false;
}

int main()
{
	//freopen("in_3518.txt","r",stdin);
	memset(p,true,sizeof(p));
	np=0;
	int sq=int(ceil(sqrt(double(MAXN-1))));
	for(int i=2;i<=sq;++i)
	{
		if(p[i])
		{
			for(int j=i*i;j<MAXN;j+=i)
			{
				p[j]=false;
			}
		}
	}
	for(int i=2;i<MAXN;++i)
	{
		if(p[i])
		{
			num[np++]=i;
		}
	}
	while(scanf("%d",&n)&&n)
	{
		if(n==1||BinarySearch(n,lower))
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n",num[lower+1]-num[lower]);
		}
	}
	return 0;
}
