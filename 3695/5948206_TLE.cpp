/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Rectangles
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3695
*       ID             : 3695
*       Date           : 10/2/2009
*       Time           : 22:13:44
*       Computer Name  : EVERLASTING-AMD
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
	//覆盖总长度
	int len;
};

struct RECT
{
	int x0,y0,x1,y1;
};

int q;
//矩形数
int n;
//静态分配线段树节点的内存
Node tn[MAXN*4];
//总面积
int ans;
//不同的y坐标数
int m;
//y坐标
int yc[MAXN*2];
//实际坐标到离散化坐标的映射
map<int,int> ym;
//y方向的线段
YLine yl[MAXN*2];

RECT rect[21];

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

//更新总长度
void UpdateLength(int cur)
{
	if(tn[cur].cnt>0)
	{
		tn[cur].len=yc[tn[cur].r]-yc[tn[cur].l];
	}
	else if(tn[cur].r-tn[cur].l>1)
	{
		tn[cur].len=tn[tn[cur].lc].len+tn[tn[cur].rc].len;
	}
	else
	{
		tn[cur].len=0;
	}
}

//插入线段
void InsertLine(int cur,int l,int r)
{
	if(l<=tn[cur].l&&tn[cur].r<=r)
	{
		tn[cur].cnt++;
	}
	else
	{
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
	UpdateLength(cur);
}

//删除线段
void EraseLine(int cur,int l,int r)
{
	if(l<=tn[cur].l&&tn[cur].r<=r)
	{
		tn[cur].cnt--;
	}
	else
	{
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
	UpdateLength(cur);
}

bool Solve()
{
	scanf("%d",&n);		
	for(int i=0;i<n;++i)
	{
		int rr;
		scanf("%d",&rr);
		int t1=rect[rr].x0,t2=rect[rr].y0,t3=rect[rr].x1,t4=rect[rr].y1;
		//scanf("%d%d%d",&t1,&t3,&t4);
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
		ans+=tn[0].len*(yl[i+1].x-yl[i].x);
	}
	//输出
	printf("%d\n",ans);
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3695.txt","r",stdin);
#endif
	int ca=0;
	while(scanf("%d%d",&n,&q)&&n)
	{
		printf("Case %d:\n",++ca);
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d%d",&rect[i].x0,&rect[i].y0,&rect[i].x1,&rect[i].y1);
		}
		for(int i=1;i<=q;++i)
		{
			printf("Query %d: ",i);
			Solve();
		}
		puts("");
	}
	return 0;
}
