#include<iostream>
#include<queue>
using namespace std;

#define MAXM 1002
#define MAXN 82

struct QN
{
	int x,y;
	QN(int _x,int _y)
	{
		x=_x;
		y=_y;
	}
	QN(){}
};

const int move[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

int m,n,best;
bool map[MAXM][MAXN];

void BFS(int sx,int sy)
{
	int si=0;
	queue<QN> q;
	q.push(QN(sx,sy));
	map[sx][sy]=false;
	while(!q.empty())
	{
		si++;
		QN now=q.front();
		q.pop();
		QN next;
		for(int i=0;i<4;++i)
		{
			next.x=now.x+move[i][0];
			next.y=now.y+move[i][1];
			if(map[next.x][next.y])
			{
				q.push(next);
				map[next.x][next.y]=false;
			}
		}
	}
	if(si>best)
	{
		best=si;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	best=0;
	memset(map,false,sizeof(map));
	for(int i=1;i<=m;++i)
	{
		getchar();
		for(int j=1;j<=n;++j)
		{
			if(getchar()=='*')
			{
				map[i][j]=true;
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(map[i][j])
			{
				BFS(i,j);
			}
		}
	}
	printf("%d\n",best);
	return 0;
}

