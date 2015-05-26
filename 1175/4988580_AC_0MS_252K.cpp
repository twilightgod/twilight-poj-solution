/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Starry Night
*       ID             : 1175
*       Date           : 4/16/2009
*       Time           : 12:10:51
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;

#define MAXN 100
#define MAXS 26
#define MAXL 160

struct Point
{
	int x,y;
	Point(int _x,int _y)
	{
		x=_x;
		y=_y;
	}
};

const short move[8][2]={{-1,-1},{-1,1},{1,1},{1,-1},{0,1},{1,0},{-1,0},{0,-1}};

short map[MAXN][MAXN];
double hash[MAXS];
int m,n,ns;
double sum;

double GetDis(Point a,Point b)
{
	return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void BFS(Point a)
{
	map[a.x][a.y]=0;
	double sum=0;
	vector<Point> list;
	queue<Point> t;
	t.push(a);
	list.push_back(a);
	while(!t.empty())
	{
		Point p=t.front();
		t.pop();
		for(int i=0;i<8;++i)
		{
			Point next(p.x+move[i][0],p.y+move[i][1]);
			if(next.x>=0&&next.y>=0&&next.x<m&&next.y<n&&map[next.x][next.y]==1)
			{
				t.push(next);
				for(int j=0;j<(int)list.size();++j)
				{
					sum+=GetDis(list[j],next);
				}
				list.push_back(next);
				map[next.x][next.y]=0;
			}
		}
	}
	bool newc=true;
	int color;
	for(int i=0;i<ns;++i)
	{
		if(fabs(sum-hash[i])<1e-6)
		{
			newc=false;
			color=i+'a';
			break;
		}
	}
	if(newc)
	{
		color=ns+'a';
		hash[ns++]=sum;
	}
	for(int i=0;i<(int)list.size();++i)
	{
		map[list[i].x][list[i].y]=color;
	}
}

int main()
{
	//freopen("in_1175.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i)
	{
		getchar();
		for(int j=0;j<n;++j)
		{
			map[i][j]=getchar()-'0';
		}
	}
	ns=0;
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(map[i][j]==1)
			{
				BFS(Point(i,j));
			}
		}
	}
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(map[i][j])
			{
				printf("%c",(char)map[i][j]);
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}
