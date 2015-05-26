#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 10000

int n,i,j,t;
long long sum;
int a[MAXN];

int main()
{
	//freopen("d:/in.txt","r",stdin);
	while(cin>>n)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		sum=0;
		if(n==2)
		{
			sum=a[1]-a[0];
		}
		else
		{
			j=(n-1)<<1;
			for(i=0;i<n-1;++i)
			{
				sum+=j*(a[n-i-1]-a[i]);
				j-=2;
			}
		}
		printf("%I64d\n",sum);
	}
	return 0;
}
