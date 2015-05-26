/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Aggressive cows
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2456
*       ID             : 2456
*       Date           : 5/28/2009
*       Time           : 11:28:22
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 100000

int n,c,l,r,m;
int a[MAXN];

bool Check(int m)
{
	int cnt=1;
	int last=a[0];
	for(int i=1;i<n;++i)
	{
		if(last+m>a[i])
		{
			continue;
		}
		else
		{
			last=a[i];
			if(++cnt==c)
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
	freopen("in_2456_test.txt","r",stdin);
#endif
	scanf("%d%d",&n,&c);
	l=1;
	r=-1;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		if(r<a[i])
		{
			r=a[i];
		}
	}
	sort(a,a+n);
	while(l<=r)
	{
		m=(l+r)>>1;
		if(Check(m))
		{
			l=m+1;
		}
		else
		{
			r=m-1;
		}
	}
	printf("%d\n",r);
	return 0;
}
