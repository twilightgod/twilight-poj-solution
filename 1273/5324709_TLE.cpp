/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Drainage Ditches
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1273
*       ID             : 1273_SAP_SE
*       Date           : 6/24/2009
*       Time           : 11:30:56
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
using namespace std;

#define MAXN 300
#define INF 0x7fffffff

int c[MAXN][MAXN];
int h[MAXN],vh[MAXN];
int n,augc,rd1,rd2,m,i;
int flow=0;
bool found;

void aug(const int m)
{
	int i,augco,minh;
	minh=n-1;
	augco=augc;
	if(m==n)
	{
		found=true;
		flow+=augc;
		return;
	}
	for(int i=1;i<=n;++i)
		if(c[m][i])
		{
			if(h[i]+1==h[m])
			{
				if(c[m][i]<augc) augc=c[m][i];
				aug(i);
				if(h[1]>=n) return;
				if(found) break;
				augc=augco;
			}
			if(h[i]<minh) minh=h[i];
	}
	if(!found)
	{
		vh[h[m]]--;
		if(!vh[h[m]]) h[1]=n;
		h[m]=minh+1;
		vh[h[m]]++;
	}
	else
	{
		c[m][i]-=augc;
		c[i][m]+=augc;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1273_SAP_SE.txt","r",stdin);
#endif
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		flow=0;
		memset(c,0,sizeof(c));
		for (i=1;i<=m;i++)
		{
			scanf("%d%d%d",&rd1,&rd2,&augc);
			c[rd1][rd2]+=augc;
		}
		memset(h,0,sizeof(h));
		memset(vh,0,sizeof(vh));
		vh[0]=n;
		while(h[1]<n)
		{
			augc=INF;
			found=false;
			aug(1);
		}
		printf("%d\n",flow);
	}
	return 0;
}
