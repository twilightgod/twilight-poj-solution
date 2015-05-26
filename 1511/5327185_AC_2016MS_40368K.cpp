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

struct QNode
{
	int v,d;
	int next;
};

int lin1[MAXN],lin2[MAXN];
QNode e[2*MAXN];

bool used[MAXN];
long long dis[MAXN];

typedef pair<long long,int> PNode;
priority_queue<PNode> pq;

int n,m,t,cnt;

long long Dij(int lin[])
{
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		dis[i]=INF64;
	}
	dis[1]=0;
	pq.push(PNode(0,1));
	memset(used,false,sizeof(used));
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(used[u])
		{
			continue;
		}
		used[u]=true;
		for(int i=lin[u];i!=-1;i=e[i].next)
		{
			int &v=e[i].v;
			int &d=e[i].d;
			if(dis[v]>dis[u]+d)
			{
				dis[v]=dis[u]+d;
				pq.push(PNode(-dis[v],v));
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
		memset(lin1,-1,sizeof(lin1));
		memset(lin2,-1,sizeof(lin2));
		cnt=0;
		while(m--)
		{
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			e[cnt].next=lin1[u];
			e[cnt].d=d;
			e[cnt].v=v;
			lin1[u]=cnt;
			cnt++;
			e[cnt].next=lin2[v];
			e[cnt].d=d;
			e[cnt].v=u;
			lin2[v]=cnt;
			cnt++;
		}
		printf("%I64d\n",Dij(lin1)+Dij(lin2));
	}
	return 0;
}
