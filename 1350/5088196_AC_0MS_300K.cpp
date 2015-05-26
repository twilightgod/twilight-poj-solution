/**********************************************************************
*       Online Judge   : POJ
*       Problem Title  : Cabric Number Problem
*       ID             : 1350
*       Date           : 5/3/2009
*       Time           : 12:19:11
*       Computer Name  : EVERLASTING-PC
***********************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

int n,t;
string str;

bool cmp0(char a,char b)
{
	return a>b?1:0;
}

bool cmp1(char a,char b)
{
	return a<b?1:0;
}

bool Check()
{
	if(str.length()!=4)
	{
		return false;
	}
	if((str[0]==str[1])&&(str[2]==str[3])&&(str[2]==str[0]))
	{
		return false;
	}
	stringstream ss;
	ss.clear();
	ss<<str;
	ss>>n;
	return true;
}

bool Work()
{
	stringstream ss;
	string s0,s1;
	ss.clear();
	ss<<n;
	ss>>s0;
	s1=s0;
	sort(s0.begin(),s0.end(),cmp0);
	sort(s1.begin(),s1.end(),cmp1);
	//sort(s0.begin(),s0.end(),greater<char>());
	//sort(s1.begin(),s1.end());
	int a,b;
	ss.clear();
	ss<<s0;
	ss>>a;
	ss.clear();
	ss<<s1;
	ss>>b;
	printf("%d-%d=%d\n",a,b,a-b);
	n=a-b;
	return true;
}

int main()
{
	//freopen("in_1350.txt","r",stdin);
	while(cin>>str)
	{
		if(str=="-1")
		{
			break;
		}
		printf("N=%s:\n",str.c_str());
		if(!Check())
		{
			printf("No!!\n");
			continue;
		}
		t=0;
		while(!(n==6174||n==0))
		{
			Work();
			t++;
		}
		printf("Ok!! %d times\n",t);
	}
	return 0;
}
