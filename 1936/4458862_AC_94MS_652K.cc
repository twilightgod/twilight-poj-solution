/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : All in All
*       ID             : 1936
*       Date           : 12/6/2008
*       Time           : 11:49:54
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

string s1,s2;

int main()
{
	//freopen("in_1936.txt","r",stdin);
	while (cin>>s1>>s2)
	{
		int j=0;
		for (int i=0;i<s2.length();++i)
		{
			if (s1[j]==s2[i])
			{
				j++;
			}
		}
		cout<<(j==s1.length()?"Yes":"No")<<endl;
	}
	return 0;
}
