/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : TEX Quotes
*       ID             : 1488
*       Date           : 1/5/2009
*       Time           : 13:34:24
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

string text;
bool first;

int main()
{
	//freopen("in_1488.txt","r",stdin);
	first=true;
	while (getline(cin,text))
	{
		for (int i=0;i<text.length();++i)
		{
			if (text[i]=='"')
			{
				if (first)
				{
					cout<<"``";
				}
				else
				{
					cout<<"''";
				}
				first^=1;
			}
			else
			{
				cout<<text[i];
			}
		}
		cout<<endl;
	}
	return 0;
}
