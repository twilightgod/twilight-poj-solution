#include<iostream>
#include<fstream>
using namespace std;

#define MAXN 1002

struct Point
{
	int x,y;
	Point(int _x=0,int _y=0)
	{
		x=_x;
		y=_y;
	}
};

int i,j,r,c,t,ti,fx,fy,head,tail,x,y,fx2,fy2,l1;
char cc;
bool map[MAXN][MAXN];
int dis[MAXN][MAXN];
Point queue[MAXN*MAXN];

const int m[2][4]={{-1,1,0,0},{0,0,1,-1}};

void bfs()
{
		memset(dis,-1,sizeof(dis));
		dis[fx][fy]=0;
		head=-1;tail=0;
		queue[0]=Point(fx,fy);
		l1=0;
		while(head<=tail)
		{
			head++;
			for(i=0;i<4;++i)
			{
				x=queue[head].x+m[0][i];
				y=queue[head].y+m[1][i];
				if(map[x][y]&&dis[x][y]==-1)
				{
					dis[x][y]=dis[queue[head].x][queue[head].y]+1;
					if(dis[x][y]>l1)
					{
						l1=dis[x][y];
						fx2=x;
						fy2=y;
					}
					tail++;
					queue[tail]=Point(x,y);
				}

			}
		}
}

int main()
{
	scanf("%d",&t);
	for(ti=0;ti<t;++ti)
	{
		memset(map,false,sizeof(map));
		scanf("%d %d",&c,&r);
		scanf("%c",&cc);
		for(i=1;i<=r;++i)
		{
			for(j=1;j<=c;++j)
			{
				scanf("%c",&cc);
				if(cc=='.')
				{
					map[i][j]=true;
					fx=i;
					fy=j;
				}
			}
			scanf("%c",&cc);
		}

		bfs();
		fx=fx2;
		fy=fy2;
		bfs();
		printf("Maximum rope length is %d.\n",l1);
	}
	return 0;
}