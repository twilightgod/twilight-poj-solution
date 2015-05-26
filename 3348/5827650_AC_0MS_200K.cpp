/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Cows
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3348
*       ID             : 3348
*       Date           : 9/8/2009
*       Time           : 11:46:18
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
//Melkman
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

#define MAXN 10001

struct _point
{
	int x,y;
};

_point p[MAXN];
int d[MAXN*2];
_point pc[MAXN];
int i,j,n,far,top,bot;
bool tleft,bleft;

/*
inline double GetDistance(_point& p0,_point& p1)
{
	return sqrt((double)((p1.x-p0.x)*(p1.x-p0.x)+(p1.y-p0.y)*(p1.y-p0.y)));
}
*/

//计算向量积的模
inline int vp(int x1,int y1,int x2,int y2)
{
	return x1*y2-x2*y1;
}

//判断左旋
//return >0左旋 / =0共线 / <0右旋
inline int IsLeft(_point& p0,_point& p1,_point& p2)
{
	return vp(p1.x-p0.x,p1.y-p0.y,p2.x-p1.x,p2.y-p1.y);
}

//比较函数
bool cmp(_point p1,_point p2)
{
	return p1.y<p2.y||p1.y==p2.y&&p1.x<p2.x;
}

//计算多边形面积,顶点按顺时针或逆时针给出
double area_polygon(int n,_point* p){
	double s1=0,s2=0;
	int i;
	for (i=0;i<n;i++)
		s1+=p[(i+1)%n].y*p[i].x,s2+=p[(i+1)%n].y*p[(i+2)%n].x;
	return fabs(s1-s2)/2;
}

int main()
{
	//freopen("in_3348.txt","r",stdin);
	//读入点坐标
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	//找最左下角的点,放在p[0]
	j=0;
	for(i=1;i<n;++i)
	{
		if(cmp(p[i],p[j]))
		{
			swap(p[i],p[j]);
		}
	}
	//对点集排序,变为简单多边形
	//Melkman不能处理普通点集,只能处理简单多边形(含凹凸)
	sort(p+1,p+n,cmp);
	//初始化deque
	top=n+1;
	bot=n-2;
	d[n-1]=0;
	d[n]=1;
	//头三个点不能共线
	for(i=2;i<n;++i)
	{
		if(IsLeft(p[0],p[1],p[i])!=0)
		{
			break;
		}
		d[n]=i;
	}
	d[n-2]=d[n+1]=i;
	//如果右旋则交换0和1
	if(IsLeft(p[0],p[1],p[i])<=0)
	{
		swap(d[n],d[n-1]);
	}
	//处理过程
	for(++i;i<n;++i)
	{
		if(IsLeft(p[d[bot+1]],p[d[bot]],p[i])<0&&IsLeft(p[d[top-1]],p[d[top]],p[i])>0)
		{
			continue;
		}
		while(IsLeft(p[d[top-1]],p[d[top]],p[i])<=0)
		{
			top--;
		}
		while(IsLeft(p[d[bot+1]],p[d[bot]],p[i])>=0)
		{
			bot++;
		}
		d[++top]=i;
		d[--bot]=i;
	}
	//处理完后[d[bot],d[top-1]]存的是凸包里顶点的下标
	for(i=bot;i<top;++i)
	{
		pc[i-bot]=p[d[i]];
	}
	printf("%d\n",int(area_polygon(top-bot,pc)/50));
	return 0;
}
