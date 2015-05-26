/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Corral the Cows
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3179
*       ID             : 3179
*       Date           : 9/29/2009
*       Time           : 10:14:32
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define MAXN 501

typedef pair<int,int> CLOVER;

CLOVER cl[MAXN];
int n,c,l,r,m,sz;
set<int> sx,sy;
map<int,int> mx,my;
vector<int> vx,vy;
int s[MAXN][MAXN]={0};

inline int max1(int x,int y)
{
	return x>y?x:y;
}

bool Check(int m)
{
	for(int i=1;i<=vx.size();++i)
	{
		for(int j=1;j<=vy.size();++j)
		{
			if(vx[i-1]+m-1>vx.back()&&vy[j-1]+m-1>vy.back())
			{
				break;
			}
			int x=distance(vx.begin(),upper_bound(vx.begin(),vx.end(),vx[i-1]+m-1));
			int y=distance(vy.begin(),upper_bound(vy.begin(),vy.end(),vy[j-1]+m-1));

			if(s[x][y]-s[x][j-1]-s[i-1][y]+s[i-1][j-1]>=c)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3179.txt","r",stdin);
#endif
	scanf("%d%d",&c,&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&cl[i].first,&cl[i].second);
		sx.insert(cl[i].first);
		sy.insert(cl[i].second);
	}
	vx.assign(sx.begin(),sx.end());
	vy.assign(sy.begin(),sy.end());
	for(int i=0;i<vx.size();++i)
	{
		mx[vx[i]]=i+1;
	}
	for(int i=0;i<vy.size();++i)
	{
		my[vy[i]]=i+1;
	}
	for(int i=0;i<n;++i)
	{
		s[mx[cl[i].first]][my[cl[i].second]]++;
	}
	sz=max1(vx.size(),vy.size());
	for(int i=1;i<=sz;++i)
	{
		for(int j=1;j<=sz;++j)
		{
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	l=1;
	r=max1(vx.back()-vx.front()+1,vy.back()-vy.front()+1);

	while(l<=r)
	{
		m=(l+r)>>1;
		if(Check(m))
		{
			r=m-1;
		}
		else
		{
			l=m+1;
		}
	}
	printf("%d\n",l);
	return 0;
}
