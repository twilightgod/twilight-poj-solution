/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Cows
*       ID             : 2481
*       Date           : 11/28/2008
*       Time           : 22:16:38
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
//排序+树状数组
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 100001

//Si,Ei,索引号
struct Cow
{
	int s,e,index;
};

Cow cows[MAXN];
int C[MAXN];
int n;
int ans[MAXN];

//第一优先:E递减,第二优先:S递增
inline bool cmp(const Cow &a,const Cow &b)
{
	return a.e==b.e?a.s<b.s:a.e>b.e;
}

//树状数组操作1
inline int LowBit(int x)
{
	return x&(-x);
}

//树状数组操作2
int Sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=C[i];
		i-=LowBit(i);
	}
	return s;
}

//树状数组操作3,len为最大更新的下标
void Modify(int i,int delta,int len)
{
	while(i<=len)
	{
		C[i]+=delta;
		i+=LowBit(i);
	}
}

int main()
{
	//freopen("in_2481.txt","r",stdin);
	//为了后面的循环处理,设置一个肯定S,E不同的cow
	cows[0].e=-1;
	while(scanf("%d",&n)&&n)
	{
		//清空C
		memset(C,0,sizeof(C));
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&cows[i].s,&cows[i].e);
			//树状数组从1开始,加1处理掉0
			cows[i].s++;
			cows[i].e++;
			cows[i].index=i;
		}
		//排序
		sort(cows+1,cows+n+1,cmp);
		for(int i=1;i<=n;++i)
		{
			//因为相等的区间不算包含关系,如果区间i和区间i-1相等,那么ans相同,否则统计[1,Si]的总数
			ans[cows[i].index]=cows[i].s==cows[i-1].s&&cows[i].e==cows[i-1].e
				?ans[cows[i-1].index]
				:Sum(cows[i].s);
			//更新树状数组只需到Ei
			Modify(cows[i].s,1,cows[i].e);
		}
		for(int i=1;i<=n;++i)
		{
			printf("%s%d",i!=1?" ":"",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
