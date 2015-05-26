/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Image Perimeters
*       ID             : 1111
*       Date           : 1/8/2009
*       Time           : 0:24:13
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 20

const short int move[8][2]={{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};
bool map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int m,n,sx,sy,ans;

void DFS(int x,int y)
{
	visited[x][y]=true;
	int nx,ny;
	for (int i=0;i<8;++i)
	{
		nx=x+move[i][0];
		ny=y+move[i][1];
		if (nx>=0&&nx<m&&ny>=0&&ny<n&&map[nx][ny])
		{
			if (!visited[nx][ny])
			{
				DFS(nx,ny);
			}
		}
		else if (i<4)
		{
			ans++;
		}
	}
}

int main()
{
	while (cin>>m>>n>>sx>>sy&&m)
	{
		getchar();
		for (int i=0;i<m;++i,getchar())
		{
			for (int j=0;j<n;++j)
			{
				map[i][j]=getchar()=='X'?true:false;
			}
		}
		ans=0;
		memset(visited,false,sizeof(visited));
		DFS(sx-1,sy-1);
		cout<<ans<<endl;
	}
	return 0;
}
