/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Network
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1144
*       ID             : 1144
*       Date           : 9/9/2009
*       Time           : 22:44:56
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

#define MAXN 110

void search(int n,int mat[][MAXN],int* dfn,int* low,int now,int& ret,int* key,int& cnt,int root,int& rd,int* bb){
	int i;
	dfn[now]=low[now]=++cnt;
	for (i=0;i<n;i++)
		if (mat[now][i]){
			if (!dfn[i]){
				search(n,mat,dfn,low,i,ret,key,cnt,root,rd,bb);
				if (low[i]<low[now])
					low[now]=low[i];
				if (low[i]>=dfn[now]){
					if (now!=root&&!bb[now])
						key[ret++]=now,bb[now]=1;
					else if(now==root)
						rd++;
				}
			}
			else if (dfn[i]<low[now])
				low[now]=dfn[i];
		}
}

int key_vertex(int n,int mat[][MAXN],int* key){
	int ret=0,i,cnt,rd,dfn[MAXN],low[MAXN],bb[MAXN];
	for (i=0;i<n;dfn[i++]=bb[i]=0);
	for (cnt=i=0;i<n;i++)
		if (!dfn[i]){
			rd=0;
			search(n,mat,dfn,low,i,ret,key,cnt,i,rd,bb);
			if (rd>1&&!bb[i])
				key[ret++]=i,bb[i]=1;
		}
	return ret;
}

int mat[MAXN][MAXN];
int n;
int key[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1144.txt","r",stdin);
#endif
	while(scanf("%d",&n)&&n)
	{
		memset(mat,0,sizeof(mat));
		int u,v;
		while(scanf("%d",&u)&&u)
		{
			u--;
			while(getchar()!='\n')
			{
				scanf("%d",&v);
				v--;
				mat[u][v]=mat[v][u]=1;
			}
		}
		printf("%d\n",key_vertex(n,mat,key));
	}
	return 0;
}
