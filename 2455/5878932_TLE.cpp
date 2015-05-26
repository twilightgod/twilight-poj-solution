/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Secret Milking Machine
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2455
*       ID             : 2455
*       Date           : 9/19/2009
*       Time           : 9:42:59
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include <iostream>   
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
int DES;
int N;
int BE;
#define VS 205   
#define ES 200001
#define inf 2147483647   
int tc=0;
int pre[ES];
int tail[VS];
int len[ES];
int to[ES];
int op[ES];
int es=0;

struct EDGE
{
	int u,v,d;
} edge[ES];

int h[VS];
int vh[VS];
int n, m,t;
int Ex[ES];
int Ey[ES];
int Edges[ES];
bool Vis[VS];
int EdgeNum=0;
void init() {
	es=0;
	memset(pre, 255, sizeof(pre));
	memset(tail, 255, sizeof(tail));
	memset(Vis, false, sizeof(Vis));
	DES=n;
	N=n;
	BE=1;
}

int addedge(int x, int y, int w) {
	pre[++es]=tail[x];
	tail[x]=es;
	len[es]=w;
	to[es]=y;
	return es;
}
void add2edge(int x, int y, int w) {
	int o=addedge(x, y, w);
	int p=addedge(y, x, 0);
	op[o]=p;
	op[p]=o;
}

void add2edge_b(int x, int y, int w) {
	int o=addedge(x, y, w);
	int p=addedge(y, x, w);
	op[o]=p;
	op[p]=o;
}

int aug(int u, int t) {
	if (u==DES)
		return t;
	int l=t, d;
	int minh=N-1;
	for (int p=tail[u]; p>0; p=pre[p]) {
		if (len[p]>0) {
			if (h[to[p]]+1==h[u]) {
				d=aug(to[p], l<len[p] ? l : len[p]);
				len[p]-=d;
				len[op[p]]+=d;
				l-=d;
				if (h[BE]>=N)
					return t-l;
				if (l==0)
					break;
			}
			if (h[to[p]]<minh)
				minh=h[to[p]];
		}

	}
	if (l==t) {
		vh[h[u]]--;
		if (vh[h[u]]==0)
			h[BE]=N;
		h[u]=minh+1;
		vh[h[u]]++;
	}
	return t-l;
}
int maxflow() {
	memset(h, 0, sizeof(h));
	memset(vh, 0, sizeof(vh));
	vh[0]=N;
	int ans=0;
	while (h[BE]<N) ans+=aug(BE, inf);

	return ans;
}
/*
int input(int t) {

	for (int i=1; i<=m; i++) {
		int x, y, w;
		cin>>x>>y>>w;
		add2edge(x, y, w);
		Ex[i]=x;
		Ey[i]=y;
	}
	int X, W;
	int sum=0;
	for (int i=1; i<=t; i++) {
		cin>>X>>W;
		sum+=W;
		add2edge(X, DES, W);
	}
	return sum;

}

void dfs(int x) {
	for (int p=tail[x]; p>0; p=pre[p]) {
		if (!Vis[to[p]]&&len[p]>0) {
			Vis[to[p]]=true;
			dfs(to[p]);
		}
	}
}
void OutputEdges() {
	EdgeNum=0;
	for (int i=1; i<=m; i++) {
		if (Vis[Ex[i]]&&!Vis[Ey[i]]) {
			Edges[++EdgeNum]=i;
		}
	}
	cout<<EdgeNum<<" ";
	for (int i=1; i<=EdgeNum; i++) {
		cout<<Edges[i]<<" ";
	}
	cout<<endl;
}
*/

bool Check(int mid)
{
	init();
	/*
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(mat[i][j]<=m)
			{
				add2edge_b(i, j, 1);
			}
		}
	}
	
	
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(i!=j&&mat[i][j]<=m)
			{
				add2edge(i, j, 1);
			}
		}
	}
	*/

	for(int i=0;i<m;++i)
	{
		if(edge[i].d<=mid)
		{
			add2edge(edge[i].u,edge[i].v,1);
			add2edge(edge[i].v,edge[i].u,1);
		}
	}
	return maxflow()>=t;
}

int main(int argc, char**argv) {

#ifndef ONLINE_JUDGE
	freopen("in_2455.txt","r",stdin);
#endif
	
		scanf("%d%d%d",&n,&m,&t);
		for(int i=0;i<m;++i)
		{
			int u,v,d;
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].d);
		}
		/*
		for(int k=1;k<=n;++k)
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					if(mat[i][k]!=inf&&mat[k][j]!=inf&&mat[i][j]>mat[i][k]+mat[k][j])
					{
						mat[i][j]=mat[i][k]+mat[k][j];
					}
				}
			}
		}
		*/
		int l=0,r=inf,m;
		while(l<=r)
		{
			m=(l+r)>>1;
			if(Check(m))
			{
				r=m-1;
			}
			else
			{
				l=m+1;
			}
		}
		/*
		init();
		int Sum=input(F);
		int MaxFlow=maxflow();
		Vis[1]=true;
		dfs(1);
		cout<<"Case "<<CaseIndex<<": "<<Sum-MaxFlow<<endl;
		OutputEdges();
		*/
		printf("%d\n",l);
	
	return 0;
}
