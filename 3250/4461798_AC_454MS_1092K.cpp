/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Bad Hair Day
*       ID             : 3250
*       Date           : 12/6/2008
*       Time           : 22:54:42
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<stack>
using namespace std;

stack<int> s;
int n,h;
long long sum;

int main()
{
	//freopen("in_3250.txt","r",stdin);
	while (scanf("%d",&n)!=-1)
	{
		while (!s.empty())
		{
			s.pop();
		}
		sum=0;
		for (int i=0;i<n;++i)
		{
			scanf("%d",&h);
			while (!s.empty()&&s.top()<=h)
			{
				s.pop();
			}
			s.push(h);
			sum+=s.size()-1;
		}
		printf("%I64d\n",sum);
	}
	return 0;
}
