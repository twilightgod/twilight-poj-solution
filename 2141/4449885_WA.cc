/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Message Decowding
*       ID             : 2141
*       Date           : 12/3/2008
*       Time           : 17:4:28
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

string s0,s1;
char dic[128];

int main()
{
	//freopen("in_2141.txt","r",stdin);
	while (1)
	{
		getline(cin,s0);
		if (cin.eof())
		{
			break;
		}
		for (int i=0;i<26;++i)
		{
			dic['a'+i]=s0[i];
		}
		getline(cin,s1);
		for (int i=0;i<s1.length();++i)
		{
			if (s1[i]==' ')
			{
				continue;
			}
			if (s1[i]<'a')
			{
				s1[i]=char(s1[i]+32);
			}
			s1[i]=dic[s1[i]];
		}
		cout<<s1;
	}
	return 0;
}
