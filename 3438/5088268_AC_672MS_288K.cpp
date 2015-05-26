/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Look and Say
*       ID             : 3438
*       Date           : 5/3/2009
*       Time           : 13:4:12
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

int t,p,q;
string s;

int main()
{
	//freopen("in_3438.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		cin>>s;
		s+='#';
		p=0;
		while(p<s.length()-1)
		{
			q=p+1;
			while(s[q]==s[p])
			{
				q++;
			}
			cout<<q-p<<s[p];
			p=q;
		}
		cout<<endl;
	}
	return 0;
}
