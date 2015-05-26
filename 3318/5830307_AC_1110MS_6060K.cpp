/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Matrix Multiplication
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3318
*       ID             : 3318
*       Date           : 9/8/2009
*       Time           : 19:53:36
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
//ABX=CX --?-> AB=C
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

#define MAXN 501

long long a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];
int n;

bool Check()
{
	//CX=D
	long long d[MAXN]={0};
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			d[i]+=(j+1)*c[i][j];
		}
	}
	//BX=E
	long long e[MAXN]={0};
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			e[i]+=(j+1)*b[i][j];
		}
	}
	//AE=F
	long long f[MAXN]={0};
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			f[i]+=e[j]*a[i][j];
		}
	}
	//Check
	for(int i=0;i<n;++i)
	{
		if(f[i]!=d[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3318.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			scanf("%I64d",&a[i][j]);
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			scanf("%I64d",&b[i][j]);
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			scanf("%I64d",&c[i][j]);
		}
	}
	if(Check())
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
