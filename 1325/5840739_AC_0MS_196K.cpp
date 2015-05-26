/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Machine Schedule
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1325
*       ID             : 1325
*       Date           : 9/10/2009
*       Time           : 11:23:14
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

#define MAXN 101
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

int m,n,k;
int mat[MAXN][MAXN];
int match1[MAXN],match2[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1325.txt","r",stdin);
#endif
	while(scanf("%d",&m)&&m)
	{
		scanf("%d%d",&n,&k);
		memset(mat,0,sizeof(mat));
		while(k--)
		{
			int i,u,v;
			scanf("%d%d%d",&i,&u,&v);
			if(u*v)
			{
				mat[u][v]=1;
			}
		}
		printf("%d\n",hungary(m,n,mat,match1,match2));
	}
	return 0;
}
