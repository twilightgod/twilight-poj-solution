/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Quicksum
*       ID             : 3094
*       Date           : 4/26/2009
*       Time           : 13:20:39
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

int qsum,p;
string s;

int main()
{
	//freopen("in_3094.txt","r",stdin);
	while(1)
	{
		getline(cin,s);
		if(s=="#")
		{
			break;
		}
		qsum=0;
		p=0;
		for(int i=0;i<s.length();++i)
		{
			if(s[i]!=' ')
			{
				qsum+=(s[i]-'A'+1)*(++p);
			}
		}
		cout<<qsum<<endl;
	}
	return 0;
}
