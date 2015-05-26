#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

#define MAXN 5000
#define MAXP 670

int n,np,ans;
int p[MAXP];
int sum[MAXP];

int main()
{
	//freopen("in_2739.txt","r",stdin);
	np=1;
	p[0]=sum[0]=0;
	p[1]=sum[1]=2;
	for(int i=3;i<MAXN;i+=2)
	{
		int sqrti=(int)sqrt((double)i);
		bool flag=true;
		for(int j=1;p[j]<=sqrti;++j)
		{
			if(i%p[j]==0)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			p[++np]=i;
			sum[np]=sum[np-1]+i;
		}
	}
	while(scanf("%d",&n)&&n)
	{
		ans=0;
		for(int i=1;i<=np;++i)
		{
			for(int j=i;j<=np;++j)
			{
				int t=sum[j]-sum[i-1];
				if(t>n)
				{
					break;
				}
				if(t==n)
				{
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
