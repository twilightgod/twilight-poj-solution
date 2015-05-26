/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : The Bottom of a Graph
*       ID             : 2553
*       Date           : 4/7/2009
*       Time           : 21:46:38
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define MAXN 5001

vector<int> link[MAXN],linkr[MAXN];
stack<int> s;
int n,m,ns;
int d[MAXN];
int scc[MAXN];
bool visited[MAXN];

void DFS(int u)
{
	visited[u]=true;
	for(int i=0;i<(int)link[u].size();++i)
	{
		int v=link[u][i];
		if(!visited[v])
		{
			DFS(v);
		}
	}
	s.push(u);
}

void DFSR(int u)
{
	scc[u]=ns;
	for(int i=0;i<(int)linkr[u].size();++i)
	{
		int v=linkr[u][i];
		if(scc[v]==0)
		{
			DFSR(v);
		}
	}
}

int main()
{
	//freopen("in_2553.txt","r",stdin);
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&m);
		for(int i=1;i<=n;++i)
		{
			link[i].clear();
			linkr[i].clear();
		}
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			link[u].push_back(v);
			linkr[v].push_back(u);
		}
		memset(visited,false,sizeof(visited));
		while(!s.empty())
		{
			s.pop();
		}
		for(int i=1;i<=n;++i)
		{
			if(!visited[i])
			{
				DFS(i);
			}
		}
		ns=0;
		memset(scc,0,sizeof(scc));
		while(!s.empty())
		{
			int u=s.top();
			s.pop();
			if(scc[u])
			{
				continue;
			}
			ns++;
			DFSR(u);
		}
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<(int)linkr[i].size();++j)
			{
				int v=linkr[i][j];
				if(scc[i]!=scc[v])
				{
					d[scc[v]]++;
				}
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(d[scc[i]]==0)
			{
				printf("%d ",i);
			}
		}
		printf("\n");
	}
	return 0;
}
