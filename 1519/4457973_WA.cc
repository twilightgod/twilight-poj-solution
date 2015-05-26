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

int n;

int main()
{
	//freopen("in_1519.txt","r",stdin);
	while (cin>>n&&n)
	{
		stringstream ss;
		int sum=n;
		while (1)
		{
			ss.clear();
			ss<<sum;
			string s;
			ss>>s;
			sum=0;
			for (int i=0;i<s.length();++i)
			{
				sum+=s[i]-'0';
			}
			if (sum<10)
			{
				break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
