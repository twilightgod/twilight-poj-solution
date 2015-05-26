/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Stacking Cylinders
*       ID             : 2194
*       Date           : 5/12/2009
*       Time           : 12:33:10
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

#define MAXN 10

struct Coo
{
	double x,y;
};

Coo c[MAXN][MAXN];
int t,n,ca;

bool cmp(Coo a,Coo b)
{
	return a.x<b.x;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2194.txt","r",stdin);
#endif
	while(cin>>n&&n)
	{
		for(int i=0;i<n;++i)
		{
			cin>>c[n-1][i].x;
			c[n-1][i].y=1;
		}
		sort(c[n-1],c[n-1]+n,cmp);
		for(int i=n-2;i>=0;--i)
		{
			for(int j=0;j<=i;++j)
			{
				Coo p1,p2,p3;
				p1=c[i+1][j];
				p2=c[i+1][j+1];
				p3.x=(p1.x+p2.x)/2;
				p3.y=(p1.y+p2.y)/2;
				double d=sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
				double t=sqrt(4-(d/2)*(d/2));
				c[i][j].x=-(p2.y-p1.y)/d*t+p3.x;
				c[i][j].y=(p2.x-p1.x)/d*t+p3.y;
			}
		}
		printf("%.4lf %.4lf\n",c[0][0].x,c[0][0].y);
	}
	return 0;
}
