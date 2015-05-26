/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Sum of Factorials
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1775
*       ID             : 1775
*       Date           : 5/27/2009
*       Time           : 16:54:14
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
using namespace std;

#define MAXN 10

int f[MAXN];
int n;
bool god;

void DFS(int dep,int s)
{
	if(s==n)
	{
		god=false;
		return;
	}
	if(dep==10)
	{
		return;
	}
	if(s+f[dep]<=n)
	{
		DFS(dep+1,s+f[dep]);
	}
	if(!god)
	{
		return;
	}
	DFS(dep+1,s);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1775.txt","r",stdin);
#endif
	f[0]=1;
	for(int i=1;i<10;++i)
	{
		f[i]=f[i-1]*i;
	}
	while(cin>>n&&n>=0)
	{
		god=true;
		DFS(0,0);
		if(god||n==0)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
	}
	return 0;
}
