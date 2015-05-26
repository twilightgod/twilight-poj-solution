/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Web Navigation
*       ID             : 1028
*       Date           : 12/5/2008
*       Time           : 23:6:31
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<string> forward,backward;
string cmd,url,cur;

int main()
{
	//freopen("in_1028.txt","r",stdin);
	cur="http://www.acm.org/";
	while (cin>>cmd)
	{
		if (cmd=="QUIT")
		{
			break;
		}
		else if (cmd=="BACK")
		{
			if (backward.empty())
			{
				cout<<"Ignored\n";
			}
			else
			{
				forward.push(cur);
				cur=backward.top();
				backward.pop();
				cout<<cur<<endl;
			}
		}
		else if (cmd=="FORWARD")
		{
			if (forward.empty())
			{
				cout<<"Ignored\n";
			}
			else
			{
				backward.push(cur);
				cur=forward.top();
				forward.pop();
				cout<<cur<<endl;
			}
		}
		else
		{
			cin>>url;
			backward.push(cur);
			cur=url;
			while (!forward.empty())
			{
				forward.pop();
			}
			cout<<cur<<endl;
		}
	}
	return 0;
}
