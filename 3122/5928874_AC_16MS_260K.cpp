/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Pie
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3122
*       ID             : 3122
*       Date           : 9/28/2009
*       Time           : 21:3:57
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

#define MAXN 10000

const double PI=acos(double(-1));
const double eps=1e-5;

double s[MAXN],l,r,m;
int n,f,t;

bool Check(double m)
{
	int cnt=0;
	for(int i=0;i<n;++i)
	{
		if((cnt+=int(s[i]/m))>=f+1)
		{
			return true;
		}
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3122.txt","r",stdin);
#endif
	scanf("%d",&t);
	while(t--)
	{
		l=1e30;
		r=-1e30;
		scanf("%d%d",&n,&f);
		for(int i=0;i<n;++i)
		{
			int tmp;
			scanf("%d",&tmp);
			s[i]=tmp*tmp*PI;
			if(s[i]<l)
			{
				l=s[i];
			}
			if(s[i]>r)
			{
				r=s[i];
			}
		}
		l/=(f+1);
		while(r-l>eps)
		{
			m=(l+r)/2;
			if(Check(m))
			{
				l=m+eps;
			}
			else
			{
				r=m-eps;
			}
		}
		printf("%.4f\n",l);
	}
	return 0;
}
