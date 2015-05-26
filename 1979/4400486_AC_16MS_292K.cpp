/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Red and Black
*       ID             : 1979
*       Date           : 11/20/2008
*       Time           : 22:23:39
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 20

int move[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool map[MAXN][MAXN];
int m,n,i,j,sx,sy,ans;
char ch;

void DFS(int x,int y)
{
	map[x][y]=false;
	ans++;
	int x1,y1;
	for(int i=0;i<4;++i)
	{
		x1=x+move[i][0];
		y1=y+move[i][1];
		if(x1>=0&&y1>=0&&x1<m&&y1<n&&map[x1][y1])
		{
			DFS(x1,y1);
		}
	}
}

int main()
{
	//freopen("in_1979.txt","r",stdin);
	while(cin>>n>>m&&m)
	{
		ans=0;
		//getchar();
		for(i=0;i<m;++i)
		{
			for(j=0;j<n;++j)
			{
				cin>>ch;
				if(ch=='@')
				{
					sx=i;
					sy=j;
				}
				else if(ch=='.')
				{
					map[i][j]=true;
				}
				else
				{
					map[i][j]=false;
				}
			}
		}
		DFS(sx,sy);
		cout<<ans<<endl;
	}
	return 0;
}
