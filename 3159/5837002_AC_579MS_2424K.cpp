/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Candies
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3159
*       ID             : 3159
*       Date           : 9/10/2009
*       Time           : 10:20:13
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

#define MAXN 30001
#define INF 0x7fffffff

struct QNode
{
	int v,d;
	int next;
};

int lin1[MAXN];
QNode e[150001];

bool used[MAXN];
int dis[MAXN];

typedef pair<int,int> PNode;
priority_queue<PNode> pq;

int n,m,t,cnt;

long long Dij(int lin[])
{
	for(int i=1;i<=n;++i)
	{
		dis[i]=INF;
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
	return dis[n];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3159.txt","r",stdin);
#endif

	{
		scanf("%d%d",&n,&m);
		memset(lin1,-1,sizeof(lin1));
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
		}
		printf("%d\n",Dij(lin1));
	}
	return 0;
}

