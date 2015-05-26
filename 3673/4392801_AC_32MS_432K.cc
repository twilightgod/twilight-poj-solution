/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Cow Multiplication
*       ID             : 3673
*       Date           : 11/19/2008
*       Time           : 11:26:50
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

string s1,s2;
int i,j,sum;

int main()
{
	//freopen("in_3673.txt","r",stdin);
	while(cin>>s1>>s2)
	{
		sum=0;
		for(i=0;i<s1.length();++i)
		{
			for(j=0;j<s2.length();++j)
			{
				sum+=(s1[i]-48)*(s2[j]-48);
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
