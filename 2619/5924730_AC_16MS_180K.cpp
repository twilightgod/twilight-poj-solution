/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Delta-wave
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2619
*       ID             : 2619
*       Date           : 9/27/2009
*       Time           : 22:37:27
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

int GetRow(int x)
{
	return (int)ceil(sqrt(double(x)));
}

int GetCol(int x,int r)
{
	return x-(r-1)*(r-1)-1;
}

int GetLeft(int c,int r)
{
	return ((r<<1)-1-1-c)>>1;
}

int GetRight(int c)
{
	return c>>1;
}

int n,m,ans,r1,r2,c1,c2;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2619.txt","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2)
	{
		ans=0;
		r1=GetRow(n);
		r2=GetRow(m);
		c1=GetCol(n,r1);
		c2=GetCol(m,r2);
		ans+=abs(r1-r2);
		ans+=abs(GetLeft(c1,r1)-GetLeft(c2,r2));
		ans+=abs(GetRight(c1)-GetRight(c2));
		printf("%d\n",ans);
	}
	return 0;
}
