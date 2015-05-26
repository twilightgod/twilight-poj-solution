/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sudoku Checker
*       ID             : 3435
*       Date           : 11/22/2008
*       Time           : 22:26:15
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 11

int map[MAXN*MAXN][MAXN*MAXN];
bool hash[MAXN*MAXN];
int i,j,n;

bool Check(int x0,int y0)
{
	memset(hash,false,sizeof(hash));
	for(int i=x0;i<x0+n;++i)
	{
		for(int j=y0;j<y0+n;++j)
		{
			if(map[i][j])
			{
				if(hash[map[i][j]])
				{
					return false;
				}
				else
				{
					hash[map[i][j]]=true;
				}
			}
		}
	}
	return true;
}

int main()
{
	//freopen("in_3435.txt","r",stdin);
	while(cin>>n)
	{
		for(i=0;i<n*n;++i)
		{
			for(j=0;j<n*n;++j)
			{
				cin>>map[i][j];
			}
		}
		if(Check(0,0)&&Check(0,n)&&Check(n,0)&&Check(n,n))
		{
			cout<<"CORRECT\n";
		}
		else
		{
			cout<<"INCORRECT\n";
		}
	}
	return 0;
}
