/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Ugly Numbers
*       ID             : 1338
*       Date           : 5/13/2009
*       Time           : 21:51:26
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<queue>
#include<set>
#include<functional>
using namespace std;

#define MAXN 1501

int a[MAXN];
int n;
priority_queue<int,vector<int>,greater<int> > q;
set<int> s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1338.txt","r",stdin);
#endif
	q.push(1);
	s.insert(1);
	for(int i=1;i<=MAXN;++i)
	{
		int t=q.top();
		q.pop();
		a[i]=t;
		if(s.find(2*t)==s.end())
		{
			q.push(2*t);
			s.insert(2*t);
		}
		if(s.find(3*t)==s.end())
		{
			q.push(3*t);
			s.insert(3*t);
		}
		if(s.find(5*t)==s.end())
		{
			q.push(5*t);
			s.insert(5*t);
		}
	}
	while(cin>>n&&n)
	{
		cout<<a[n]<<endl;
	}
	return 0;
}
