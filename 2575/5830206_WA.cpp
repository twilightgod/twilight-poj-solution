/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Jolly Jumpers
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2575
*       ID             : 2575
*       Date           : 9/8/2009
*       Time           : 19:40:51
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<set>
#include<math.h>
using namespace std;

set<int> s;
int n,pre,a;
bool god;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2575.txt","r",stdin);
#endif
	while(cin>>n)
	{
		s.clear();
		cin>>pre;
		god=false;
		for(int i=1;i<n;++i)
		{
			cin>>a;
			int t=abs(a-pre);
			if(t>=n||s.find(t)!=s.end())
			{
				god=true;
				break;
			}
			else
			{
				s.insert(t);
			}
		}
		if(god)
		{
			cout<<"Not jolly\n";
		}
		else
		{
			cout<<"Jolly\n";
		}
	}
	return 0;
}
