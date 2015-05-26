/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Jamie's Contact Groups
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2289
*       ID             : 2289
*       Date           : 10/4/2009
*       Time           : 21:21:11
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
#include<sstream>
using namespace std;

#define INF (-1u>>1)
#define MAXN 1000
#define MAXM 500

int m,n,l,r,mid;
int match[MAXN][MAXM],mcnt[MAXM];
bool mat[MAXN][MAXM],mat2[MAXN][MAXM];
bool used[MAXM];
char buf[2000];
string str;
stringstream ss;

bool Aug(int u)
{
	for(int v=0;v<m;++v)
	{
		if(!used[v]&&mat[u][v])
		{
			used[v]=true;
			if(mcnt[v]<mid)
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

bool Check()
{
	memset(match,-1,sizeof(match));
	memset(mcnt,0,sizeof(mcnt));
	for(int i=0;i<n;++i)
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
	freopen("in_2289.txt","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)&&n)
	{
		memset(mat,false,sizeof(mat));
		for(int i=0;i<n;++i)
		{
			scanf("%s",&buf);
			gets(buf);
			str.assign(buf);
			ss.clear();
			ss<<str;
			int g;
			while(1)
			{
				ss>>g;
				mat[i][g]=true;
				if(ss.eof())
				{
					break;
				}
			}
		}
		l=1;
		r=n;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(Check())
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		printf("%d\n",l);
	}
	return 0;
}
