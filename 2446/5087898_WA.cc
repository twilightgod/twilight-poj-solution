/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Chessboard
*       ID             : 2446
*       Date           : 5/3/2009
*       Time           : 11:15:14
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<vector>
using namespace std;

int const move[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int const MAX = 32;
vector <int> table [MAX*MAX]; //图的邻接表
int X[MAX*MAX],Y[MAX*MAX];
bool tY[MAX*MAX];
bool hole[MAX][MAX];
int m,n,k;

bool path(int i)
{//寻找交替链
	for(int v = 0; v < table[i].size(); v++)
	{
		int t = table[i][v];
		if(!tY[t])
		{
			tY[t] = true;
			if((Y[t] < 0) || path(Y[t]))
			{
				X[i] = t, Y[t] = i;
				return true;
			}
		}
	}
	return false;
}

int solve(int num)// num 是顶点集X的数目
{
	int ans = 0;
	memset(X,-1,sizeof(X));
	memset(Y,-1,sizeof(Y));
	for(int i = 0; i < num; i++)
		if(X[i] < 0)
		{
			memset(tY,0,sizeof(tY));
			ans += path(i);
		}
		return ans;
}

int main()
{
	//freopen("in_2446.txt","r",stdin);
	cin>>m>>n>>k;
	memset(hole,false,sizeof(hole));
	for(int i=0;i<k;++i)
	{
		int u,v;
		cin>>v>>u;
		hole[--u][--v]=true;
	}
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(((i&1&&j&1)||(!(i&1)&&!(j&1)))&&!hole[i][j])
			{
				for(int t=0;j<4;++j)
				{
					int nr,nc;
					nr=i+move[t][0];
					nc=j+move[t][1];
					if(nr>=0&&nr<m&&nc>=0&&nc<n&&!hole[nr][nc])
					{
						table[i*n+j].push_back(nr*n+nc);
					}
				}
			}
		}
	}
	if(solve(m*n)*2+k==m*n)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}
