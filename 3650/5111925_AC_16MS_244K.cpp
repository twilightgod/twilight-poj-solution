/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : The Seven Percent Solution
*       ID             : 3650
*       Date           : 5/6/2009
*       Time           : 22:23:54
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

string s;

string Encode(char ch)
{
	switch(ch)
	{
		case' ':return "%20";
		case'!':return "%21"; 
		case'$':return "%24"; 
		case'%':return "%25"; 
		case'(':return "%28"; 
		case')':return "%29"; 
		case'*':return "%2a";
		default:string s;s.resize(1);s[0]=ch;return s;
	}
}

int main()
{
	//freopen("in_3650.txt","r",stdin);
	while(getline(cin,s)&&s!="#")
	{
		for(int i=0;i<s.length();++i)
		{
			cout<<Encode(s[i]);
		}
		cout<<endl;
	}
	return 0;
}

