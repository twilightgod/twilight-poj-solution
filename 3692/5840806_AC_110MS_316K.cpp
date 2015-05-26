/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Kindergarten
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3692
*       ID             : 3692
*       Date           : 9/10/2009
*       Time           : 22:33:4
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

#define MAXN 201
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

int n,m,k,ca;
int mat[MAXN][MAXN],match1[MAXN],match2[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3692.txt","r",stdin);
#endif
	ca=0;
	while(scanf("%d%d%d",&n,&m,&k)&&n)
	{
		memset(mat,1,sizeof(mat));
		while(k--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			mat[--u][--v]=0;
		}
		printf("Case %d: %d\n",++ca,n+m-hungary(n,m,mat,match1,match2));
	}
	return 0;
}
