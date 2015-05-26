/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Big Clock
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2840
*       ID             : 2840
*       Date           : 6/23/2009
*       Time           : 14:40:30
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

int t,n;
string ttt;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2840.txt","r",stdin);
#endif
	cin>>t;
	while(t--)
	{
		cin>>n;		
		getline(cin,ttt);
		if(ttt!=":00"&&ttt!=":0")
		{
			cout<<0<<endl;
			continue;
		}
		cout<<((n+12-1)%24+1)<<endl;
	}
	return 0;
}
