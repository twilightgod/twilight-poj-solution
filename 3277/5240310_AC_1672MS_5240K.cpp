/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : City Horizon
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3277
*       ID             : 3277
*       Date           : 5/29/2009
*       Time           : 16:17:1
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define MAXN 40001

//y方向线段
struct YLine
{
	//x坐标
	int x;
	//y坐标
	int y_low,y_high;
	//是否是矩形的左边线
	bool left;
};

//y方向线段按x排序
bool cmp(YLine a,YLine b)
{
	return a.x<b.x;
}

//线段树节点
struct Node
{
	//左右子树指针
	int lc,rc;
	//节点所代表的区间[l,r]
	int l,r;
	//覆盖数
	int cnt;
};

//矩形数
int n;
//静态分配线段树节点的内存
Node tn[MAXN*4];
//总面积
long long ans;
//不同的y坐标数
int m;
//y坐标
int yc[MAXN*2];
//实际坐标到离散化坐标的映射
map<int,int> ym;
//y方向的线段
YLine yl[MAXN*2];

//建立线段树
void BuildTree(int &cc,int l,int r)
{
	int cur=cc;
	tn[cur].l=l;
	tn[cur].r=r;
	tn[cur].cnt=0;
	if(r-l>1)
	{
		tn[cur].lc=++cc;
		int m=(l+r)>>1;
		BuildTree(cc,l,m);
		tn[cur].rc=++cc;
		BuildTree(cc,m,r);
	}
}

//插入线段
void InsertLine(int cur,int l,int r)
{
	if(l<=tn[cur].l&&tn[cur].r<=r)
	{
		tn[cur].cnt++;
		return;
	}
	int m=(tn[cur].l+tn[cur].r)>>1;
	if(l<m)
	{
		InsertLine(tn[cur].lc,l,r);
	}
	if(m<r)
	{
		InsertLine(tn[cur].rc,l,r);
	}
}

//删除线段
void EraseLine(int cur,int l,int r)
{
	if(l<=tn[cur].l&&tn[cur].r<=r)
	{
		tn[cur].cnt--;
		return;
	}
	int m=(tn[cur].l+tn[cur].r)>>1;
	if(l<m)
	{
		EraseLine(tn[cur].lc,l,r);
	}
	if(m<r)
	{
		EraseLine(tn[cur].rc,l,r);
	}
}

//获取总长度
int GetLength(int cur,int l,int r)
{
	if(tn[cur].cnt>0)
	{
		return yc[tn[cur].r]-yc[tn[cur].l];
	}
	if(tn[cur].r-tn[cur].l>1)
	{
		return(GetLength(tn[cur].lc,l,r)+GetLength(tn[cur].rc,l,r));
	}
	return 0;
}

bool Solve()
{
	//读入
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int t1,t2,t3,t4;
		scanf("%d%d%d",&t1,&t3,&t4);
		t2=0;
		yl[i<<1].left=true;
		yl[i<<1].x=t1;
		yl[i<<1].y_low=t2;
		yl[i<<1].y_high=t4;
		yl[(i<<1)+1].left=false;
		yl[(i<<1)+1].x=t3;
		yl[(i<<1)+1].y_low=t2;
		yl[(i<<1)+1].y_high=t4;
		yc[i<<1]=t2;
		yc[(i<<1)+1]=t4;
	}
	//排序
	sort(yc,yc+(n<<1));
	sort(yl,yl+(n<<1),cmp);
	//去重复坐标
	m=1;
	for(int i=1;i<(n<<1);++i)
	{
		if(yc[i]!=yc[i-1])
		{
			yc[m++]=yc[i];
		}
	}
	//建立映射
	ym.clear();
	for(int i=0;i<m;++i)
	{
		ym[yc[i]]=i;
	}
	//建立线段树
	int cur=0;
	BuildTree(cur,0,m-1);
	//求解
	ans=0;
	//枚举所有平行于y的小区间
	for(int i=0;i<(n<<1);++i)
	{
		//左侧插入,右侧删除
		if(yl[i].left)
		{
			InsertLine(0,ym[yl[i].y_low],ym[yl[i].y_high]);
		}
		else
		{
			EraseLine(0,ym[yl[i].y_low],ym[yl[i].y_high]);
		}
		ans+=(long long)GetLength(0,0,m-1)*(long long)(yl[i+1].x-yl[i].x);
	}
	//输出
	printf("%I64d\n",ans);
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3277.txt","r",stdin);
#endif
	Solve();
	return 0;
}
