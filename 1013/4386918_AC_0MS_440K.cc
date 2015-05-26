/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Counterfeit Dollar
*       ID             : 1013
*       Date           : 11/17/2008
*       Time           : 21:19:25
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
using namespace std;

int n;
string s[3][3];

bool Fit(int diff,char ch)
{
	for(int i=0;i<3;++i)
	{
		if((s[i][2]!="even")&&(s[i][0].find(ch)==-1)&&(s[i][1].find(ch)==-1))
		{
			return false;
		}
		if((s[i][2]=="even")&&((s[i][0].find(ch)!=-1)||(s[i][1].find(ch)!=-1)))
		{
			return false;
		}
		if((diff==0)&&(s[i][0].find(ch)!=-1)&&(s[i][2]=="down"))
		{
			return false;
		}
		if((diff==0)&&(s[i][1].find(ch)!=-1)&&(s[i][2]=="up"))
		{
			return false;
		}
		if((diff==1)&&(s[i][0].find(ch)!=-1)&&(s[i][2]=="up"))
		{
			return false;
		}
		if((diff==1)&&(s[i][1].find(ch)!=-1)&&(s[i][2]=="down"))
		{
			return false;
		}
	}
	return true;
}

void Solve()
{
	for(int diff=0;diff<=1;++diff)
	{
		for(char ch='A';ch<='L';++ch)
		{
			if(Fit(diff,ch))
			{
				cout<<ch<<" is the counterfeit coin and it is "<<(diff==0?"heavy":"light")<<".\n";
				return;
			}
		}
	}	
}

int main()
{
	//freopen("in_1013.txt","r",stdin);
	cin>>n;
	while(n--)
	{
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				cin>>s[i][j];
		Solve();
	}
	return 0;
}
