/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Oil Deposits
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1562
*       ID             : 1562
*       Date           : 9/11/2009
*       Time           : 11:29:38
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

#define MAXN 100

char map[MAXN][MAXN];
int m,n,ans;

void DFS(int x,int y)
{
	if(x<0||y<0||x>=m||y>=n||map[x][y]=='*')
	{
		return;
	}
	map[x][y]='*';
	
	DFS(x+1,y);
	DFS(x,y+1);
	DFS(x-1,y);
	DFS(x,y-1);
	
	DFS(x+1,y-1);
	DFS(x+1,y+1);
	DFS(x-1,y-1);
	DFS(x-1,y+1);

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1562.txt","r",stdin);
#endif
	while(scanf("%d%d\n",&m,&n)&&m)
	{
		for(int i=0;i<m;++i)
		{
			scanf("%s\n",&map[i]);
		}
		ans=0;
		for(int i=0;i<m;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(map[i][j]=='@')
				{
					ans++;
					DFS(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
