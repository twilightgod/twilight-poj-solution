/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Texas Trip
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3301
*       ID             : 3301
*       Date           : 10/4/2009
*       Time           : 22:22:23
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

struct POINT
{
	int x,y;
}p[30];

double x[30],y[30];
int t,n;
double best;
const double PI=acos(double(-1));

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3301.txt","r",stdin);
#endif
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>p[i].x>>p[i].y;
		}
		best=1e30;
		for(double theta=0;theta<=PI/2;theta+=0.00002)
		{
			for(int i=0;i<n;++i)
			{
				x[i]=p[i].x*cos(theta)-p[i].y*sin(theta);
				y[i]=p[i].y*cos(theta)+p[i].x*sin(theta);
			}
			double t1,t2;
			t1=*max_element(x,x+n)-*min_element(x,x+n);
			t2=*max_element(y,y+n)-*min_element(y,y+n);
			if(t1>t2)
			{
				t1*=t1;
			}
			else
			{
				t1=t2*t2;
			}
			if(t1<best)
			{
				best=t1;
			}
		}
		printf("%.2f\n",best);
	}
	return 0;
}
