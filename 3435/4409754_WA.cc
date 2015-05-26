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
bool ans;

bool Check1(int i)
{
	memset(hash,false,sizeof(hash));
	for(int j=0;j<n*n;++j)
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
	return true;
}

bool Check2(int j)
{
	memset(hash,false,sizeof(hash));
	for(int i=0;i<n*n;++i)
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
	return true;
}

bool Check3(int x0,int y0)
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
		for(int i=0;i<n*n;++i)
		{
			for(int j=0;j<n*n;++j)
			{
				cin>>map[i][j];
			}
		}
		for(int i=0;i<n&&ans;++i)
		{
			for(int j=0;j<n&&ans;++j)
			{
				ans=Check3(i*n,j*n);
			}
		}
		for(int i=0;i<n*n&&ans;++i)
		{
			ans=Check1(i);
		}
		for(int j=0;j<n*n&&ans;++j)
		{
			ans=Check2(j);
		}
		if(ans)
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
