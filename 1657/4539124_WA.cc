/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Distance on Chessboard
*       ID             : 1657
*       Date           : 1/7/2009
*       Time           : 11:50:24
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct Node
{
	int x,y;
	Node(int _x,int _y):x(_x),y(_y){}
};

const int move1[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int move2[4][2]={{-1,1},{1,1},{1,-1},{-1,-1}};
int map[8][8];
int sx,sy,ex,ey;
int test;
string s1,s2;
queue<Node> q;

void BFS(int t)
{
	while (!q.empty())
	{
		q.pop();
	}
	memset(map,0,sizeof(map));
	map[sx][sy]=1;
	q.push(Node(sx,sy));
	while (!q.empty())
	{
		int x,y,nx,ny;
		x=q.front().x;
		y=q.front().y;
		q.pop();
		if (x==ex&&y==ey)
		{
			break;
		}
		int k=t==0?1:8;
		if (t<3)
		{
			for (int i=0;i<4;++i)
			{
				nx=x;
				ny=y;
				for (int j=0;j<k;++j)
				{
					nx+=move1[i][0];
					ny+=move1[i][1];
					if (!(nx>=0&&nx<8&&ny>=0&&ny<8)||map[nx][ny])
					{
						break;
					}
					else
					{
						q.push(Node(nx,ny));
						map[nx][ny]=map[x][y]+1;
					}
				}
			}
		}
		if (t<2||t==3)
		{
			for (int i=0;i<4;++i)
			{
				nx=x;
				ny=y;
				for (int j=0;j<k;++j)
				{
					nx+=move2[i][0];
					ny+=move2[i][1];
					if (!(nx>=0&&nx<8&&ny>=0&&ny<8)||map[nx][ny])
					{
						break;
					}
					else
					{
						q.push(Node(nx,ny));
						map[nx][ny]=map[x][y]+1;
					}
				}
			}
		}
	}
	if (map[ex][ey])
	{
		cout<<map[ex][ey]-1;
	}
	else
	{
		cout<<"Inf";
	}
}

int main()
{
//	freopen("in_1657.txt","r",stdin);
	cin>>test;
	while (test--)
	{
		cin>>s1>>s2;
		sx=s1[1]-'0'-1;
		sy=7-(s1[0]-'a');
		ex=s2[1]-'0'-1;
		ey=7-(s2[0]-'a');
		for (int i=0;i<4;++i)
		{
			if (i)
			{
				cout<<' ';
			}
			BFS(i);
		}
		cout<<endl;
	}
	return 0;
}
