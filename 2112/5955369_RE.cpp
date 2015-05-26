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
#define MAXN 201

int k,c,m,n,l,r,mid;
int mat[MAXN][MAXN],match[MAXN][20],mcnt[MAXN];
bool mat2[MAXN][MAXN];
bool used[MAXN];

bool Aug(int u)
{
	for(int v=0;v<k;++v)
	{
		if(!used[v]&&mat2[u][v])
		{
			used[v]=true;
			if(mcnt[v]<m)
			{
				match[v][mcnt[v]++]=u;
				return true;
			}
			for(int kk=0;kk<mcnt[v];++kk)
			{
				if(Aug(match[v][kk]))
				{
					match[v][kk]=u;
					return true;
				}
			}
		}
	}
	return false;
}

bool Check(int mid)
{
	for(int i=k;i<n;++i)
	{
		for(int j=0;j<k;++j)
		{
			mat2[i-k][j]=(mat[i][j]<=mid);
		}
	}
	memset(match,-1,sizeof(match));
	memset(mcnt,0,sizeof(mcnt));
	for(int i=0;i<c;++i)
	{
		memset(used,false,sizeof(used));
		if(!Aug(i))
		{
			return false;
		}
	}
	return true;
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
