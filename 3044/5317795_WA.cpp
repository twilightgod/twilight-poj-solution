/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : City Skyline
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3044
*       ID             : 3044
*       Date           : 6/21/2009
*       Time           : 19:38:14
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<stack>
using namespace std;

int n,x,y,ans;
stack<int> s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3044.txt","r",stdin);
#endif
	s.push(0);
	ans=0;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		while(s.top()>y)
		{
			ans++;
			s.pop();
		}
		if(s.top()!=y)
		{
			s.push(y);
		}
	}
	printf("%d\n",ans);
	return 0;
}
