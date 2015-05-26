/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : The Suspects
*       ID             : 1611
*       Date           : 12/6/2008
*       Time           : 22:17:53
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 30000

int p[MAXN];
int rank[MAXN];
int n,m,sum;

inline void MakeSet(int x)
{
	p[x]=x;
	rank[x]=0;
}

int FindSet(int x)
{
	int r=x,t;
	while (r!=p[r])
	{
		r=p[r];
	}
	while(r!=x)
	{
		t=p[x];
		p[x]=r;
		x=t;
	}
	return r;
}

void Link(int x,int y)
{
	if (rank[x]>rank[y])
	{
		p[y]=x;
	}
	else
	{
		p[x]=y;
		if (rank[x]==rank[y])
		{
			rank[y]++;
		}
	}
}

void Union(int x,int y)
{
	Link(FindSet(x),FindSet(y));
}

bool Request(int x,int y)
{
	return FindSet(x)==FindSet(y);
}

int main()
{
	//freopen("in_1611.txt","r",stdin);
	while(cin>>n>>m)
	{
		if (n==0&&m==0)
		{
			break;
		}
		for (int i=0;i<n;++i)
		{
			MakeSet(i);
		}
		for (int i=0;i<m;++i)
		{
			int k,h,t;
			cin>>k>>h;
			for (int j=0;j<k-1;++j)
			{
				cin>>t;
				Union(h,t);
			}
		}
		sum=0;
		for (int i=0;i<n;++i)
		{
			if (Request(0,i))
			{
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
