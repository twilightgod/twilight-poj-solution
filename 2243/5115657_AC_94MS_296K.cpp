/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Knight Moves
*       ID             : 2243
*       Date           : 5/8/2009
*       Time           : 12:30:2
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<queue>
using namespace std;

#define MAXN 8

struct Node
{
	int x,y;
};

const int move[8][2]={{-2,1},{-2,-1},{2,1},{2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
int ti[MAXN][MAXN];
queue<Node> q;
Node S,T;
int n,t;
char ch;

int main()
{
	//freopen("in_2243.txt","r",stdin);
	//cin>>t;
	while(1)
	{
		//cin>>>>S.x>>S.y>>T.x>>T.y;
		S.x=getchar()-'a';
		cin>>S.y;
		S.y--;
		getchar();
		T.x=getchar()-'a';
		cin>>T.y;
		T.y--;
		getchar();
		if(cin.eof())
		{
			break;
		}
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
				if(next.x>=0&&next.x<8&&next.y>=0&&next.y<8&&ti[next.x][next.y]==0)
				{
					ti[next.x][next.y]=ti[now.x][now.y]+1;
					q.push(next);
				}
			}
		}
		//cout<<ti[T.x][T.y]-1<<endl;
		cout<<"To get from "<<char(S.x+'a')<<S.y+1<<" to "<<char(T.x+'a')<<T.y+1<<" takes "<<ti[T.x][T.y]-1<<" knight moves.\n";
	}
	return 0;
}
