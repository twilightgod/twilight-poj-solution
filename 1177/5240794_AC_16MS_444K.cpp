/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Picture
*       ID             : 1177
*       Date           : 5/3/2009
*       Time           : 13:44:25
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define MAXN 5001

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
	//节点所代表的区间[l,r](离散化后下标)
	int l,r;
	//覆盖数
	int cnt;
	//覆盖总长度
	int len;
	//是否覆盖了左右子树
	bool lcover,rcover;
	//覆盖的段数
	int seg;
};

//矩形数
int n;
//静态分配线段树节点的内存
Node tn[MAXN*4];
//总周长
long long ans;
//上一次的结果
long long lastsum;
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

//更新覆盖区间数
void UpdateSegment(int cur)
{
	if(tn[cur].cnt>0)
	{
		tn[cur].lcover=tn[cur].rcover=true;
		tn[cur].seg=1;
	}
	else if(tn[cur].r-tn[cur].l>1)
	{
		tn[cur].lcover=tn[tn[cur].lc].lcover;
		tn[cur].rcover=tn[tn[cur].rc].rcover;
		tn[cur].seg=tn[tn[cur].lc].seg+tn[tn[cur].rc].seg
			-tn[tn[cur].rc].lcover*tn[tn[cur].lc].rcover;
	}
	else
	{
		tn[cur].lcover=tn[cur].rcover=false;
		tn[cur].seg=0;
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
	UpdateSegment(cur);
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
	UpdateSegment(cur);
}

bool Solve()
{
	//读入
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int t1,t2,t3,t4;
		scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
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
	lastsum=0;
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
		//面积
		//ans+=(long long)tn[0].len*(long long)(yl[i+1].x-yl[i].x);
		//周长
		if(i!=(n<<1)-1)
		{
			ans += tn[0].seg*(yl[i+1].x - yl[i].x)*2; // 横增加
		}
		ans += abs(tn[0].len - lastsum);// 竖增加
		lastsum=tn[0].len;
	}

	//输出
	printf("%I64d\n",ans);
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1177.txt","r",stdin);
#endif
	Solve();
	return 0;
}
