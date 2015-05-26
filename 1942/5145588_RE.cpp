/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Paths on a Grid
*       ID             : 1942
*       Date           : 5/13/2009
*       Time           : 13:30:29
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 1000

unsigned m,n;
unsigned f[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1942.txt","r",stdin);
#endif
	while(cin>>m>>n)
	{
		if(m==0&&n==0)
		{
			break;
		}
		for(int i=0;i<=m;++i)
		{
			f[i][0]=1;
		}
		for(int j=0;j<=n;++j)
		{
			f[0][j]=1;
		}
		for(int i=1;i<=m;++i)
		{
			for(int j=1;j<=n;++j)
			{
				f[i][j]=f[i-1][j]+f[i][j-1];
			}
		}
		cout<<f[m][n]<<endl;
	}
	return 0;
}
