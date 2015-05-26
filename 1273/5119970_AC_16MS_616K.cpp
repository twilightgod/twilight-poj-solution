#include<stdio.h> 
#include<list> 
#include<queue> 
#include<string.h> 
#include <vector>
#include <iostream>
using namespace std; 
#define M 201
int pre[M]; 
int f[M][M],g[M][M]; 
bool b[M]={0}; 

//g为输入的图容量矩阵,f为返回流量矩阵
int dinic(int n,int s,int t) 
{ 
	memset(f,0,sizeof(f));
	int ans=0; 
	while(true) 
	{
		queue<int> q; 
		fill(pre,pre+n+2,-1); 
		fill(b,b+n+2,0); 
		q.push(s);b[s]=1; 
		while(!q.empty()) 
		{ 
			int x=q.front();q.pop(); 
			if(x==t)break; 
			for(int i=1;i<=n;i++) 
			{
				if(!b[i]&&f[x][i]<g[x][i]) 
				{ 
					pre[i]=x; 
					b[i]=1; 
					q.push(i); 
				} 
			}
		} 
		if(pre[t]==-1)break; 
		for(int i=1;i<=n;i++) 
		{
			if(f[i][t]<g[i][t]&&(i==s||pre[i]!=-1)) 
			{ 
				int v,low=g[i][t]-f[i][t]; 
				pre[t]=i; 
				for(v=t;pre[v]!=-1;v=pre[v]) 
					low=low<g[pre[v]][v]-f[pre[v]][v]?low:g[pre[v]][v]-f[pre[v]][v]; 
				if(low==0)continue; 
				for(v=t;pre[v]!=-1;v=pre[v]) 
				{ 
					f[pre[v]][v]+=low; 
					f[v][pre[v]]-=low; 
				} 
				ans+=low; 
			} 
		}
	} 
	return ans;
}  

int main(){
	int m,n,i,j,u,v,w;
	while(cin >> m >> n){
		memset(g,0,sizeof(g));
		for(i=0;i<m;i++){
			scanf("%d%d%d",&u,&v,&w);
			g[u][v]+=w;
		}
		cout << dinic(n,1,n) << endl;
	}
}