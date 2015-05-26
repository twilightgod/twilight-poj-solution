/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Roads in the North
*       ID             : 2631
*       Date           : 5/11/2009
*       Time           : 18:2:37
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAXN 10001

struct Node
{
	int v,d;
	Node(int _v,int _d)
	{
		v=_v;
		d=_d;
	}
};

int dis[MAXN];
int n;
vector<Node> l[MAXN];
queue<int> q;
char buf[20];

int BFS(int src,int &dst)
{
	memset(dis,-1,sizeof(dis));
	dis[src]=0;
	q.push(src);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<l[u].size();++i)
		{
			int v=l[u][i].v;
			if(dis[v]==-1)
			{
				dis[v]=dis[u]+l[u][i].d;
				q.push(v);
			}
		}
	}
	int m=0,p;
	for(int i=1;i<=n;++i)
	{
		if(dis[i]>m)
		{
			m=dis[i];
			p=i;
		}
	}
	dst=p;
	return m;
}

int main()
{
//	freopen("in_2631.txt","r",stdin);
	n=1;
	int u,v,d;
	while(scanf("%d%d%d",&u,&v,&d)!=EOF)
	{
		n++;
		l[u].push_back(Node(v,d));
		l[v].push_back(Node(u,d));
	}
	int p1,p2;
	BFS(1,p1);
	printf("%d\n",BFS(p1,p2));
	return 0;
}
