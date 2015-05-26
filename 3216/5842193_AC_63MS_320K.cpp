/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Repairing Company
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3216
*       ID             : 3216
*       Date           : 9/11/2009
*       Time           : 10:42:59
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

#define MAXQ 21
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

struct TASK
{
	int p,t,d;
} task[MAXN];
int matq[MAXQ][MAXQ],mat[MAXN][MAXN],match1[MAXN],match2[MAXN];
int q,m;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3216.txt","r",stdin);
#endif
	while(scanf("%d%d",&q,&m)&&q)
	{
		for(int i=0;i<q;++i)
		{
			for(int j=0;j<q;++j)
			{
				scanf("%d",&matq[i][j]);
			}
		}
		for(int k=0;k<q;++k)
		{
			for(int i=0;i<q;++i)
			{
				for(int j=0;j<q;++j)
				{
					if(matq[i][k]!=-1&&matq[k][j]!=-1&&(matq[i][k]+matq[k][j]<matq[i][j]||matq[i][j]==-1))
					{
						matq[i][j]=matq[i][k]+matq[k][j];
					}
				}
			}
		}
		memset(mat,0,sizeof(mat));
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&task[i].p,&task[i].t,&task[i].d);
			task[i].p--;
		}
		for(int i=0;i<m;++i)
		{
			for(int j=0;j<m;++j)
			{
				if(i!=j)
				{
					if(task[i].t+task[i].d+matq[task[i].p][task[j].p]<=task[j].t)
					{
						mat[i][j]=1;
					}
				}
			}
		}
		printf("%d\n",m-hungary(m,m,mat,match1,match2));
	}
	return 0;
}
