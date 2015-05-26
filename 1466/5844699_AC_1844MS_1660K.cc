/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Girls and Boys
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1466
*       ID             : 1466
*       Date           : 9/11/2009
*       Time           : 20:33:29
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<stdio.h>
using namespace std;

#define MAXN 501

#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}

struct TAXI
{
	int x0,y0,x1,y1,ti,st;
};

TAXI taxi[MAXN];
int n,t;
int mat[MAXN][MAXN],match1[MAXN],match2[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1466.txt","r",stdin);
#endif
	while(scanf("%d\n",&n)==1)
	{
		memset(mat,0,sizeof(mat));
		for(int i=0;i<n;++i)
		{
			int u,v,c;
			scanf("%d: (%d)",&u,&c);
			while(c--)
			{
				scanf("%d",&v);
				mat[u][v]=1;
			}
		}
		printf("%d\n",n-hungary(n,n,mat,match1,match2)/2);
	}
	return 0;
}
