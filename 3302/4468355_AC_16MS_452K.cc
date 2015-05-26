/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Subsequence
*       ID             : 3302
*       Date           : 12/8/2008
*       Time           : 22:18:24
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int test;
string s1,s2,s3;

bool Sub(string s1,string s2)
{
	int j=0;
	for (int i=0;i<s1.length();++i)
	{
		if (s1[i]==s2[j])
		{
			j++;
		}
	}
	if(j==s2.length())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	//freopen("in_3302.txt","r",stdin);
	cin>>test;
	while (test--)
	{
		cin>>s1>>s2;
		s3=s2;
		reverse(s3.begin(),s3.end());		
		if (Sub(s1,s2)||Sub(s1,s3))
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}
