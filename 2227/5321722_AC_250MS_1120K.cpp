/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : The Wedding Juicer
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2227
*       ID             : 2227
*       Date           : 6/22/2009
*       Time           : 13:7:24
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<queue>
using namespace std;

#define MAXN 300

int map[MAXN][MAXN];
bool v[MAXN][MAXN];
bool inq[MAXN][MAXN];

struct PNode
{
	int x,y;
	PNode(int _x,int _y)
	{
		x=_x;
		y=_y;
	}
	PNode(){}
};

bool operator<(PNode a,PNode b)
{
	return map[a.x][a.y]>map[b.x][b.y];
}

int m,n,h;
long long ans;
priority_queue<PNode> pq;

void DFS(int x,int y)
{
	if(x<0||y<0||x>=m||y>=n)
	{
		return;
	}
	if(map[x][y]>h)
	{
		if(!inq[x][y])
		{
			pq.push(PNode(x,y));
			inq[x][y]=true;
		}
		return;
	}
	else if(!v[x][y])
	{
		v[x][y]=true;
		ans+=h-map[x][y];
		DFS(x+1,y);
		DFS(x-1,y);
		DFS(x,y+1);
		DFS(x,y-1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2227.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			scanf("%d",&map[i][j]);
		}
	}
	//inq==true表示已经在堆里
	memset(inq,false,sizeof(inq));
	//将最外圈入堆
	for(int i=0;i<m;++i)
	{
		pq.push(PNode(i,0));
		pq.push(PNode(i,n-1));
		inq[i][0]=inq[i][n-1]=true;
	}
	for(int j=1;j<n-1;++j)
	{
		pq.push(PNode(0,j));
		pq.push(PNode(m-1,j));
		inq[0][j]=inq[m-1][j]=true;
	}
	ans=0;
	//v==true表示已经访问过
	memset(v,false,sizeof(v));
	while(!pq.empty())
	{
		//取最小的
		PNode t=pq.top();
		pq.pop();
		h=map[t.x][t.y];
		DFS(t.x,t.y);
	}
	printf("%I64d\n",ans);
	return 0;
}
