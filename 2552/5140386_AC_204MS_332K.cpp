#include<iostream>
#include<math.h>
using namespace std;

#define MAXN 33810
#define MAXP 3000

int p[MAXP];
bool hash[MAXN];
int n,pos,m;

int main()
{
	//freopen("in_1978.txt","r",stdin);
	memset(hash,true,sizeof(hash));
	pos=2;
	for(int i=0;i<MAXP;++i)
	{
		int base=pos,count=0;
		while(pos<MAXN)
		{
			pos++;
			if(hash[pos])
			{
				count++;
			}
			if(count==base)
			{
				hash[pos]=false;
				count=0;
				//break;
			}
		}
		pos=base+1;
		while(pos<MAXN&&!hash[pos])
		{
			pos++;
		}
	}
	m=0;
	for(int i=2;i<MAXN;++i)
	{
		if(hash[i])
		{
			p[m++]=i;
		}
	}
	//cout<<p[2999]<<endl;
	while(cin>>n&&n)
	{
		cout<<p[n-1]<<endl;
	}
	/*
	for(int i=0;i<20;++i)
	{
	cout<<i+1<<' '<<p[i]<<endl;
	}*/
	return 0;
}
