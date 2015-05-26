/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Knight Moves
*       ID             : 1915
*       Date           : 4/26/2009
*       Time           : 9:55:35
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<queue>
using namespace std;

#define MAXN 300

struct Node
{
	int x,y;
};

const int move[8][2]={{-2,1},{-2,-1},{2,1},{2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
int ti[MAXN][MAXN];
queue<Node> q;
Node S,T;
int n,t;

int main()
{
	//freopen("in_1915.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>n>>S.x>>S.y>>T.x>>T.y;
		while(!q.empty())
		{
			q.pop();
		}
		memset(ti,0,sizeof(ti));
		ti[S.x][S.y]=1;
		q.push(S);
		while(!q.empty())
		{
			Node now=q.front();
			q.pop();
			if(now.x==T.x&&now.y==T.y)
			{
				break;
			}
			Node next;
			for(int i=0;i<8;++i)
			{
				next.x=now.x+move[i][0];
				next.y=now.y+move[i][1];
				if(next.x>=0&&next.x<n&&next.y>=0&&next.y<n&&ti[next.x][next.y]==0)
				{
					ti[next.x][next.y]=ti[now.x][now.y]+1;
					q.push(next);
				}
			}
		}
		cout<<ti[T.x][T.y]-1<<endl;
	}
	return 0;
}
