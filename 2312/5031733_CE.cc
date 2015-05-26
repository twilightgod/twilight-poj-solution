
/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Battle City
*       ID             : 2312
*       Date           : 4/22/2009
*       Time           : 22:15:42
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<queue>
usingnamespace std;
#define MAXN 302
constshort move[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
structNode
{
	int x,y;
	Node(int _x,int _y)
	{
		x=_x;
		y=_y;
	}
	Node(){}
};
queue<Node> q;
int m,n;
int t[MAXN][MAXN];
bool bb[MAXN][MAXN];
Node Y,T;
intmain()
{
	//freopen("in_2312.txt","r",stdin);
	while(cin>>m>>n&&m)
	{
memset(bb,false,sizeof(bb));
		for(int i=0;i<=m+1;++i)
		{
			for(int j=0;j<=n+1;++j)
			{
				t[i][j]=-1;
			}
		}
		for(int i=1;i<=m;++i)
		{
			getchar();
			for(int j=1;j<=n;++j)
			{
				switch(getchar())
				{
				case'Y':
					Y.x=i;
					Y.y=j;
					t[i][j]=1;
					break;
				case'T':
					T.x=i;
					T.y=j;
					t[i][j]=0;
					break;
				case'B':
					t[i][j]=-2;
bb[i][j]=true;
					break;
				case'E':
					t[i][j]=0;
				}
			}
		}
		while(!q.empty())
		{
			q.pop();
		}
		q.push(Y);
		while(!q.empty())
		{
			Node now=q.front();
			q.pop();
			Node next;
			for(int i=0;i<4;++i)
			{
				next.x=now.x+move[i][0];
				next.y=now.y+move[i][1];
				if(t[next.x][next.y]==-2)
				{
					t[next.x][next.y]=t[now.x][now.y]+2;
					q.push(next);
				}
				else  if(t[next.x][next.y]==0||t[next.x][next.y]>t[now.x][now.y]+1)
				{
				if(!bb[now.x][now.y]){	t[next.x][next.y]=t[now.x][now.y]+1;
					q.push(next);}
				}
			}
		}
		cout<<t[T.x][T.y]-1<<endl;
	}
	return0;
}
