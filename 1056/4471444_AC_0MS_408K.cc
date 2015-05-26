/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : IMMEDIATE DECODABILITY
*       ID             : 1056
*       Date           : 12/9/2008
*       Time           : 22:35:4
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

#define MAXN 100

string s[MAXN];
int n,ca;

bool Check()
{
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j)
		{
			if (i!=j&&s[i].find(s[j])==0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	//freopen("in_1056.txt","r",stdin);
	ca=0;
	while (1)
	{
		n=0;
		do 
		{
			cin>>s[n++];
			if (cin.eof())
			{
				goto ret;
			}
		} while (s[n-1]!="9");
		n--;
		printf("Set %d is %simmediately decodable\n",++ca,Check()?"":"not ");
	}
ret:return 0;
}
