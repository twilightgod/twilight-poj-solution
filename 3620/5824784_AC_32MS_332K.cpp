/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Avoid The Lakes
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3620
*       ID             : 3620
*       Date           : 9/7/2009
*       Time           : 17:55:39
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

#define MAXN 101
int n,m,k;
bool map[MAXN][MAXN];
int best,sz;

void DFS(int x,int y)
{
	if(x<1||y<1||x>n||y>m||map[x][y])
	{
		return;
	}
	sz++;
	map[x][y]=true;
	DFS(x+1,y);
	DFS(x-1,y);
	DFS(x,y+1);
	DFS(x,y-1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3620.txt","r",stdin);
#endif
	memset(map,true,sizeof(map));
	cin>>n>>m>>k;
	for(int i=0;i<k;++i)
	{
		int u,v;
		cin>>u>>v;
		map[u][v]=false;
	}
	best=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(!map[i][j])
			{
				sz=0;
				DFS(i,j);
				if(sz>best)
				{
					best=sz;
				}
			}
		}
	}
	cout<<best<<endl;
	return 0;
}
