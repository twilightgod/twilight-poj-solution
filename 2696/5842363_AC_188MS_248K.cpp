/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : A Mysterious Function
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2696
*       ID             : 2696
*       Date           : 9/11/2009
*       Time           : 11:43:30
*       Computer Name  : EVERLASTING-AMD
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

int MOD(int p,int q)
{
	for(int ret=0;ret<q;++ret)
	{
		if((p-ret)%q==0)
		{
			return ret;
		}
	}
}

int a,b,c,d,e,f,g,h,n,t;
int fun[1001];

int F(int i)
{
	if(fun[i]!=-1)
	{
		return fun[i];
	}
	if(i%2)
	{
		return fun[i]=MOD(d*F(i-1)+e*F(i-2)-f*F(i-3),g);
	}
	else
	{
		return fun[i]=MOD(f*F(i-1)-d*F(i-2)+e*F(i-3),h);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2696.txt","r",stdin);
#endif
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d>>e>>f>>g>>h>>n;
		memset(fun,-1,sizeof(fun));
		fun[0]=a;
		fun[1]=b;
		fun[2]=c;
		cout<<F(n)<<endl;
	}
	return 0;
}
