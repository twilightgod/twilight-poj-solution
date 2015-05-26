/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Going from u to v or from v to u?
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2762
*       ID             : 2762
*       Date           : 9/9/2009
*       Time           : 9:58:47
*       Computer Name  : EVERLASTING-AMD
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

#define MAXN 1001

vector<int> lin[MAXN],linr[MAXN],linc[MAXN];
/*
void search(int n,int* dfn,int* low,int now,int& cnt,int& tag,int* id,int* st,int& sp){
	int i,j;
	dfn[st[sp++]=now]=low[now]=++cnt;
	//for (i=0;i<n;i++)
	for(int kk=0;kk<lin[now].size();++kk)
	{
		//	if (mat[now][i]){
		i=lin[now][kk];
		{
			if (!dfn[i]){
				search(n,dfn,low,i,cnt,tag,id,st,sp);
				if (low[i]<low[now])
					low[now]=low[i];
			}
			else if (dfn[i]<dfn[now]){
				for (j=0;j<sp&&st[j]!=i;j++);
				if (j<cnt&&dfn[i]<low[now])
					low[now]=dfn[i];
			}
		}
	}
	if (low[now]==dfn[now])
		for (tag++;st[sp]!=now;id[st[--sp]]=tag);
}

int find_components(int n,int* id){
	int ret=0,i,cnt,sp,st[MAXN],dfn[MAXN],low[MAXN];
	for (i=0;i<n;dfn[i++]=0);
	for (sp=cnt=i=0;i<n;i++)
		if (!dfn[i])
			search(n,dfn,low,i,cnt,ret,id,st,sp);
	return ret;
}
*/

bool used[MAXN];
int num,nn;
int len;
int n,m,t;
int id[MAXN];
int de[MAXN];
int sq[MAXN];

void DFS0(int u)
{
	used[u]=true;
	for(int i=0;i<lin[u].size();++i)
	{
		int &v=lin[u][i];
		if(!used[v])
		{
			DFS0(v);
		}
	}
	sq[--num]=u;
}

void DFS1(int u)
{
	used[u]=true;
	for(int i=0;i<linr[u].size();++i)
	{
		int &v=linr[u][i];
		if(!used[v])
		{
			DFS1(v);
		}
	}
	id[u]=nn;
}

void DFS2(int u,int dep)
{
	if(dep>len)
	{
		len=dep;
	}
	for(int kk=0;kk<linc[u].size();++kk)
	{
		int &v=linc[u][kk];
		DFS2(v,dep+1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2762.txt","r",stdin);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
		{
			lin[i].clear();
			linr[i].clear();
		}
		while(m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			lin[--u].push_back(--v);
			linr[v].push_back(u);
		}

		num=n;
		memset(used,false,sizeof(used));
		for(int i=0;i<n;++i)
		{
			if(!used[i])
			{
				DFS0(i);
			}
		}

		nn=0;
		memset(used,false,sizeof(used));
		for(int i=0;i<n;++i)
		{
			if(!used[sq[i]])
			{
				nn++;
				DFS1(sq[i]);
			}
		}

		//int nn=find_components(n,id);
		for(int i=0;i<nn;++i)
		{
			linc[i].clear();
		}
		memset(de,0,sizeof(de));
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<lin[i].size();++j)
			{
				int k=lin[i][j];
				if(id[i]!=id[k])
				{
					linc[id[i]-1].push_back(id[k]-1);
					de[id[k]-1]++;
				}
			}
		}
		
		bool god=false;
		int st;

		//访问到了零入度点
		bool de0=false;
		for(int i=0;i<nn;++i)
		{
			if(de[i]==0)
			{
				if(!de0)
				{
					de0=true;
					st=i;
				}
				else
				{
					god=true;
					break;
				}
			}
		}

		if(!god)
		{
			len=0;
			DFS2(st,1);
			if(len!=nn)
			{
				god=true;
			}
		}

		if(!god)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
