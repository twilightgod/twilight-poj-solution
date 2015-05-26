/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Rails
*       ID             : 1363
*       Date           : 5/13/2009
*       Time           : 22:37:42
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
using namespace std;

#define MAXN 1000

int n;
int a[MAXN];

bool Check()
{
	for(int i=0;i<n;++i)
	{
		int last=a[i];
		for(int j=i+1;j<n;++j)
		{
			if(a[i]>a[j])
			{
				if(a[j]>last)
				{
					return false;
				}
				else
				{
					last=a[j];
				}
			}
		}
	}
	return true;
}

void work()
{
	while(1)
	{
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
			if(a[i]==0)
			{
				return;
			}
		}
		if(Check())
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1363.txt","r",stdin);
#endif
	while(cin>>n&&n)
	{
		work();
		cout<<endl;
	}
	return 0;
}
