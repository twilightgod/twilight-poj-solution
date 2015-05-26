/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Art Gallery
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1279
*       ID             : 1279
*       Date           : 10/8/2009
*       Time           : 20:26:14
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
/*
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

//看代码前最好看下zzy的论文！！！！王飞的资料里有 
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>

using namespace std;

const double eps = 1e-8;
const int MaxN = 50005;
typedef struct{double x, y;}Point;
typedef struct{double k, b;}Line;
typedef struct{Point p[MaxN]; int n;}Polygon;
Line l[MaxN]; 
double ang[MaxN];
int n, ord[MaxN], dq[MaxN];

int dblcmp(double t)
{
	if(fabs(t) < eps)
		return 0;
	return t < 0? -1 : 1;
}

double cross(Point p0, Point p1, Point p2)	//叉积 
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}

bool cmp(int u, int v)		//极角排序 
{
	if(!dblcmp(ang[u]-ang[v]))//当极角一样是，靠近目标的放前面 
		return l[u].b > l[v].b;
	return ang[u] < ang[v];
}

void Intersection(int x, int y, Point &pp)	//y=kx+b,判断两直线的交点pp 
{
	pp.x = (l[x].b-l[y].b)/(l[y].k-l[x].k);
	pp.y = l[x].k*pp.x + l[x].b;
}

void Intersection(Point s1, Point e1, Point s2, Point e2, Point &pp) 
{  
    double dot1,dot2; 
    dot1 = cross(s2,e1,s1); dot2 = cross(e1,e2,s1); 
	    pp.x = (s2.x*dot2 + e2.x*dot1) / (dot2+dot1); 
	    pp.y = (s2.y*dot2 + e2.y*dot1) / (dot2+dot1); 
}两个点求两直线的交点pp  


int Judgein(int x, int y, int z)	//用叉积判断点是靠近目标的还是远离目标的 
{
	Point tmp, t1, t2;
	Intersection(y, z, tmp);
	t1.x = 1;
	t1.y = l[x].k + l[x].b;
	t2.x = 0;
	t2.y = l[x].b;
	return cross(t2, t1, tmp) <= 0;
}

int HalfPlaneIntersection()
{
	int cnt, i;
	for(i = 0; i < n; i++)		//求出与X轴夹角，用于极角排序 
	{
		ang[i] = atan2(l[i].k, 1);
		ord[i] = i;
	}
	sort(ord, ord+n, cmp);
	for(i = cnt = 1; i < n; i++)
		if(dblcmp(ang[ord[i]]-ang[ord[i-1]]))
			ord[cnt++] = ord[i];
	int bot = 1, top = 2;
	dq[1] = ord[0];		//	双端队列 
	dq[2] = ord[1];
	for(i = 2; i < n; i++)
	{
		while(bot < top && Judgein(ord[i], dq[top], dq[top-1]))
			top--;
		while(bot < top && Judgein(ord[i], dq[bot], dq[bot+1]))
			bot++;
		dq[++top] = ord[i];
	}
	while(bot < top && Judgein(dq[bot], dq[top], dq[top-1]))
		top--;
	while(bot < top && Judgein(dq[top], dq[bot], dq[bot+1]))
		bot++;
	//得到平面的交点 
}
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
//多边形切割
//可用于半平面交
#define MAXN 2000
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};

int sgn(double x)
{
	return (x>eps)-(x<-eps);
}

double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int same_side(point p1,point p2,point l1,point l2){
	return xmult(l1,p1,l2)*xmult(l1,p2,l2)>eps;
}

double dis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

point intersection(point u1,point u2,point v1,point v2){
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
			/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}

//将多边形沿l1,l2确定的直线切割在side侧切割,保证l1,l2,side不共线
void polygon_cut(int& n,point* p,point l1,point l2,point side){
	point pp[100];
	int m=0,i;
	for (i=0;i<n;i++){
		if (same_side(p[i],side,l1,l2))
			pp[m++]=p[i];
		if (!same_side(p[i],p[(i+1)%n],l1,l2)&&!(zero(xmult(p[i],l1,l2))&&zero(xmult(p[(i+1)%n],l1,l2))))
			pp[m++]=intersection(p[i],p[(i+1)%n],l1,l2);
	}
	for (n=i=0;i<m;i++)
		if (!i||!zero(pp[i].x-pp[i-1].x)||!zero(pp[i].y-pp[i-1].y))
			p[n++]=pp[i];
	if (zero(p[n-1].x-p[0].x)&&zero(p[n-1].y-p[0].y))
		n--;
	if (n<3)
		n=0;
}

//计算多边形面积,顶点按顺时针或逆时针给出
double area_polygon(int n,point* p){
	double s1=0,s2=0;
	int i;
	for (i=0;i<n;i++)
		s1+=p[(i+1)%n].y*p[i].x,s2+=p[(i+1)%n].y*p[(i+2)%n].x;
	return (s1-s2)/2;
}

int n,m,t;
double ans,len;
point p[MAXN],poy[MAXN],lb;
#define INF 1e10

void Init()
{
	poy[0].x=poy[0].y=-INF;
	poy[1].x=-INF;
	poy[1].y=INF;
	poy[2].x=poy[2].y=INF;
	poy[3].x=INF;
	poy[3].y=-INF;
	m=4;
}

bool cmp(point a,point b)
{
	/*
	double t1=atan2(a.y-lb.y,a.x-lb.x),t2=atan2(b.y-lb.y,b.x-lb.x);
	if(sgn(t1-t2)==0)
	{
		return sgn(dis(a,lb)-dis(b,lb))>0;
	}
	else
	{
		return sgn(t1-t2)>0;
	}
	*/
	double x=xmult(a,b,lb);
	if(sgn(x)==0)
	{
		return sgn(dis(a,lb)-dis(b,lb))>0;
	}
	else
	{
		return sgn(x)<0;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1279.txt","r",stdin);
#endif
	scanf("%d\n",&t);
	while(t--)
	{
		Init();
		scanf("%d\n",&n);
		lb.x=lb.y=INF;
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf\n",&p[i].x,&p[i].y);
			/*
			if(sgn(lb.y-p[i].y)==0)
			{
				if(sgn(lb.x-p[i].x)>0)
				{
					lb=p[i];
				}
			}
			else if(sgn(lb.y-p[i].y)>0)
			{
				lb=p[i];
			}
			*/
		}
		//sort(p,p+n,cmp);
		if(sgn(area_polygon(n,p))>0)
		{
			reverse(p,p+n);
		}
		for(int i=0;i<n;++i)
		{
			point a,b;
			a.x=p[(i+1)%n].x-p[i].x;
			a.y=p[(i+1)%n].y-p[i].y;
			b.x=p[i].x+a.y;
			b.y=p[i].y-a.x;
			polygon_cut(m,poy,p[i],p[(i+1)%n],b);
		}
		ans=fabs(area_polygon(m,poy));
		printf("%.2lf\n",ans);
	}
	return 0;
}
