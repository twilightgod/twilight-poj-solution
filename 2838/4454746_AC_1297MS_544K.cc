/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Graph Connectivity
*       ID             : 2838
*       Date           : 12/4/2008
*       Time           : 21:28:51
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 1001
#define MAXE 40002

struct Edge
{
	int v,next;
};

bool used[MAXN];
Edge e[MAXE];
int Link[MAXN];
int n,q;
int ec;
bool got;

void AddEdge(int u,int v)
{
	e[ec].next=Link[u];
	e[ec].v=v;
	Link[u]=ec;
	ec++;
}

void RemoveEdge(int u,int v)
{
	int pre=-2;
	for(int i=Link[u];i!=-1;i=e[i].next)
	{
		if (e[i].v==v)
		{
			if (pre==-2)
			{
				Link[u]=e[i].next;
			}
			else
			{
				e[pre].next=e[i].next;
			}
		}
		pre=i;
	}
}

// void DFS(int u,int goal)
// {
// 	if(u==goal)
// 	{
// 		got=true;
// 		return;
// 	}
// 	used[u]=true;
// 	for (int i=Link[u];i!=-1;i=e[i].next)
// 	{
// 		int v=e[i].v;
// 		if(!used[v])
// 		{
// 			DFS(v,goal);
// 		}
// 	}
// }
// 
// bool IsLink(int u,int v)
// {
// 	memset(used,false,sizeof(used));
// 	got=false;
// 	DFS(u,v);
// 	return got;
// }

bool IsLink(int u,int goal)
{
	memset(used,false,sizeof(used));
	used[u]=true;
	got=false;
	int h=-1,t=0;
	int q[MAXN];
	q[0]=u;
	while(h!=t)
	{
		int x=q[++h];
		if (x==goal)
		{
			got=true;
			goto ret;
		}
		for (int i=Link[x];i!=-1;i=e[i].next)
		{
			int v=e[i].v;
			if(!used[v])
			{
				q[++t]=v;
				used[v]=true;
			}
		}
	}
ret:return got;
}

int main()
{
	//freopen("in_2838.txt","r",stdin);
	while (scanf("%d%d",&n,&q)!=-1)
	{
		getchar();
		memset(Link,-1,sizeof(int)*(n+1));
		ec=0;
		for (int i=0;i<q;++i)
		{
			int u,v;
			char cmd;
			scanf("%c%d%d",&cmd,&u,&v);
			getchar();
			switch (cmd)
			{
			case 'I':
				AddEdge(u,v);
				AddEdge(v,u);
				break;
			case 'D':
				RemoveEdge(u,v);
				RemoveEdge(v,u);
				break;
			case 'Q':
				printf("%c\n",IsLink(u,v)?'Y':'N');
				break;
			}
		}
	}
	return 0;
}
