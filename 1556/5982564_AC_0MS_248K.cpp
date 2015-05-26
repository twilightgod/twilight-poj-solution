/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : The Doors
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1556
*       ID             : 1556
*       Date           : 10/10/2009
*       Time           : 12:21:14
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

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define MAXN 100
#define INF 1e10

struct point{double x,y;};

//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int opposite_side(point p1,point p2,point l1,point l2){
	return xmult(l1,p1,l2)*xmult(l1,p2,l2)<-eps;
}

int intersect_ex(point u1,point u2,point v1,point v2){
	return opposite_side(u1,u2,v1,v2)&&opposite_side(v1,v2,u1,u2);
}

int n,m;
point w1[MAXN],w2[MAXN],p[MAXN];
double mat[MAXN][MAXN],dis[MAXN];
bool used[MAXN];

bool CanSee(int i,int j)
{
	for(int k=0;k<m;++k)
	{
		if(intersect_ex(w1[k],w2[k],p[i],p[j]))
		{
			return false;
		}
	}
	return true;
}

inline double getdis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1556.txt","r",stdin);
#endif
	while(scanf("%d\n",&n)&&n!=-1)
	{
		for(int i=0;i<n;++i)
		{
			double tx,ty1,ty2,ty3,ty4;
			scanf("%lf%lf%lf%lf%lf\n",&tx,&ty1,&ty2,&ty3,&ty4);
			w1[3*i].x=w2[3*i].x=w1[3*i+1].x=w2[3*i+1].x=w1[3*i+2].x=w2[3*i+2].x=tx;
			p[4*i].x=p[4*i+1].x=p[4*i+2].x=p[4*i+3].x=tx;
			p[4*i].y=ty1;
			p[4*i+1].y=ty2;
			p[4*i+2].y=ty3;
			p[4*i+3].y=ty4;
			w1[3*i].y=0;
			w2[3*i].y=ty1;
			w1[3*i+1].y=ty2;
			w2[3*i+1].y=ty3;
			w1[3*i+2].y=ty4;
			w2[3*i+2].y=10;
		}
		m=3*n;
		n=n*4+2;
		p[n-2].x=0;
		p[n-2].y=5;
		p[n-1].x=10;
		p[n-1].y=5;
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				if(CanSee(i,j))
				{
					mat[i][j]=mat[j][i]=getdis(p[i],p[j]);
				}
				else
				{
					mat[i][j]=mat[j][i]=INF;
				}
			}
		}
		for(int i=0;i<n;++i)
		{
			dis[i]=INF;
		}
		memset(used,false,sizeof(used));
		dis[n-2]=0;
		for(int i=0;i<n-1;++i)
		{
			int u,ma=INF;
			for(int i=0;i<n;++i)
			{
				if(!used[i]&&ma>dis[i])
				{
					u=i;
					ma=dis[i];
				}
			}
			if(u==n-1)
			{
				break;
			}
			used[u]=true;
			for(int v=0;v<n;++v)
			{
				if(!used[v]&&dis[v]>dis[u]+mat[u][v])
				{
					dis[v]=dis[u]+mat[u][v];
				}
			}
		}
		printf("%.2lf\n",dis[n-1]);
	}
	return 0;
}
