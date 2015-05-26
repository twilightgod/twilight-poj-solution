/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Chambers Ceramic Conundrum
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2877
*       ID             : 2877
*       Date           : 6/29/2009
*       Time           : 7:53:49
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
using namespace std;

//Tiles
int tile[7][4][3][2]={
	
	{
	{{0,1},{0,2},{0,3}},
	{{1,0},{2,0},{3,0}},
	{{0,0},{0,0},{0,0}},
	{{0,0},{0,0},{0,0}},
	},
	
	{
	{{0,1},{1,0},{1,1}},
	{{0,0},{0,0},{0,0}},
	{{0,0},{0,0},{0,0}},
	{{0,0},{0,0},{0,0}},
	},

	{
	{{0,1},{1,1},{1,2}},
	{{1,0},{1,-1},{2,-1}},
	{{0,0},{0,0},{0,0}},
	{{0,0},{0,0},{0,0}},
	},

	{
	{{0,1},{1,0},{1,-1}},
	{{1,0},{1,1},{2,1}},
	{{0,0},{0,0},{0,0}},
	{{0,0},{0,0},{0,0}},
	},

	{
	{{1,0},{1,1},{1,2}},
	{{0,1},{1,0},{2,0}},
	{{0,1},{0,2},{1,2}},
	{{1,0},{2,0},{2,-1}},
	},

	{
	{{0,1},{1,0},{0,2}},
	{{0,1},{1,1},{2,1}},
	{{1,0},{1,-1},{1,-2}},
	{{1,0},{2,0},{2,1}},
	},

	{
	{{1,-1},{1,0},{1,1}},
	{{1,0},{2,0},{1,1}},
	{{0,1},{0,2},{1,1}},
	{{0,1},{1,1},{-1,1}}
	}
};

int cnt[7]={2,1,2,2,4,4,4};

char map[6][6];

int t,ca;
int a[9];
bool god;

//Dancing Links
int L[11],R[11];

void InitDL()
{
	for(int i=1;i<11;++i)
	{
		L[i]=i-1;
	}
	for(int i=0;i<10;++i)
	{
		R[i]=i+1;
	}
}

void FindBlank(int &x,int &y)
{
	for(x=0;x<6;++x)
	{
		for(y=0;y<6;++y)
		{
			if(map[x][y]==' ')
			{
				return;
			}
		}
	}
}

bool IsLegal(int x,int y,int ti,int ro)
{
	int dx,dy;
	for(int i=0;i<3;++i)
	{
		dx=x+tile[ti][ro][i][0];
		dy=y+tile[ti][ro][i][1];
		if(dx<0||dy<0||dx>=6||dy>=6||map[dx][dy]!=' ')
		{
			return false;
		}
	}
	return true;
}

void PutTile(int x,int y,int ti,int ro,char ch)
{
	int dx,dy;
	map[x][y]=ch;
	for(int i=0;i<3;++i)
	{
		dx=x+tile[ti][ro][i][0];
		dy=y+tile[ti][ro][i][1];
		map[dx][dy]=ch;
	}
}

void DFS(int dep)
{
	if(dep==9)
	{
		god=false;
		return;
	}

	int x,y;
	FindBlank(x,y);

	bool tried[7]={false};
	//Tile
	for(int p=R[0];p!=10;p=R[p])
	{
		int ti=a[p-1];
		if(tried[ti])
		{
			continue;
		}
		tried[ti]=true;
		//Rotation
		for(int ro=0;ro<cnt[ti];++ro)
		{
			if(IsLegal(x,y,ti,ro))
			{
				PutTile(x,y,ti,ro,char(p-1+'A'));
				R[L[p]]=R[p];
				L[R[p]]=L[p];
				DFS(dep+1);
				if(!god)
				{
					return;
				}
				//Backtrace
				PutTile(x,y,ti,ro,' ');
				R[L[p]]=p;
				L[R[p]]=p;
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2877.txt","r",stdin);
#endif
	ca=0;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<9;++i)
		{
			scanf("%d",&a[i]);
			a[i]--;
		}
		memset(map,' ',sizeof(map));
		god=true;
		InitDL();
		DFS(0);
		printf("Data Set %d\n",++ca);
		if(god)
		{
			printf("The floor may not be tiled.\n\n");
		}
		else
		{
			printf("The floor may be tiled.\n");
			for(int i=0;i<6;++i)
			{
				for(int j=0;j<6;++j)
				{
					printf("%c",map[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	printf("End of Output\n");
	return 0;
}
