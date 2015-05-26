/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Invitation Cards
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1511
*       ID             : 1511_SPFA_NOSTL1
*       Date           : 6/25/2009
*       Time           : 9:28:14
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

bool inq[MAXN];
long long dis[MAXN];

queue<int> q;

int n,m,t,cnt;

long long SPFA(int lin[])
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
		for(int i=lin[u];i!=-1;i=e[i].next)
		{
			int &v=e[i].v;
			int &d=e[i].d;
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
	freopen("in_1511_SPFA_NOSTL1.txt","r",stdin);
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
		printf("%I64d\n",SPFA(lin1)+SPFA(lin2));
	}
	return 0;
}