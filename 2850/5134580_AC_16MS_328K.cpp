/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Stacking Cylinders
*       ID             : 2850
*       Date           : 5/11/2009
*       Time           : 18:24:17
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

#define MAXN 1000

struct Coo
{
	double x,y;
};

Coo c[MAXN][MAXN];
int t,n,ca;

int main()
{
	//freopen("in_2850.txt","r",stdin);
	cin>>t;
	ca=0;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>c[n-1][i].x;
			c[n-1][i].y=1;
		}
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
				//if(p1.y<=p2.y)
				c[i][j].x=-(p2.y-p1.y)/d*t+p3.x;
				c[i][j].y=(p2.x-p1.x)/d*t+p3.y;
			}
		}
		printf("%d: %.4lf %.4lf\n",++ca,c[0][0].x,c[0][0].y);
	}
	return 0;
}
