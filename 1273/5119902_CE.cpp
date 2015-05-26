/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Drainage Ditches
*       ID             : 1273
*       Date           : 5/8/2009
*       Time           : 23:1:28
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 300
#define inf 2000000000

int mat[MAXN][MAXN],flow[MAXN][MAXN],bf[MAXN][MAXN];
int n,m,s,t;

void _max_flow(int n,int mat[][MAXN],int source,int sink,int flow[][MAXN]){
	int pre[MAXN],que[MAXN],d[MAXN],p,q,t,i,j;
	for (;;){
		for (i=0;i<n;pre[i++]=0);
		pre[t=source]=source+1,d[t]=inf;
		for (p=q=0;p<=q&&!pre[sink];t=que[p++])
			for (i=0;i<n;i++)
				if (!pre[i]&&j=mat[t][i]-flow[t][i])
					pre[que[q++]=i]=t+1,d[i]=d[t]<j?d[t]:j;
				else if (!pre[i]&&j=flow[i][t])
					pre[que[q++]=i]=-t-1,d[i]=d[t]<j?d[t]:j;
		if (!pre[sink]) break;
		for (i=sink;i!=source;)
			if (pre[i]>0)
				flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
			else
				flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
	}	
}

int limit_max_flow(int n,int mat[][MAXN],int bf[][MAXN],int source,int sink,int flow[][MAXN]){
	int i,j,sk,ks;
	if (source==sink) return inf;
	for (mat[n][n+1]=mat[n+1][n]=mat[n][n]=mat[n+1][n+1]=i=0;i<n;i++)
		for (mat[n][i]=mat[i][n]=mat[n+1][i]=mat[i][n+1]=j=0;j<n;j++)
			mat[i][j]-=bf[i][j],mat[n][i]+=bf[j][i],mat[i][n+1]+=bf[i][j];
	sk=mat[source][sink],ks=mat[sink][source],mat[source][sink]=mat[sink][source]=inf;
	for (i=0;i<n+2;i++)
		for (j=0;j<n+2;flow[i][j++]=0);
	_max_flow(n+2,mat,n,n+1,flow);
	for (i=0;i<n;i++)
		if (flow[n][i]<mat[n][i]) return -1;
	flow[source][sink]=flow[sink][source]=0,mat[source][sink]=sk,mat[sink][source]=ks;
	_max_flow(n,mat,source,sink,flow);
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			mat[i][j]+=bf[i][j],flow[i][j]+=bf[i][j];
	for (j=i=0;i<n;j+=flow[source][i++]);
	return j;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1273.txt","r",stdin);
#endif
	while(scanf("%d%d",&m,&n))
	{
		memset(mat,0,sizeof(mat));
		memset(bf,0,sizeof(bf));
		for(int i=0;i<m;++i)
		{
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			mat[u][v]+=c;
		}
		printf("%d\n",limit_max_flow(n,mat,bf,1,n,flow));
	}
	return 0;
}
