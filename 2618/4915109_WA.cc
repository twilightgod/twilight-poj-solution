#include<iostream>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

#define MAXN 200
#define MAXL 10

//0 right,1 up,2 left,3 down
const int move[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
//roll[i][j] means move to direction i and the original side is in side j
//the value is the new side where the original side is
const int roll[4][6]={{1,5,2,0,4,3},{2,1,5,3,0,4},{3,0,2,5,4,1},{4,1,0,3,5,2}};
struct St
{
	int x,y,l;
	St(int _x,int _y,int _l)
	{
		x=_x;
		y=_y;
		l=_l;
	}
	St(){}
};

int t[MAXN][MAXN][MAXL];
bool b[4][MAXN][MAXN];
int m,n,sx,sy,ex,ey;
bool god;
stringstream ss;
string str;
queue<St> q;

void input()
{
	int step=0;
	int bx,by;
	getchar();
	while(1)
	{
		getline(cin,str);
		if(cin.eof())
		{
			break;
		}
		if(str=="v")
		{
			step=1;
			continue;
		}
		if(str=="h")
		{
			step=2;
			continue;
		}
		if(step==1)
		{
			ss.clear();
			ss<<str;
			ss>>bx>>by;
			b[0][bx][by]=b[2][bx][by+1]=true;
			continue;
		}
		if(step==2)
		{
			ss.clear();
			ss<<str;
			ss>>bx>>by;
			b[3][bx][by]=b[1][bx+1][by]=true;
			continue;
		}
	}
	//getchar();
}

void bfs()
{
	t[sx][sy][0]=1;
	god=true;
	while(!q.empty())
	{
		q.pop();
	}
	q.push(St(sx,sy,0));
	while(!q.empty())
	{
		St now=q.front();
		St next;
		q.pop();
		if(now.x==ex&&now.y==ey&&now.l==0)
		{
			god=false;
			break;
		}
		for(int i=0;i<4;++i)
		{
			next.x=now.x+move[i][0];
			next.y=now.y+move[i][1];
			next.l=roll[i][now.l];
			if((t[next.x][next.y][next.l]==0)&&!b[i][now.x][now.y])
			{
				q.push(next);
				t[next.x][next.y][next.l]=t[now.x][now.y][now.l]+1;
			}
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//while(1)
	{
		//if(cin.eof())
		//{
		//	break;
		//}
		cin>>m>>n>>sx>>sy>>ex>>ey;
		//if(cin.eof())
		//{
		//	break;
		//}
		memset(t,0,sizeof(t));
		memset(b,false,sizeof(b));
		for(int i=0;i<=m+2;++i)
		{
			b[0][i][n]=b[2][i][1]=true;
		}
		for(int j=0;j<=n+2;++j)
		{
			b[1][1][j]=b[3][m][j]=true;
		}
		input();
		bfs();
		if(!god)
		{
			cout<<t[ex][ey][0]-1<<endl;
		}
		else
		{
			cout<<"no\n";
		}
	}
	return 0;
}
