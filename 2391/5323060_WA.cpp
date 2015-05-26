/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Ombrophobic Bovines
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2391
*       ID             : 2391
*       Date           : 6/23/2009
*       Time           : 14:58:53
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

#define MAXN 402
#define INF 0x7fffffff
#define INF64 0x7fffffffffffffff

long long dis[MAXN][MAXN];
int a[MAXN],b[MAXN],mat[MAXN][MAXN],flow[MAXN][MAXN];
int n,p,cow;
long long l,r,m;

//求网络最大流,邻接表形式
int max_flow(int n,int mat[][MAXN],int source,int sink,int flow[][MAXN]){
	int pre[MAXN],que[MAXN],d[MAXN],p,q,t,i,j,r;
	vector<int> e[MAXN];	
	if (source==sink) return INF;
	for (i=0;i<n;i++)
		for (j=0;j<n;flow[i][j++]=0);
	//e[i]存放所有以i相邻的点,包括反向边!!!
	for (i=0;i<n;i++)
		for (e[i].clear(),j=0;j<n;j++)
			if (mat[i][j]) e[i].push_back(j),e[j].push_back(i);
	for (;;){
		for (i=0;i<n;pre[i++]=0);
		pre[t=source]=source+1,d[t]=INF;
		for (p=q=0;p<=q&&!pre[sink];t=que[p++])
			for (r=0;r<e[t].size();++r){
				i=e[t][r];			
				if (!pre[i]&&(j=mat[t][i]-flow[t][i]))
					pre[que[q++]=i]=t+1,d[i]=d[t]<j?d[t]:j;
				else if (!pre[i]&&(j=flow[i][t]))
					pre[que[q++]=i]=-t-1,d[i]=d[t]<j?d[t]:j;
			}
		if (!pre[sink]) break;
		for (i=sink;i!=source;)
			if (pre[i]>0)
				flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
			else
				flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
	}
	for (j=i=0;i<n;j+=flow[source][i++]);
	return j;
}

inline int min1(int &x,int &y)
{
	return x<y?x:y;
}

bool Check(long long m)
{
	//根据m进行构图
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			if(dis[i][j]<=m)
				mat[i][j+n]=min1(a[i],b[j]);
	return (max_flow(2*n+2,mat,0,2*n+1,flow)==cow)?true:false;
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("in_2391.txt","r",stdin);
	freopen("D:/Development/data/1115/ombro.2.in","r",stdin);
#endif
	scanf("%d%d",&n,&p);
	cow=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		cow+=a[i];
	}
	//邻接矩阵初始化
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i==j)
				dis[i][j]=0;
			else
				dis[i][j]=INF64;
	//读入边
	while(p--)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		if(dis[u][v]>d)
			dis[u][v]=dis[v][u]=d;
	}
	//Floyd
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(dis[i][k]!=INF64&&dis[k][j]!=INF64&&dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	/*
	//拆点后的邻接矩阵
	for(int i=0;i<=2*n+1;++i)
		for(int j=0;j<=2*n+1;++j)
			if(i==j)
				mat[i][j]=0;
			else
				mat[i][j]=INF;
				*/
	memset(mat,0,sizeof(mat));
	//增加源点,汇点
	for(int i=1;i<=n;++i)
	{
		if(a[i])
			mat[0][i]=a[i];
		if(b[i])
			mat[i+n][2*n+1]=b[i];
	}
	//计算二分的界
	l=0;
	r=-1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(dis[i][j]!=INF64&&r<dis[i][j])
				r=dis[i][j];
	int debug=0;
	//二分
	while(l<=r)
	{
		m=(l+r)>>1;
		if(Check(m))
			r=m-1;
		else
			l=m+1;
		debug++;
	}
	//cout<<debug<<endl;
	if(Check(l))
		printf("%I64d\n",l);
	else
		printf("-1\n");
	return 0;
}
