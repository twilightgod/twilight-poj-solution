/**********************************************************************
*       Online Judge  : POJ
*       Project  : 2386
*       Date : 11/15/2008
*       Time : 23:15:58:
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 101

int move[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
bool map[MAXN][MAXN];
int n,m,i,j,sum;
char ch;

void DFS(int x,int y)
{
	map[x][y]=false;
	int nx,ny;
	for(int k=0;k<8;++k)
	{
		nx=x+move[k][0];
		ny=y+move[k][1];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&map[nx][ny])
		{
			DFS(nx,ny);
		}
	}
}

int main()
{
	//freopen("in_2386.txt","r",stdin);
	while(cin>>n>>m)
	{
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				cin>>ch;
				map[i][j]=ch=='W'?true:false;
			}
		}
		sum=0;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				if(map[i][j])
				{
					sum++;
					DFS(i,j);
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
