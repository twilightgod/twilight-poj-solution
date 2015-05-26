/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Telephone Lines
*       ID             : 3662
*       Date           : 12/10/2008
*       Time           : 22:22:51
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//BinarySearch
//二分答案
//因为如果解m可以满足条件,那么任何n>m都可以满足条件
//解是单调的
//假设当前解为m,重新构图
//边权小于等于m设为0,大于m设为1
//BFS+DFS,O(|V|+|E|)计算从1到n的最短路
//即为使用长度超过m的边的条数,如果m<=k,则此解可行
//二分继续逼近答案
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAXN 1001
#define Inf 0x7fffffff

//边
struct Edge
{
	int v,len;
};

//邻接表
vector<Edge> Link[MAXN];
//队列
queue<int> q;
int n,m,k,maxlen;
//距离
int d[MAXN];
//顶点是否访问
bool used[MAXN];

//递归搜索,将与u相邻且未访问的顶点加入队列,且到他们的距离与到u相同
void DFS(int u,int ans)
{
	int v;
	for (int i=0;i<Link[u].size();++i)
	{
		v=Link[u][i].v;
		if (!used[v]&&Link[u][i].len<=ans)
		{
			q.push(v);
			used[v]=true;
			d[v]=d[u];
			DFS(v,ans);
		}
	}
}

//BFS,计算新图中1到n的最短路径
int Check(int ans)
{
	//清空队列
	while (!q.empty())
	{
		q.pop();
	}
	memset(used,false,sizeof(used));
	memset(d,0,sizeof(d));
	//初始将1放入队列
	q.push(1);
	used[1]=true;
	//到n距离无穷大
	d[n]=Inf;
	//从1扩展边权0的节点
	DFS(1,ans);
	//BFS
	while (!q.empty())
	{
		int u=q.front();
		if (u==n)
		{
			break;
		}
		q.pop();
		//当从队首取出u时,与u相邻的边权为0的点必然已经加入队列了
		//这时加入的点是边权为1的
		int v;
		for (int i=0;i<Link[u].size();++i)
		{
			v=Link[u][i].v;
			if (!used[v])
			{
				q.push(v);
				used[v]=true;
				//距离为到u距离+1
				d[v]=d[u]+1;
				//从v扩展边权0的节点
				DFS(v,ans);
			}
		}
	}
	return d[n];
}

//二分求解
int Solve()
{
	int l=0,r=maxlen;
	while (l<=r)
	{
		int m=(l+r)>>1;
		int t=Check(m);
		if (t==Inf)
		{
			return -1;
		}
		if (t>k)
		{
			l=m+1;
		}
		else
		{
			r=m-1;
		}
	}
	return l;
}

int main()
{
	while (scanf("%d%d%d",&n,&m,&k)!=-1)
	{
		for (int i=1;i<=n;++i)
		{
			Link[i].clear();
		}
		maxlen=-Inf;
		for (int i=0;i<m;++i)
		{
			int u,v,len;
			scanf("%d%d%d",&u,&v,&len);
			//建立邻接表
			Edge e;
			e.v=v;
			e.len=len;
			Link[u].push_back(e);
			e.v=u;
			Link[v].push_back(e);
			//记录最长边,作为二分上界
			if (maxlen<len)
			{
				maxlen=len;
			}
		}
		printf("%d\n",Solve());
	}
	return 0;
}