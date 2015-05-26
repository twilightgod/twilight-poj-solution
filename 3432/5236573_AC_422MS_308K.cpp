/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Count Squares
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3432
*       ID             : 3432
*       Date           : 5/28/2009
*       Time           : 21:14:12
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<set>
using namespace std;

#define MAXN 2000

struct Node
{
	int x,y;
};

bool operator <(Node a,Node b)
{
	if(a.x==b.x)
	{
		return a.y<b.y;
	}
	else
	{
		return a.x<b.x;
	}
}

int n,ans;
set<Node> s;
Node a[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3432.txt","r",stdin);
#endif
	while(scanf("%d",&n)!=EOF)
	{
		s.clear();
		ans=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].x<<=1;
			a[i].y<<=1;
			s.insert(a[i]);
		}
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				Node m;
				m.x=(a[i].x+a[j].x)>>1;
				m.y=(a[i].y+a[j].y)>>1;
				Node v;
				v.x=(-(a[i].y-a[j].y))>>1;
				v.y=(a[i].x-a[j].x)>>1;
				Node c1,c2;
				c1.x=v.x+m.x;
				c1.y=v.y+m.y;
				c2.x=m.x-v.x;
				c2.y=m.y-v.y;
				if(s.find(c1)!=s.end()&&s.find(c2)!=s.end())
				{
					ans++;
				}
			}
		}
		printf("%d\n",(ans>>1));
	}
	return 0;
}
