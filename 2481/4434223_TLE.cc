/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Cows
*       ID             : 2481
*       Date           : 11/28/2008
*       Time           : 22:16:38
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 100001

struct Cow
{
	int s,e,index;
};

Cow cows[MAXN];
int C[MAXN];
int n;
int ans[MAXN];

inline bool cmp(Cow a,Cow b)
{
	return a.e==b.e?a.s>b.s:a.e>b.e;
}

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

int main()
{
	//freopen("in_2481.txt","r",stdin);
	cows[0].e=-1;
	while(cin>>n&&n)
	{
		memset(C,0,sizeof(C));
		for(int i=1;i<=n;++i)
		{
			cin>>cows[i].s>>cows[i].e;
			cows[i].s++;
			cows[i].e++;
			cows[i].index=i;
		}
		sort(cows+1,cows+n+1,cmp);
		for(int i=1;i<=n;++i)
		{
			if(cows[i].s==cows[i-1].s&&cows[i].e==cows[i-1].e)
			{
				ans[cows[i].index]=ans[cows[i-1].index];
			}
			else
			{
				ans[cows[i].index]=Sum(cows[i].s);
			}
			Modify(cows[i].s,1,cows[i].e);
		}
		for(int i=1;i<=n;++i)
		{
			if(i!=1)
			{
				cout<<' ';
			}
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}
