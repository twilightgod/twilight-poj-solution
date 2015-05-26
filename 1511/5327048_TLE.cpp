/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Invitation Cards
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1511
*       ID             : 1511_HeapDijkstra
*       Date           : 6/25/2009
*       Time           : 9:19:44
*       Computer Name  : EVERLASTING-PC
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

#define MAXN 1000001
#define INF64 0x7fffffffffffffffLL

typedef pair<int,long long> QNode;
typedef vector<QNode> LinkTable;
LinkTable lin1[MAXN],lin2[MAXN];

bool inq[MAXN];
long long dis[MAXN];

queue<int> q;

int n,m,t;

long long SPFA(LinkTable lin[])
{
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		dis[i]=INF64;
	}
	memset(inq,false,sizeof(inq));
	dis[1]=0;
	inq[1]=true;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		inq[u]=false;
		for(int i=0;i<lin[u].size();++i)
		{
			int &v=lin[u][i].first;
			long long &d=lin[u][i].second;
			if(dis[v]>dis[u]+d)
			{
				dis[v]=dis[u]+d;
				if(!inq[v])
				{
					inq[v]=true;
					q.push(v);
				}
			}
		}
	}
	for(int i=2;i<=n;++i)
	{
		ans+=dis[i];
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1511_HeapDijkstra.txt","r",stdin);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			lin1[i].clear();
			lin2[i].clear();
		}
		while(m--)
		{
			int u,v;
			long long d;
			scanf("%d%d%I64d",&u,&v,&d);
			lin1[u].push_back(QNode(v,d));
			lin2[v].push_back(QNode(u,d));
		}
		printf("%I64d\n",SPFA(lin1)+SPFA(lin2));
	}
	return 0;
}
