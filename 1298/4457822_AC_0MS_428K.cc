/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : The Hardest Problem Ever
*       ID             : 1298
*       Date           : 12/5/2008
*       Time           : 22:10:17
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

string s;

int main()
{
	//freopen("in_1298.txt","r",stdin);
	while (1)
	{
		getline(cin,s);
		if (s=="ENDOFINPUT")
		{
			break;
		}
		getline(cin,s);
		for (int i=0;i<s.length();++i)
		{
			if (s[i]>='A'&&s[i]<='Z')
			{
				s[i]=char((s[i]-'A'-5+26)%26+'A');
			}
		}
		cout<<s<<endl;
		getline(cin,s);
	}
	return 0;
}
