/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Digital Roots
*       ID             : 1519
*       Date           : 12/5/2008
*       Time           : 22:53:36
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string s;
int sum;

int main()
{
	//freopen("in_1519.txt","r",stdin);
	while (cin>>s)
	{
		if (s=="0")
		{
			break;
		}
		sum=0;
		for (int i=0;i<s.length();++i)
		{
			sum+=s[i]-'0';
		}
		cout<<(sum%9?sum%9:9)<<endl;
	}
	return 0;
}
