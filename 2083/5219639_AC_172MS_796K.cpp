/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Fractal
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2083
*       ID             : 2083
*       Date           : 5/25/2009
*       Time           : 13:33:45
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

#define MAXN 729

int n;
char f[MAXN][MAXN];
int t[10];

void DFS(int x,int y,int size)
{
	if(size==1)
	{
		f[x][y]='X';
		return;
	}
	DFS(x,y,size-1);
	DFS(x,y+2*t[size-2],size-1);
	DFS(x+t[size-2],y+t[size-2],size-1);
	DFS(x+2*t[size-2],y,size-1);
	DFS(x+2*t[size-2],y+2*t[size-2],size-1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2083.txt","r",stdin);
#endif
	t[0]=1;
	for(int i=1;i<10;++i)
	{
		t[i]=t[i-1]*3;
	}
	while(cin>>n&&n!=-1)
	{
		for(int i=0;i<t[n-1];++i)
		{
			for(int j=0;j<t[n-1];++j)
			{
				f[i][j]=' ';
			}
		}
		DFS(0,0,n);
		for(int i=0;i<t[n-1];++i)
		{
			for(int j=0;j<t[n-1];++j)
			{
				printf("%c",f[i][j]);
			}
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
}
