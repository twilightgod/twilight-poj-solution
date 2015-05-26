/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Rank List
*       ID             : 2153
*       Date           : 12/1/2008
*       Time           : 14:14:9
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define MAXN 10000

struct st
{
	int mark;
	string name;
};

bool cmp(const st &a,const st &b)
{
	if (a.mark>b.mark)
	{
		return true;
	}
	else if (a.mark==b.mark)
	{
		if (a.name=="Li Ming")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int n,m;
string s;
st a[MAXN];

int main()
{
	//freopen("in_2153.txt","r",stdin);
	while(cin>>n)
	{
		getchar();
		for (int i=0;i<n;++i)
		{
			getline(cin,s);
		}
		cin>>m;
		for(int k=0;k<m;++k)
		{
			for(int i=0;i<n;++i)
			{
				cin>>a[i].mark;
				getchar();
				getline(cin,a[i].name);
			}
			sort(a,a+n,cmp);
			for(int i=0;i<n;++i)
			{
				if (a[i].name=="Li Ming")
				{
					cout<<i+1<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
