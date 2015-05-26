/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Asteroids
*       ID             : 3041
*       Date           : 4/24/2009
*       Time           : 21:50:8
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<vector>
using namespace std;

#define MAXN 501

vector<int> lin[MAXN];
int X[MAXN],Y[MAXN];
bool tY[MAXN];
int n,m;

bool path(int i)
{
	for(int v = 0; v < lin[i].size(); v++)
	{
		int t = lin[i][v];
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
	for(int i = 1; i <= num; i++)
		if(X[i] < 0)
		{
			memset(tY,0,sizeof(tY));
			ans += path(i);
		}
		return ans;
}

int main()
{
	//freopen("in_3041.txt","r",stdin);
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;++i)
		{
			lin[i].clear();
		}
		for(int i=0;i<m;++i)
		{
			int u,v;
			cin>>u>>v;
			lin[u].push_back(v);
		}
		cout<<solve(n)<<endl;
	}
	return 0;
}
