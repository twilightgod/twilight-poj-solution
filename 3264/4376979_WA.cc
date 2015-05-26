#include<iostream>
using namespace std;

#define MAXN 50000
#define MAXINT 50000
#define MININT -50000

struct Node
{
	int maxh,minh;
};

Node ITree[2*MAXN-1];
int num[MAXN];
int n,q,ql,qr;

inline int max(int a,int b)
{
	return a>b?a:b;
}

inline int min(int a,int b)
{
	return a<b?a:b;
}

inline int GetAdd(int l,int r)
{
	return (l+r)|(l!=r);
}

int BuildITree_Max(int l,int r)
{
	int add=GetAdd(l,r);
	if(l==r)
	{
		return ITree[add].maxh=num[l];
	}
	int m=(l+r)>>1;
	return ITree[add].maxh=max(BuildITree_Max(l,m),BuildITree_Max(m+1,r));
}

int BuildITree_Min(int l,int r)
{
	int add=GetAdd(l,r);
	if(l==r)
	{
		return ITree[add].minh=num[l];
	}
	int m=(l+r)>>1;
	return ITree[add].minh=min(BuildITree_Min(l,m),BuildITree_Min(m+1,r));
}

int QuestITree_Max(int l,int r)
{
	int add=GetAdd(l,r);
	if(l>=ql&&r<=qr)
	{
		return ITree[add].maxh;
	}
	if(l>qr||r<ql)
	{
		return MININT;
	}
	int m=(l+r)>>1;
	return max(QuestITree_Max(l,m),QuestITree_Max(m+1,r));
}

int QuestITree_Min(int l,int r)
{
	int add=GetAdd(l,r);
	if(l>=ql&&r<=qr)
	{
		return ITree[add].minh;
	}
	if(l>qr||r<ql)
	{
		return MAXINT;
	}
	int m=(l+r)>>1;
	return min(QuestITree_Min(l,m),QuestITree_Min(m+1,r));
}

int main()
{
	//freopen("in3264.in","r",stdin);
	while(scanf("%d%d",&n,&q)!=-1)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&num[i]);
		}
		BuildITree_Max(0,n-1);
		BuildITree_Min(0,n-1);
		for(int i=0;i<q;++i)
		{
			scanf("%d%d",&ql,&qr);
			ql--;qr--;
			printf("%d\n",QuestITree_Max(0,n-1)-QuestITree_Min(0,n-1));
		}
	}
	return 0;
}
