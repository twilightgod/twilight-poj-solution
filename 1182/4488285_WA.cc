/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : 食物链
*       ID             : 1182
*       Date           : 12/15/2008
*       Time           : 22:14:30
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 50001

int p[MAXN*3];
int rank[MAXN*3];
int n,k,ans;

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
	while (r!=x)
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

//x吃的集合
inline int Master(int x)
{
	return x+n;
}
//吃x的集合
inline int Eat(int x)
{
	return x+(n<<1);
}

int main()
{
	//freopen("in_1182.txt","r",stdin);
	while (scanf("%d%d",&n,&k)!=-1)
	{
		for (int i=1;i<=n*3;++i)
		{
			MakeSet(i);
		}
		ans=0;
		for (int i=0;i<k;++i)
		{
			int cmd,x,y;
			scanf("%d%d%d",&cmd,&x,&y);
			if (x>n||y>n)
			{
				ans++;
				continue;
			}
			if (cmd==1)
			{
				if (Request(x,Master(y))||Request(x,Eat(y)))
				{
					ans++;
					continue;
				}
				else
				{
					Union(x,y);
				}
			}
			else
			{
				if (x==y||Request(x,y)||Request(x,Master(y)))
				{
					ans++;
					continue;
				}
				else
				{
					Union(y,Master(x));
					Union(x,Eat(y));
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
