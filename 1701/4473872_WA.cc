#include<iostream>
using namespace std;

#define MAXN 10001

int s[MAXN];
int sum[MAXN];
__int64 down[MAXN];
__int64 up[MAXN];
int p[MAXN];
int n,a,b,test,best_i;
__int64 best;

int main()
{
	//freopen("in_1701.txt","r",stdin);
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&n,&a,&b);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&p[i]);
		}

		//calc down
		s[0]=0;
		for(int i=1;i<=n;++i)
		{
			s[i]=s[i-1]+p[i];
		}
		sum[0]=0;
		for(int i=1;i<=n;++i)
		{
			sum[i]=sum[i-1]+s[i];
		}
		down[1]=0;
		for(int i=2;i<=n;++i)
		{
			down[i]=down[i-1]+b*s[i-1]+sum[i-2];
		}
		
		//calc up
		s[n+1]=0;
		for(int i=n;i>0;--i)
		{
			s[i]=s[i+1]+p[i];
		}
		sum[n+1]=0;
		for(int i=n;i>0;--i)
		{
			sum[i]=sum[i+1]+s[i];
		}
		up[n]=0;
		for(int i=n-1;i>0;--i)
		{
			up[i]=up[i+1]+a*s[i+1]+sum[i+2];
		}
		
		//calc total
		best=4000000000;
		for(int i=1;i<=n;++i)
		{
			if(best>up[i]+down[i])
			{
				best=up[i]+down[i];
				best_i=i;
			}
		}
		printf("%d\n",best_i);
	}
	return 0;
}
