#include<iostream>
using namespace std;
#define MAXN 34000

bool prime[MAXN];
int p[MAXN];
int i,j,n,s,pn;

int main()
{
	//freopen("d:/in.txt","r",stdin);
	memset(prime,true,sizeof(prime));
	for(i=2;i<=182;++i)
	{
		if(prime[i])
		{
			for(j=i*i;j<=MAXN;j+=i)
			{
				prime[j]=false;
			}
		}
	}
	pn=0;
	for (i=2;i<=MAXN/2;++i)
	{
		if (prime[i])
		{
			p[pn++]=i;
		}
	}
	while(scanf("%d",&n)!=-1&&n)
	{
		s=0;
		for(i=0;i<=pn;++i)
		{
			if (p[i]>n>>1)
			{
				break;
			}
			if(prime[n-p[i]])
			{
				s++;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}