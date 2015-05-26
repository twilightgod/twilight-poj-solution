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

bool cmp0(char a,char b)
{
	return a>b?a:b;
}

bool cmp1(char a,char b)
{
	return a<b?a:b;
}

bool Check(int num)
{
	stringstream ss;
	string s;
	ss.clear();
	ss<<num;
	ss>>s;
	if(s.length()!=4)
	{
		return false;
	}
	if(s[0]==s[1]==s[2]==s[3])
	{
		return false;
	}
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
	int a,b;
	ss.clear();
	ss<<s0;
	ss>>a;
	ss<<s1;
	ss>>b;
	printf("%d-%d=%d\n",a,b,a-b);
	n=a-b;
	return true;
}

int main()
{
	//freopen("in_1350.txt","r",stdin);
	while(scanf("%d",&n)&&n!=-1)
	{
		printf("N=%d:\n",n);
		if(!Check(n))
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
