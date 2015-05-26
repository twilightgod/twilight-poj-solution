/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : The Perfect Stall
*       ID             : 1274
*       Date           : 12/20/2008
*       Time           : 21:25:34
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<vector>
using namespace std;

#define MAXN 201

int X[MAXN],Y[MAXN];
bool tY[MAXN];
vector<int> table[MAXN];
int n,m;

bool path(int i)
{//寻找交替链
	for(int v=0;v<table[i].size();v++)
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
	//freopen("in_1274.txt","r",stdin);
	while(scanf("%d%d",&n,&m)!=-1)
	{
		for(int i=0;i<n;++i)
		{
			table[i].clear();
		}
		for (int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d",&u);
			for (int j=0;j<u;++j)
			{
				scanf("%d",&v);
				v--;
				table[i].push_back(v);
			}
		}
		printf("%d\n",solve(n));
	}
	return 0;
}
