/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Taxi Cab Scheme
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2060
*       ID             : 2060
*       Date           : 9/11/2009
*       Time           : 10:21:2
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
	freopen("in_2060.txt","r",stdin);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			int hh,mm;
			scanf("%d:%d",&hh,&mm);
			scanf("%d%d%d%d",&taxi[i].x0,&taxi[i].y0,&taxi[i].x1,&taxi[i].y1);
			taxi[i].st=hh*60+mm;
			taxi[i].ti=abs(taxi[i].x0-taxi[i].x1)+abs(taxi[i].y0-taxi[i].y1);
		}
		memset(mat,0,sizeof(mat));
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				if(abs(taxi[i].x1-taxi[j].x0)+abs(taxi[i].y1-taxi[j].y0)+taxi[i].ti+taxi[i].st<taxi[j].st)
				{
					mat[i][j]=1;
				}
			}
		}
		printf("%d\n",n-hungary(n,n,mat,match1,match2));
	}
	return 0;
}
