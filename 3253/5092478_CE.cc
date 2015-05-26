/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Fence Repair
*       ID             : 3253
*       Date           : 5/4/2009
*       Time           : 13:48:4
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<queue>
#include<functional>
using namespace std;

#define MAXN 20000

int n;
__int64 s;
priority_queue<int,vector<int>,greater<int>> q;

int main()
{
	//freopen("in_3253.txt","r",stdin);
	s=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int t;
		scanf("%d",&t);
		q.push(t);
	}
	for(int i=0;i<n-1;++i)
	{
		__int64 t;
		t=q.top();
		q.pop();
		t+=q.top();
		q.pop();
		s+=t;
		q.push(t);
	}
	printf("%I64d\n",s);
	return 0;
}
