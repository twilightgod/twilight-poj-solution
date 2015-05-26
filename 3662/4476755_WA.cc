/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Telephone Lines
*       ID             : 3662
*       Date           : 12/10/2008
*       Time           : 22:22:51
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//BinarySearch
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAXN 1001
#define Inf 0x7fffffff

struct Edge
{
	int v,len;
};

vector<Edge> Link[MAXN];
queue<int> q;
int n,m,k,maxlen;
int d[MAXN];
bool used[MAXN];

void DFS(int u,int ans)
{
	int v;
	for (int i=0;i<Link[u].size();++i)
	{
		v=Link[u][i].v;
		if (!used[v]&&Link[u][i].len<=ans)
		{
			q.push(v);
			used[v]=true;
			d[v]=d[u];
			DFS(v,ans);
		}
	}
}

int Check(int ans)
{
	while (!q.empty())
	{
		q.pop();
	}
	memset(used,false,sizeof(used));
	memset(d,0,sizeof(d));
	q.push(1);
	used[1]=true;
	DFS(1,ans);
	while (!q.empty())
	{
		int u=q.front();
		if (u==n)
		{
			break;
		}
		q.pop();
		int v;
		for (int i=0;i<Link[u].size();++i)
		{
			v=Link[u][i].v;
			if (!used[v])
			{
				q.push(v);
				used[v]=true;
				d[v]=d[u]+1;
				DFS(v,ans);
			}
		}
	}
	return d[n];
}

int Solve()
{
	int l=0,r=maxlen;
	while (l<=r)
	{
		int m=(l+r)>>1;
		int t=Check(m);
		if (t==Inf)
		{
			return -1;
		}
		if (t>k)
		{
			l=m+1;
		}
		else
		{
			r=m-1;
		}
	}
	return l;
}

int main()
{
	//freopen("in_3662.txt","r",stdin);
//	freopen("phoneline.13.in","r",stdin);
	while (scanf("%d%d%d",&n,&m,&k)!=-1)
	{
		for (int i=1;i<=n;++i)
		{
			Link[i].clear();
		}
		maxlen=-Inf;
		for (int i=0;i<m;++i)
		{
			int u,v,len;
			scanf("%d%d%d",&u,&v,&len);
			Edge e;
			e.v=v;
			e.len=len;
			Link[u].push_back(e);
			e.v=u;
			Link[v].push_back(e);
			if (maxlen<len)
			{
				maxlen=len;
			}
		}
		printf("%d\n",Solve());
	}
	return 0;
}