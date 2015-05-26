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
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

#define MAXN 30001
#define INF 0x7fffffff

typedef pair<int,int> QNode;
typedef vector<QNode> LinkTable;
LinkTable lin[MAXN];

bool inq[MAXN];
long long dis[MAXN];

queue<int> q;
stack<int> st;

int n,m,t;

int SPFA(LinkTable lin[])
{
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		dis[i]=INF;
	}
	memset(inq,false,sizeof(inq));
	dis[1]=0;
	inq[1]=true;
	//q.push(1);
	st.push(1);
	//while(!q.empty())
	while(!st.empty())
	{
		//int u=q.front();
		int u=st.top();
		//q.pop();
		st.pop();
		inq[u]=false;
		for(int i=0;i<lin[u].size();++i)
		{
			int &v=lin[u][i].first;
			int &d=lin[u][i].second;
			if(dis[v]>dis[u]+d)
			{
				dis[v]=dis[u]+d;
				if(!inq[v])
				{
					inq[v]=true;
					//q.push(v);
					st.push(v);
				}
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		lin[i].clear();
	}
	while(m--)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		lin[u].push_back(QNode(v,d));
	}
	printf("%d\n",SPFA(lin));
	return 0;
}
