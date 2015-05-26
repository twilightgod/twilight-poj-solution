/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Japan
*       ID             : 3067
*       Date           : 12/2/2008
*       Time           : 17:15:59
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//树状数组
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXC 1000
#define MAXN 1000000

struct road
{
	int u,v;
};

long long C[MAXC+1];
road r[MAXN];
int n,m,k,t;
long long s;

inline int LowBit(int x)
{
	return x&(-x);
}

long long Sum(int i)
{
	long long s=0;
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

bool cmp(road r1,road r2)
{
	if(r1.u==r2.u)
	{
		return r1.v<r2.v;
	}
	else
	{
		return r1.u<r2.u;
	}
}

int main()
{
	//freopen("in_3067.txt","r",stdin);
	//freopen("h.in","r",stdin);
	scanf("%d",&t);
	for(int tt=0;tt<t;++tt)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<k;++i)
		{
			scanf("%d%d",&r[i].u,&r[i].v);
		}
		sort(r,r+k,cmp);
		//memset(C,0,sizeof(int)*(m+1));
		memset(C,0,sizeof(C));
		s=0;
		for(int i=0;i<k;++i)
		{
			s+=i-Sum(r[i].v);
			Modify(r[i].v,1,m);
		}
		printf("Test case %d: %I64d\n",tt+1,s);
	}
	return 0;
}
