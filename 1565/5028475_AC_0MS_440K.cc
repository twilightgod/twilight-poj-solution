/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Skew Binary
*       ID             : 1565
*       Date           : 4/22/2009
*       Time           : 21:30:35
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

string s;
int sum,l;

int main()
{
	//freopen("in_1565.txt","r",stdin);
	while(1)
	{
		cin>>s;
		if(s=="0")
		{
			break;
		}
		l=s.length();
		sum=0;
		for(int i=0;i<l;++i)
		{
			sum+=(s[i]-'0')*((1<<(l-i))-1);
		}
		cout<<sum<<endl;
	}
	return 0;
}
