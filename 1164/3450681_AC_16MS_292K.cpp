#include<iostream>
using namespace std;
#define MAXN 50

struct Node
{
	int x,y;
};

int move[2][4]={{0,-1,0,1},{-1,0,1,0}};
int go[4]={1,2,4,8};
int wall[MAXN][MAXN];
bool map[MAXN][MAXN];
int i,j,n,m,total,best,t,head,tail;
Node qu[MAXN*MAXN];

inline int max(int x,int y)
{
	return x>y?x:y;
}

int bfs(int x0,int y0)
{
	int x1,y1,i,t=1;
	map[x0][y0]=true;
	head=-1;
	tail=0;
	qu[0].x=x0;
	qu[0].y=y0;
	while(head!=tail)
	{
		head++;
		x0=qu[head].x;
		y0=qu[head].y;
		for(i=0;i<4;++i)
		{
			if((wall[x0][y0]&go[i])==0)
			{
				x1=x0+move[0][i];
				y1=y0+move[1][i];
				if(!map[x1][y1])
				{
					map[x1][y1]=true;
					tail++;
					qu[tail].x=x1;
					qu[tail].y=y1;
					t++;
				}
			}
		}
	}
	return t;
}

int main()
{
//	freopen("d:/in.txt","r",stdin);
	while(cin>>m>>n)
	{
		for(i=0;i<m;++i)
		{
			for(j=0;j<n;++j)
			{
				cin>>wall[i][j];
			}
		}
		memset(map,false,sizeof(map));
		total=best=0;
		for(i=0;i<m;++i)
		{
			for(j=0;j<n;++j)
			{
				if(!map[i][j])
				{
					best=max(best,bfs(i,j));
					total++;
				}
			}
		}
		cout<<total<<endl<<best<<endl;
	}
	return 0;
}