/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Beauty Contest
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2187
*       ID             : 2187RC
*       Date           : 9/9/2009
*       Time           : 17:19:49
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
//Melkman
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 50000

struct _point
{
	int x,y;
};

_point p[MAXN],pc[MAXN];
int d[MAXN*2];
int i,j,n,far,top,bot;
bool tleft,bleft;


inline int GetDistance(_point& p0,_point& p1)
{
	return (p1.x-p0.x)*(p1.x-p0.x)+(p1.y-p0.y)*(p1.y-p0.y);
}


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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2187RC.txt","r",stdin);
#endif
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
	far=0;
	int nn=top-bot;
	for(i=bot;i<top;++i)
	{
		pc[i-bot]=p[i];
	}
	//RC
	int j=1;
	for(int i=0;i<nn;++i)
	{
		//int j=(i+1)%nn;
		while(GetDistance(pc[i],pc[j])<GetDistance(pc[i],pc[(j+1)%nn]))
		{
			j=(j+1)%nn;
		}
		if(far<GetDistance(pc[i],pc[j]))
		{
			far=GetDistance(pc[i],pc[j]);
		}
	}
	printf("%d\n",far);
	return 0;
}
