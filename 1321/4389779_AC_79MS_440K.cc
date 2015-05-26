/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : 棋盘问题
*       ID             : 1321
*       Date           : 11/18/2008
*       Time           : 14:37:18
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 8

bool map[MAXN][MAXN];
bool row[MAXN],col[MAXN];
int i,j,n,c,m;
char ch;

void dfs(int dep,int x,int y)
{
	if(dep==m)
	{
		c++;
		return;
	}
	for(int i=x;i<n;++i)
	{
		int j=y+1;
		if(i!=x)
		{
			j=0;
		}
		for(;j<n;++j)
		{
			if(map[i][j]&&row[i]&&col[j])
			{
				col[j]=row[i]=false;
				dfs(dep+1,i,j);
				col[j]=row[i]=true;
			}
		}
	}
}

int main()
{
	//freopen("in_1321.txt","r",stdin);
	while(cin>>n>>m)
	{
		getchar();
		if(m==-1&&n==-1) break;
		c=0;
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				cin>>ch;
				map[i][j]=ch=='#'?true:false;
			}
		}
		memset(row,true,sizeof(row));
		memset(col,true,sizeof(col));
		dfs(0,0,-1);
		cout<<c<<endl;
	}
	return 0;
}
