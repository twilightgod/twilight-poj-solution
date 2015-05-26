/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Remmarguts' Date
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2449
*       ID             : 2449
*       Date           : 6/29/2009
*       Time           : 19:41:29
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<queue>
using namespace std;

#define MAXE 200000
#define MAXN 1001

#define INF 0x7fffffff

struct LNode
{
	int v,d,next;
};

int lin1[MAXN],lin2[MAXN];
LNode e[MAXE];

int n,m;
int s,t,k;
int cnt;

bool inq[MAXN];
int dis[MAXN];

deque<int> q;

struct PNode
{
	int g,u;
	PNode(int _g,int _u):g(_g),u(_u){}
	PNode(){}
};

inline bool operator <(PNode a,PNode b)
{
	return a.g+dis[a.u]>b.g+dis[b.u];
}

priority_queue<PNode> pq;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2449.txt","r",stdin);
#endif
	memset(lin1,-1,sizeof(lin1));
	memset(lin2,-1,sizeof(lin2));
	scanf("%d%d",&n,&m);
	cnt=0;
	while(m--)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		e[cnt].next=lin1[u];
		e[cnt].v=v;
		e[cnt].d=d;
		lin1[u]=cnt++;
		e[cnt].next=lin2[v];
		e[cnt].v=u;
		e[cnt].d=d;
		lin2[v]=cnt++;
	}
	scanf("%d%d%d",&s,&t,&k);

	//SPFA
	for(int i=1;i<=n;++i)
	{
		dis[i]=INF;
	}
	memset(inq,false,sizeof(inq));
	dis[t]=0;
	inq[t]=true;
	q.push_back(t);
	while(!q.empty())
	{
		int u=q.front();
		q.pop_front();
		inq[u]=false;
		for(int i=lin2[u];i!=-1;i=e[i].next)
		{
			int &v=e[i].v;
			int &d=e[i].d;
			if(dis[v]>dis[u]+d)
			{
				dis[v]=dis[u]+d;
				if(!inq[v])
				{
					if(q.empty()||dis[v]<dis[q.front()])
					{
						q.push_front(v);
					}
					else
					{
						q.push_back(v);
					}
					inq[v]=true;
				}
			}
		}
	}
	
	//No Answer
	if(dis[s]==INF)
	{
		printf("-1\n");
		return 0;
	}

	//AStar
	if(s==t) k++;
	cnt=0;
	pq.push(PNode(0,s));
	while(!pq.empty())
	{
		PNode now=pq.top();
		pq.pop();
		int &u=now.u;
		int &g=now.g;
		if(u==t)
		{
			cnt++;
			if(cnt==k)
			{
				printf("%d\n",g);
				return 0;
			}
		}
		for(int i=lin1[u];i!=-1;i=e[i].next)
		{
			int &v=e[i].v;
			int &d=e[i].d;
			pq.push(PNode(g+d,v));
		}
	}

	//No Answer
	printf("-1\n");

	return 0;
}