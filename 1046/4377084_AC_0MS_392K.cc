#include<iostream>
#include<math.h>
using namespace std;

#define MAXINT 2147483647

struct Color
{
	int r,g,b;
};

Color c[16];
Color temp;

inline double dis(Color x,Color y)
{
	return sqrt((double)(x.r-y.r)*(x.r-y.r)+(x.g-y.g)*(x.g-y.g)+(x.b-y.b)*(x.b-y.b));
}

int main()
{
	while(1)
	{
		for(int i=0;i<16;++i)
		{
			if(scanf("%d%d%d",&c[i].r,&c[i].g,&c[i].b)==-1) return 0;
		}
		while(1)
		{
			scanf("%d%d%d",&temp.r,&temp.g,&temp.b);
			if(temp.r==-1&&temp.g==-1&&temp.b==-1)
			{
				break;
			}
			double m=MAXINT;
			int t;
			for(int i=0;i<16;++i)
			{
				double d=dis(temp,c[i]);
				if(d<m)
				{
					m=d;
					t=i;
				}
			}
			printf("(%d,%d,%d) maps to (%d,%d,%d)\n",temp.r,temp.g,temp.b,c[t].r,c[t].g,c[t].b);
		}
	}
	return 0;
}
