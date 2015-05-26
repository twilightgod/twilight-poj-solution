/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Tree Summing
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1145
*       ID             : 1145_2
*       Date           : 5/28/2009
*       Time           : 18:56:40
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
using namespace std;

int n;
char ch;
bool god;

bool DFS(int sum)
{
	cin>>ch;
	cin>>ch;
	if(ch==')')
	{
		return true;
	}
	else
	{
		cin.putback(ch);
	}
	int v;
	cin>>v;
	bool l=DFS(sum+v);
	bool r=DFS(sum+v);
	if(l&&r)
	{
		if(sum+v==n)
		{
			god=false;
		}		
	}
	cin>>ch;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1145_2.txt","r",stdin);
#endif
	while(cin>>n)
	{
		god=true;
		DFS(0);
		cout<<(god?"no":"yes")<<endl;
	}
	return 0;
}
