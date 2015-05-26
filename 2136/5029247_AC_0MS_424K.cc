/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Vertical Histogram
*       ID             : 2136
*       Date           : 4/22/2009
*       Time           : 22:46:23
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

int t[26];
string s;
int m;

int main()
{
	//freopen("in_2136.txt","r",stdin);
	m=-1;
	memset(t,0,sizeof(t));
	while(cin>>s)
	{
		if(cin.eof())
		{
			break;
		}
		for(int i=0;i<s.length();++i)
		{
			if('A'<=s[i]&&s[i]<='Z')
			{
				if(m<++t[s[i]-'A'])
				{
					m=t[s[i]-'A'];
				}
			}
		}
	}
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<26;++j)
		{
			if(t[j]>=m-i)
			{
				cout<<"* ";
			}
			else
			{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n";
	return 0;
}
