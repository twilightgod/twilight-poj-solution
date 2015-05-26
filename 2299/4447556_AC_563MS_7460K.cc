/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Ultra-QuickSort
*       ID             : 2299
*       Date           : 12/2/2008
*       Time           : 17:24:14
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//树状数组 逆序对
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 500000

struct num
{
	int index,x;
};

int x[MAXN];
num sx[MAXN];
int C[MAXN+1];
int n;
long long s;

inline int LowBit(int x)
{
	return x&(-x);
}

int Sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=C[i];
		i-=LowBit(i);
	}
	return s;
}

void Modify(int i,int delta,int len)
{
	while(i<=len)
	{
		C[i]+=delta;
		i+=LowBit(i);
	}
}

bool cmp(num a,num b)
{
	if (a.x==b.x)
	{
		return a.index<b.index;
	}
	else
	{
		return a.x<b.x;
	}
}

int main()
{
	//freopen("in_2299.txt","r",stdin);
	while(scanf("%d",&n))
	{
		if(n==0)
		{
			break;
		}
		for(int i=0;i<n;++i)
		{
			scanf("%d",&sx[i].x);
			sx[i].index=i;
		}
		sort(sx,sx+n,cmp);
		for(int i=0;i<n;++i)
		{
			x[sx[i].index]=i+1;
		}
		memset(C,0,sizeof(int)*(n+1));
		s=0;
		/*
		//逆过来做,统计之前小于第i个的个数
		for(int i=n-1;i>=0;--i)
		{
			s+=Sum(x[i]);
			Modify(x[i],1,n);
		}
		*/
		//正序,统计之前大于第i个的个数
		for(int i=0;i<n;++i)
		{
			s+=i-Sum(x[i]);
			Modify(x[i],1,n);
		}
		printf("%I64d\n",s);
	}
	return 0;
}
