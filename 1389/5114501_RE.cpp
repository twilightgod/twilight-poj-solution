/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Area of Simple Polygons
*       ID             : 1389
*       Date           : 5/8/2009
*       Time           : 7:15:41
*       Computer Name  : EVERLASTING-PC
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

int n;
int s;
Rect r[MAXN];
set<int> xs,ys;
vector<int> x,y;

int main()
{
	//freopen("in_1389.txt","r",stdin);
	while(1)
	{
		n=0;
		s=0;
		xs.clear();
		ys.clear();
		for(int i=0;;++i)
		{
			scanf("%lf%lf%lf%lf",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2);
			if(r[i].x1==-1)
			{
				if(i==0)
				{
					return 0;
				}
				break;
			}
			xs.insert(r[i].x1);
			xs.insert(r[i].x2);
			ys.insert(r[i].y1);
			ys.insert(r[i].y2);
			n++;
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
		
		printf("%d\n",s);

	}
	return 0;
}
