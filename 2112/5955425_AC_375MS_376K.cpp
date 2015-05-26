/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Optimal Milking
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2112
*       ID             : 2112
*       Date           : 10/4/2009
*       Time           : 20:47:27
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

#define INF (-1u>>1)
#define MAXN 231

int k,c,m,n,l,r,mid;
int mat[MAXN][MAXN],match[MAXN];
bool mat2[MAXN][MAXN];
bool used[MAXN];

bool Aug(int u)
{
	for(int v=0;v<c;++v)
	{
		if(!used[v]&&mat2[u][v])
		{
			used[v]=true;
			if(match[v]==-1||Aug(match[v]))
			{
				match[v]=u;
				return true;
			}
		}
	}
	return false;
}

bool Check(int mid)
{
	int d[MAXN]={0};
	for(int i=0;i<k;++i)
	{
		for(int j=k;j<n;++j)
		{
			mat2[i][j-k]=(mat[i][j]<=mid);
			d[i]++;
		}
	}
	memset(match,-1,sizeof(match));
	int cnt=0;
	for(int i=0;i<c;++i)
	{
		for(int j=0;j<min(d[i],m);++j)
		{
			memset(used,false,sizeof(used));
			if(Aug(i))
			{
				if(++cnt==c)
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2112.txt","r",stdin);
#endif
	scanf("%d%d%d",&k,&c,&m);
	n=k+c;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			scanf("%d",&mat[i][j]);
			if(i!=j&&mat[i][j]==0)
			{
				mat[i][j]=INF;
			}
		}
	}
	for(int k=0;k<n;++k)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(mat[i][k]!=INF&&mat[k][j]!=INF&&mat[i][j]>mat[i][k]+mat[k][j])
				{
					mat[i][j]=mat[i][k]+mat[k][j];
				}
			}
		}
	}
	l=INF;
	r=-1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(mat[i][j]!=INF)
			{
				if(r<mat[i][j])
				{
					r=mat[i][j];
				}
				if(l>mat[i][j])
				{
					l=mat[i][j];
				}
			}
		}
	}
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(Check(mid))
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%d\n",l);
	return 0;
}
