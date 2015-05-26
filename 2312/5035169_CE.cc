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
using namespace std;
#define MAXN 302
const short move[4][2]={{0,1},{1,0},{-1,0},{0,-1}};


int m,n;
int t[MAXN][MAXN];
bool bb[MAXN][MAXN];

struct Node
{
	int x,y;
	Node(int _x,int _y)
	{
		x=_x;
		y=_y;
	}
	Node(){}
};

Node Y,T;

template<typename T>
struct cmp{
  bool   operator()(T     &lhs,T     &     rhs){     return     t[lhs.x][lhs.y]>t[rhs.x][rhs.y];}       
  };           

//queue<Node> q;
priority_queue<Node,vector<Node>,cmp<Node>> q;


int main()
{
	//freopen("in_2312.txt","r",stdin);
	while(cin>>m>>n&&m)
	{
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
			Node now=q.top();
			if(now.x==T.x&&now.y==T.y)
			{
				break;
			}
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
				else  if(t[next.x][next.y]==0)
				{
					t[next.x][next.y]=t[now.x][now.y]+1;
					q.push(next);
				}
			}
		}
		cout<<t[T.x][T.y]-1<<endl;
	}
	return 0;
}

