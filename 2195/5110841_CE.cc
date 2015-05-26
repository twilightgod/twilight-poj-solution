/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Going Home
*       ID             : 2195
*       Date           : 5/7/2009
*       Time           : 7:9:43
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<vector>
#include"math.h"
using namespace std;

#define MAXN 1002
#define inf 1000000000

struct Coo
{
	int x,y;
	Coo (int _x,int _y)
	{
		x=_x;
		y=_y;
	}
};

vector<Coo> man,house;
int mat[MAXN][MAXN],cost[MAXN][MAXN],flow[MAXN][MAXN];
int n,m,s,t;

//求网络最小费用最大流,邻接阵形式
//返回最大流量,flow返回每条边的流量,netcost返回总费用
//传入网络节点数n,容量mat,单位费用cost,源点source,汇点sink
int min_cost_max_flow(int n,int mat[][MAXN],int cost[][MAXN],int source,int sink,int flow[][MAXN],int& netcost){
	int pre[MAXN],min[MAXN],d[MAXN],i,j,t,tag;
	if (source==sink) return inf;
	for (i=0;i<n;i++)
		for (j=0;j<n;flow[i][j++]=0);
	for (netcost=0;;){
		for (i=0;i<n;i++)
			pre[i]=0,min[i]=inf;
		//通过bellman_ford寻找最短路，即最小费用可改进路
		for (pre[source]=source+1,min[source]=0,d[source]=inf,tag=1;tag;)
			for (tag=t=0;t<n;t++)
				if (d[t])
					for (i=0;i<n;i++)
						if (j=mat[t][i]-flow[t][i]&&min[t]+cost[t][i]<min[i])
							tag=1,min[i]=min[t]+cost[t][i],pre[i]=t+1,d[i]=d[t]<j?d[t]:j;
						else if (j=flow[i][t]&&min[t]<inf&&min[t]-cost[i][t]<min[i])
							tag=1,min[i]=min[t]-cost[i][t],pre[i]=-t-1,d[i]=d[t]<j?d[t]:j;
		if (!pre[sink])	break;
		for (netcost+=min[sink]*d[i=sink];i!=source;)
			if (pre[i]>0)
				flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
			else
				flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
	}
	for (j=i=0;i<n;j+=flow[source][i++]);
	return j;
}

int main()
{
//	freopen("in_2195.txt","r",stdin);
	while(cin>>m>>n&&m)
	{
		man.clear();
		house.clear();
		getchar();
		for(int i=0;i<m;++i,getchar())
		{
			for(int j=0;j<n;++j)
			{
				switch(getchar())
				{
				case 'm':man.push_back(Coo(i,j));break;
				case 'H':house.push_back(Coo(i,j));break;
				}
			}
		}
		s=man.size()+house.size();
		t=s+1;
		memset(mat,0,sizeof(mat));
		memset(cost,0,sizeof(cost));
		for(int i=0;i<man.size();++i)
		{
			for(int j=0;j<house.size();++j)
			{
				cost[i][j+man.size()]=abs(man[i].x-house[j].x)+abs(man[i].y-house[j].y);
				mat[i][j+man.size()]=1;
			}
		}
		for(int i=0;i<man.size();++i)
		{
			cost[s][i]=0;
			mat[s][i]=1;
		}
		for(int i=0;i<house.size();++i)
		{
			cost[i+man.size()][t]=0;
			mat[i+man.size()][t]=1;
		}
		int ans=0;
		min_cost_max_flow(t+1,mat,cost,s,t,flow,ans);
		cout<<ans<<endl;
	}
	return 0;
}
