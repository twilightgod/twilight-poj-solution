#include <iostream>
#include <algorithm>
using namespace std;

struct Point2D
{
	double x,y;
};

struct Tower
{
	Point2D p;
	double t;
	bool operator < (const Tower &a)
	{
		return t<a.t;
	}
};

double Distance(Point2D& a, Point2D& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double Norm(Point2D& a)
{
	return sqrt(a.x*a.x+a.y*a.y);
}

const int n = 3;
double C;
Tower ts[n];
double dis[n];
double time[n];
double dif[n];
Point2D delta[n];
Point2D ans;
int ca = 0;
bool found;

double speed = 1e-6;
double eps = 1e-6;

void Estimate()
{
	ans.x = (ts[0].p.x+ts[1].p.x+ts[2].p.x)/3;
	ans.y = (ts[0].p.y+ts[1].p.y+ts[2].p.y)/3;
	
	found = false;

	while(1)
	{
		for(int i=0;i<n;++i)
		{
			dis[i] = Distance(ans, ts[i].p);
			time[i] = dis[i]/C;
		}

		for(int i=1;i<n;++i)
		{
			dif[i] = time[i]-time[0]-ts[i].t;

			delta[i].x = ts[i].p.x - ans.x;
			delta[i].y = ts[i].p.y - ans.y;

// 			if(dif[i]<0)
// 			{
// 				delta[i].x = -delta[i].x;
// 				delta[i].y = -delta[i].y;
// 			}

			double len = Norm(delta[i]);

			if(fabs(delta[i].x)>eps)
			{
				delta[i].x *= (dif[i]/len);
			}
			if(fabs(delta[i].y)>eps)
			{
				delta[i].y *= (dif[i]/len);
			}
		}

		Point2D dir;
		dir.x = delta[1].x + delta[2].x;
		dir.y = delta[1].y + delta[2].y;

		double len = Norm(dir);

		if(fabs(dif[1]+dif[2])<eps/10)
		{
			break;
		}

// 		if (fabs(dir.x)>eps)
// 		{
// 			dir.x /= len;
// 		}
// 		if (fabs(dir.y)>eps)
// 		{
// 			dir.y /= len;
// 		}

		ans.x += dir.x/**fabs(dif[1]+dif[2])*/*C/1000;
		ans.y += dir.y/**fabs(dif[1]+dif[2])*/*C/1000;
		//printf("%.6f %.6f\n", ans.x, ans.y);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	while(cin>>C&&C)
	{
		C/=1000;

		printf("Case %d:\n", ++ca);
		for(int i=0;i<n;++i)
		{
			cin>>ts[i].p.x>>ts[i].p.y;
		}
		for(int i=0;i<n;++i)
		{
			cin>>ts[i].t;
		}

		sort(ts, ts+n);

		Estimate();

		printf("%.6f %.6f\n", ans.x, ans.y);
	}
	return 0;
}