/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Stars
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2352
*       ID             : 2352_ZHA
*       Date           : 5/29/2009
*       Time           : 11:4:45
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
using namespace std;

#define MAXR 32001
#define MAXN 15000

int C[MAXR];
int Level[MAXN];
int n;

inline int LowBit(int x)
{
	return x&(-x);
}

void Modify(int i,int delta)
{
	while(i<MAXR)
	{
		C[i]+=delta;
		i+=LowBit(i);
	}
}

int Sum(int i)
{
	int ret=0;
	while(i>0)
	{
		ret+=C[i];
		i-=LowBit(i);
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2352_ZHA.txt","r",stdin);
#endif
	memset(C,0,sizeof(C));
	memset(Level,0,sizeof(Level));
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x++;
		Level[Sum(x)]++;
		Modify(x,1);
	}
	for(int i=0;i<n;++i)
	{
		printf("%d\n",Level[i]);
	}
	return 0;
}
