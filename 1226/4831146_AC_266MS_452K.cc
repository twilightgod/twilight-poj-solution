/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Substrings
*       ID             : 1226
*       Date           : 3/22/2009
*       Time           : 13:36:10
*       Computer Name  : EVERLASTING-NCX
***********************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define MAXN 100

int test,n,best;
string s[MAXN];

bool IsFound(string& str)
{
	string str_r=str;
	reverse(str_r.begin(),str_r.end());
	for(int i=1;i<n;++i)
	{
		if(!(s[i].find(str)!=-1||s[i].find(str_r)!=-1))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	//freopen("in_1226.txt","r",stdin);
	cin>>test;
	while(test--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>s[i];
		}
		best=0;
		for(int i=0;i<s[0].length();++i)
		{
			for(int j=1;j<=s[0].length()-i;++j)
			{
				string str=s[0].substr(i,j);
				if(IsFound(str)&&str.length()>best)
				{
					best=str.length();
				}
			}
		}
		cout<<best<<endl;
	}
	return 0;
}
