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
#define INF64 0x7fffffffffffffffLL

long long dis[MAXN][MAXN];
int a[MAXN],b[MAXN],mat[MAXN][MAXN],flow[MAXN][MAXN];
int n,p,cow;
long long l,r,m;
set<long long> dd;
vector<long long> f;

int max_flow(int n,int mat[][MAXN],vector<int> list[],int source,int sink,int flow[][MAXN]){
	int pre[MAXN],que[MAXN],d[MAXN],p,q,t,i,j,r;
	if (source==sink) return INF;
	for (i=0;i<n;i++)
		for (j=0;j<n;flow[i][j++]=0);
	for (;;){
		for (i=0;i<n;pre[i++]=0);
		pre[t=source]=source+1,d[t]=INF;
		for (p=q=0;p<=q&&!pre[sink];t=que[p++])
			for (r=0;r<list[t].size();++r){
				i=list[t][r];			
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
	memset(mat,0,sizeof(mat));
	vector<int> lis[MAXN];
	//增加源点,汇点
	for(int i=1;i<=n;++i)
	{
		if(a[i])
		{
			mat[0][i]=a[i];
			lis[0].push_back(i);
			lis[i].push_back(0);
		}
		if(b[i])
		{
			mat[i+n][2*n+1]=b[i];
			lis[i+n].push_back(2*n+1);
			lis[2*n+1].push_back(i+n);
		}
	}
	//根据m进行构图
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(dis[i][j]<=m)
			{
				mat[i][j+n]=min1(a[i],b[j]);
				if(mat[i][j+n])
				{
					lis[i].push_back(j+n);
					lis[j+n].push_back(i);
				}
			}
		}
	}
	return (max_flow(2*n+2,mat,lis,0,2*n+1,flow)==cow)?true:false;
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("in_2391.txt","r",stdin);
	freopen("D:/ACM_ICPC/1115/ombro.5.in","r",stdin);
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
	{
		for(int j=1;j<=n;++j)
		{
			if(i==j)
			{
				dis[i][j]=0;
			}
			else
			{
				dis[i][j]=INF64;
			}
		}
	}
	//读入边
	while(p--)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		if(dis[u][v]>d)
		{
			dis[u][v]=dis[v][u]=d;
		}
	}
	//Floyd
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(dis[i][k]!=INF64&&dis[k][j]!=INF64&&dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	//离散化最短路长度
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			if(dis[i][j]!=INF64)
			{
				dd.insert(dis[i][j]);
			}
		}
	}
	f.assign(dd.begin(),dd.end());
	l=0;
	r=f.size()-1;
	//二分
	while(l<=r)
	{
		m=(l+r)>>1;
		if(Check(f[m]))
		{
			r=m-1;
		}
		else
		{
			l=m+1;
		}
	}
	if(Check(f[l]))
	{
		printf("%I64d\n",f[l]);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
