/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Atlantis
*       ID             : 1151
*       Date           : 5/7/2009
*       Time           : 17:32:50
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
#include<set>
#include<vector>
using namespace std;

#define MAXN 201

struct Rect
{
	double x1,y1,x2,y2;
};

int n,ca;
double s;
Rect r[MAXN];
set<double> xs,ys;
vector<double> x,y;

int main()
{
//	freopen("in_1151.txt","r",stdin);
	ca=0;
	while(scanf("%d",&n)&&n)
	{
		s=0;
		xs.clear();
		ys.clear();
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf%lf%lf",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2);
			xs.insert(r[i].x1);
			xs.insert(r[i].x2);
			ys.insert(r[i].y1);
			ys.insert(r[i].y2);
		}
		
		x.assign(xs.begin(),xs.end());
		y.assign(ys.begin(),ys.end());
		
		for(int i=0;i<x.size()-1;++i)
		{
			for(int j=0;j<y.size()-1;++j)
			{
				for(int k=0;k<n;++k)
				{
					if(r[k].x1<=x[i]&&r[k].x2>=x[i+1]
					&&r[k].y1<=y[j]&&r[k].y2>=y[j+1])
					{
						s+=(x[i+1]-x[i])*(y[j+1]-y[j]);
						break;
					}
				}
			}
		}
		
		printf("Test case #%d\nTotal explored area: %.2lf\n\n",++ca,s);

	}
	return 0;
}
